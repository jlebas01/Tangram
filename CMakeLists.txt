CMAKE_MINIMUM_REQUIRED(VERSION 3.7)


PROJECT(Tangram)


SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
SET(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)


FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(MLV REQUIRED IMPORTED_TARGET MLV)


INCLUDE_DIRECTORIES(
        ${INCLUDE_DIR}
)

FILE(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}*.cpp)
FILE(GLOB_RECURSE HEADER_FILES ${INCLUDE_DIR}*.hpp)


SET(TARGET_NAME tangram)
ADD_EXECUTABLE(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES(${TARGET_NAME} PUBLIC PkgConfig::MLV stdc++fs)

function(define_file_basename_for_sources tangram)
    get_target_property(SOURCE_FILES "${TARGET_NAME}" SOURCES)
    foreach(sourcefile ${SOURCE_FILES})
        # Add the FILE_BASENAME=filename compile definition to the list.
        get_filename_component(basename "${SOURCE_FILES}" NAME)
        # Set the updated compile definitions on the source file.
        set_property(
                SOURCE "${SOURCE_FILES}" APPEND
                PROPERTY COMPILE_DEFINITIONS "FILE_BASENAME=\"${basename}\"")
    endforeach()
endfunction()
define_file_basename_for_sources(tangram)



TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -O2
        -g
        -std=c++17
)

# Adding as much warning as possible on GNU gcc/g++ and Clang
IF (CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Weverything
            -Werror
            -Wfatal-errors
            -Wno-deprecated
            -Wno-global-constructors

    )
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0.0")
    ELSE ()
    ENDIF ()
ELSEIF (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Wall
            -Wextra
    )
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "8.0.0")
    ELSE ()
    ENDIF ()
ELSE ()
ENDIF ()


# Disable some warnings
TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -Wno-unused-parameter
        -Wno-shadow
)
IF (CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Wno-padded
            -Wno-c++98-compat
            -Wno-weak-vtables
            -Wno-exit-time-destructors
    )
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0.0")
    ELSE ()
    ENDIF ()
ELSEIF (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL "8.0.0")
    ELSE ()
    ENDIF ()
ELSE ()
ENDIF ()
