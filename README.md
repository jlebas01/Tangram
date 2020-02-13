# Tangram
A student project about the tangram's game make in C++

## How to run 
When you're in the root directory of this project <br/><br/>
### CMake
If you didn't have CMake the project, you could do that it below :
`cmake ./cmake-build-debug`
### Make
If you have already CMake the project, you could do that it below :
`cd cmake-build-debug` <br/>
`make` <br/>
### Run
If you have already CMake and Make the project, you could do it that it below :
`./tangram`

## Documentation
Here there is HTML files, LaTeX files and PDF.
### HTML
Open it with your browser
`cd doc/html`
`index.html`
### LaTeX
`cd doc/latex`
### PDF
Open it with a PDF reader
`cd doc/latex`<br/>
`refman.pdf`

## Regenerate Documentation
You can generate this document as you wish. If you're updating the code and the doc, you should do :
<br/><br/>
In the root directory of this project :
<br/><br/>
`doxygen config-file`<br/>
`cd doc/latex`<br/>
`make`<br/>
