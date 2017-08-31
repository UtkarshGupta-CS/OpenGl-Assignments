## OpenGl-Assignments


### Usage in MAC

`gcc -framework OpenGL -framework GLUT <inputfile> -o <outputfile> -Wno-deprecated`

### Usage in other LINUX Distros

`gcc <inputfile> -o <outputfile> -lGL -lGLU -lglut`

### Key Points

- **Callback Function** - In C, a callback function is a function that is called through a function pointer. If you pass the pointer (address) of a function as an argument to another, when that pointer is used to call the function it points to it is said that a call back is made.