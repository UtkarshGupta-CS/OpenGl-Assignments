#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float X1, Y1, X2, Y2;

void bresenhamAlgo()
{
  double dx = fabs(X2 - X1);
  double dy = fabs(Y2 - Y1);
  double p = 2 * dy - dx;
  double twoDy = 2 * dy, twoDyDx = 2 * dy - dx; // here twoDy is ∆E and twoDyDx is ∆NE
  double x, y, xEnd;

  if (X1 > X2)
  {
    x = X2;
    y = Y2;
    xEnd = X1;
  }
  else
  {
    x = X1;
    y = Y1;
    xEnd = X2;
  }

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);

  glVertex2d(x, y);
  while (x < xEnd)
  {
    x++;
    if (p < 0)
      p += twoDy;
    else
    {
      y++;
      p += twoDyDx;
    }
    glVertex2d(round(x), round(y));
  }
  glEnd();

  glFlush(); // force execution of GL commands in finite time
}

int main(int argc, char *argv[])
{
  printf("Enter two end points\n");
  printf("\nEnter Point1:\n");
  scanf("%f%f", &X1, &Y1);
  printf("\nEnter Point2:\n");
  scanf("%f%f", &X2, &Y2);

  glutInit(&argc, argv); //to initialize Graphic library utility

  glutInitWindowPosition(300, 300);             // set window position on the screen
  glutInitWindowSize(500, 500);                 //set display window width and height
  glutCreateWindow("Bresenham Line Algorithm"); // create window with title

  glClearColor(1.0, 1.0, 1.0, 0); // specify clear values for the color buffers
  glColor3f(1.0, 0.0, 0.0);
  gluOrtho2D(0, 640, 0, 480); //define a 2D orthographic projection matrix

  glutDisplayFunc(bresenhamAlgo); // callback function

  glutMainLoop(); // enters the GLUT event processing loop
  return 0;
}