#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>

float X1, Y1, X2, Y2, yIntercept;
int steps;

void dsAlgo()
{
  float x = X1;
  float y = Y1;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);

  glVertex2d(x, y);
  steps = 6;
  int slope = (Y2 - Y1) / (X2 - X1);

  int k;
  yIntercept = y - slope * x;

  while (x != X2 && y != Y2)
  {
    ++x;
    y = slope * x + yIntercept;

    glVertex2d(x, lround(y));
  }
  glEnd();

  glFlush();
}

int main(int argc, char *argv[])
{
  printf("Enter two end points\n");
  printf("\nEnter Point1:\n");
  scanf("%f%f", &X1, &Y1);
  printf("\nEnter Point1:\n");
  scanf("%f%f", &X2, &Y2);

  glutInit(&argc, argv); //to initialize Graphic library utility

  glutInitWindowPosition(300, 300);         // set window position on the screen
  glutInitWindowSize(500, 500);             //set display window width and height
  glutCreateWindow("Direct Solution Algo"); // create window with title

  glClearColor(1.0, 1.0, 1.0, 0);
  glColor3f(1.0, 0.0, 0.0);
  gluOrtho2D(0, 640, 0, 480); //define a 2D orthographic projection matrix

  glutDisplayFunc(dsAlgo); // callback function

  glutMainLoop(); //INFITE TIME DISPALY OR INFINITE LOOP
  return 0;
}