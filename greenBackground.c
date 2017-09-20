#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT); // to clear all color
  glColor3f(1.0, 0.0, 0.0);     // background color

  glFlush();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);                //to initialize Graphic library utility
  glutInitWindowPosition(300, 300);     // set window position on the screen
  glutInitWindowSize(500, 500);         //set display window width and height
  glutCreateWindow("Green Background"); // create window with title
  glClearColor(0.0, 1.0, 0.0, 0.0);     // set the background color
  glutDisplayFunc(display);             // callback function
  glutMainLoop();                       //INFITE TIME DISPALY OR INFINITE LOOP
  return 0;
}
