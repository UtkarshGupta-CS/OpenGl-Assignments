#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float X1, Y1, X2, Y2;

void dda()
{
  double dx = (X2 - X1);
  double dy = (Y2 - Y1);
  double iteration;
  float xInc, yInc, x = X1, y = Y1;

  iteration = (fabs(dx) > fabs(dy)) ? (fabs(dx)) : (fabs(dy));
  xInc = dx / (float)iteration;
  yInc = dy / (float)iteration;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);

  glVertex2d(x, y);
  int k;

  for (k = 0; k < iteration; k++)
  {
    x += xInc;
    y += yInc;

    glVertex2d(round(x), round(y));
  }
  glEnd();

  glFlush();
}

int main(int argc, char *argv[])
{
  printf("Enter two end points\n");
  printf("\nEnter Point1:\n");
  scanf("%f%f", &X1, &Y1);
  printf("\nEnter Point2:\n");
  scanf("%f%f", &X2, &Y2);

  glutInit(&argc, argv); //to initialize Graphic library utility

  glutInitWindowPosition(300, 300);                // set window position on the screen
  glutInitWindowSize(500, 500);                    //set display window width and height
  glutCreateWindow("Digital Difference Analyzer"); // create window with title

  glClearColor(1.0, 1.0, 1.0, 0);
  glColor3f(1.0, 0.0, 0.0);
  gluOrtho2D(0, 640, 0, 480); //define a 2D orthographic projection matrix

  glutDisplayFunc(dda); // callback function

  glutMainLoop(); //INFITE TIME DISPALY OR INFINITE LOOP
  return 0;
}