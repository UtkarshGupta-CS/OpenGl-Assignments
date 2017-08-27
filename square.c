#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT); // to clear all color
  glColor3f(1.0,0.0,0.0); // background color

  glBegin(GL_POLYGON);  
  glVertex2f(-0.5,-0.5);
  glVertex2f(-0.5,0.5);
  glVertex2f(0.5,0.5);
  glVertex2f(0.5,-0.5);
  glEnd();
  glFlush();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv); //to initialize Graphic library utility
  glutInitWindowPosition(300, 300); // set window position on the screen
  glutInitWindowSize(500, 500); //set display window width and height
  glutCreateWindow("Hello World"); // create window with title
  glClearColor(0.0,1.0,0.0,0.0); // set the background color
  glutDisplayFunc(display); // callback function
  glutMainLoop(); //INFITE TIME DISPALY OR INFINITE LOOP
  return 0;
}
