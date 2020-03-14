# Tangram
A student project about the tangram's game make in C++

## How to run 
When you're in the root directory of this project <br/><br/>
### CMake
If you didn't have CMake the project, you could do that it below :
<br/>
`cmake ./cmake-build-debug`
### Make
If you have already CMake the project, you could do that it below :
<br/>
`cd cmake-build-debug` <br/>
`make` <br/>
### Run
If you have already CMake and Make the project, you could do it that it below :
<br/>
`./tangram`

## How to play

When you have launch the game with `./tangram` you can play now.

#### Launch

You can create a new puzzle board if you click on `Launch` and use these commands to play :
<br/>
`click left` on a shape to move it.
<br/>
`click right` on a shape to rotate it.
<br/>
`press 'Esc'` to exit this mode.
<br/>
`press 's'` to save the current board as puzzle.
<br/>
`press 'd'` on a shape to rotate the shape as 45° anti clock.
<br/>
`press 'f` on a shape to rotate the shape as 45° clock.
<br/>
`press 'r'` to reverse the shape as symmetry.
<br/>
Note that last command rotate every shape as 180° except parallelogram is overturned like a mirror
<br/>
<br/>
#### Load
If you click on `Load` you can load a puzzle file and try to resolve it. To play this mode you can use these commands below :
<br/>
`click left` on a shape to move it.
<br/>
`click right` on a shape to rotate it.
<br/>
`press 'Esc'` to exit this mode.
<br/>
`press 'd'` on a shape to rotate the shape as 45° anti clock.
<br/>
`press 'f` on a shape to rotate the shape as 45° clock.
<br/>
`press 'r'` to reverse the shape as symmetry.
<br/>
Note that last command rotate every shape as 180° except parallelogram is overturned like a mirror
<br/>
#### End Game

The game will stop when you put the last shape at a right place. You will back to the main menu.



## Documentation
Here there is HTML files, LaTeX files and PDF.
### HTML
Open it with your browser
<br/>
`cd doc/html`
<br/>
`index.html`
### LaTeX
`cd doc/latex`
### PDF
Open it with a PDF reader
<br/>
`cd doc/latex`<br/>
`refman.pdf`

## Regenerate Documentation
You can generate this document as you wish. If you're updating the code and the doc, you should do :
<br/><br/>
In the root directory of this project :
<br/><br/>
`doxygen config-file`<br/>
## Regenerate LaTeX Documentation
`cd doc/latex`<br/>
`make`<br/>
