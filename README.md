# Tangram
A student project about the Tangram game made in C++

## Getting started 
When you're in the root directory of this project, follow the next steps :
### CMake
First, If you have not did it already, you can build the game by executing the
following command line :
>$ cmake ./cmake-build-debug
### Make
Second, If you have not did it already, you can make the executable’s game by
executing the following command line :
>$ cd cmake-build-debug
>
>$ make
### Run
Before using the run command line, you have to use the two aforementionned
command in the right order. If you have already did it, you can run the game by
executing the following command line :
>$ ./tangram

## How to play

Run the game with the following command line in the cmake-debug-build directory :
>$ ./tangram

You can play now.

#### Launch Button

You can create a new puzzle board if you click on the `Launch` button and use the
following commands :
>`mouse click left` on a shape and drag to move it.
>
>`mouse click right` on a shape and drag to rotate it.
>
>`press 'Esc'` to exit this mode.
>
> press 's' to save the current board as puzzle.
>
>`press 'd'` on a shape mouseovered to rotate it 45° anti clockwise.
>
>`press 'f` on a shape mouseovered to rotate it 45° clockwise.
>
>`press 'r'` to symmetrically reverse the shape.
>
>
>Note that last command rotates every shape to 180° except parallelogram which is
 overturned (in a mirror fashion)

#### Load Button
If you click on the `Load` button, you can load a puzzle file and try to resolve it. You can use the
following commands :
>`mouse click left` on a shape and drag to move it.
>
>`mouse click right` on a shape and drag to rotate it.
>
>`press 'Esc'` to exit this mode.
>
>`press 'd'` on a shape mouseovered to rotate it 45° anti clockwise.
>
>`press 'f` on a shape mouseovered to rotate it 45° clockwise.
>
>`press 'r'` to symmetrically reverse the shape.
>
>
>Note that last command rotates every shape to 180° except parallelogram which is
 overturned (in a mirror fashion)
#### End Game

The game will stop when you put the last shape at the right place. You will return to
the main menu.
When you solve a puzzle, the last shape dropped will be displayed in white and the
game will freeze a for few seconds before you return to the main menu.

## Documentation
Here you can find HTML files, LaTeX files and PDF.
### HTML
Open with your browser
<br/>
>$ cd doc/html
>
>index.html
### LaTeX
>$ cd doc/latex
### PDF
Open with a PDF reader
<br/>
>$ cd doc/latex
>
> refman.pdf

## Regenerate Documentation
You can generate this document as needed.
If you're updating the code and the documentation, you should do execute in the
root directory of this project :
>$ doxygen config-file

If you want customize the documentation generated, you could also configurate the
following file :
>$ gedit config-file

## Regenerate LaTeX Documentation
To generate the PDF documentation, execute the following commands :
>$ cd doc/latex
>
>$ make
