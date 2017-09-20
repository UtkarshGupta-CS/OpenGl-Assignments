#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float X1, X2, Y1, Y2;
float Xmin, Xmax, Ymin, Ymax;

int code(float x, float y)
{
  int c = 0;
  if (y > Ymax)
    c = 8;
  if (y < Ymin)
    c = 4;
  if (x > Xmax)
    c = c | 2;
  if (x < Xmin)
    c = c | 1;
  return c;
}

void csa()
{
  int c1 = code(X1, Y1);
  int c2 = code(X2, Y2);
  float m = (Y2 - Y1) / (X2 - X1);
  while ((c1 | c2) > 0)
  {
    if ((c1 & c2) > 0)
    {
      exit(0);
    }

    float xi = X1;
    float yi = Y1;
    int c = c1;
    if (c == 0)
    {
      c = c2;
      xi = X2;
      yi = Y2;
    }
    float x, y;
    if ((c & 8) > 0)
    {
      y = Ymax;
      x = xi + 1.0 / m * (Ymax - yi);
    }
    else if ((c & 4) > 0)
    {
      y = Ymin;
      x = xi + 1.0 / m * (Ymin - yi);
    }
    else if ((c & 2) > 0)
    {
      x = Xmax;
      y = yi + m * (Xmax - xi);
    }
    else if ((c & 1) > 0)
    {
      x = Xmin;
      y = yi + m * (Xmin - xi);
    }

    if (c == c1)
    {
      xd1 = x;
      yd1 = y;
      c1 = code(xd1, yd1);
    }

    if (c == c2)
    {
      xd2 = x;
      yd2 = y;
      c2 = code(xd2, yd2);
    }
  }

  display();
}

void mouse(int button, int state, int x, int y)
{
  glClear(GL_COLOR_BUFFER_BIT);
  //if(button==GLUT_LEFT_BUTTON){
  glClearColor(1, 0, 0, 0);
  csa();
  glFlush();
  //}
}

int main(int argc, char *argv[])
{
  printf("Enter two end points\n");
  printf("\nEnter Point1:\n");
  scanf("%f%f", &X1, &Y1);
  printf("\nEnter Point2:\n");
  scanf("%f%f", &X2, &Y2);

  glutInit(&argc, argv); //to initialize Graphic library utility

  glutInitWindowPosition(300, 300);               // set window position on the screen
  glutInitWindowSize(500, 500);                   //set display window width and height
  glutCreateWindow("Cohen Sutherland Algorithm"); // create window with title

  glClearColor(0.0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glViewport(0, 0, 250, 250);
  gluOrtho2D(0, 0, 300, 300);

  glutMouseFunc(mouse);
  glutMainLoop(); //INFITE TIME DISPALY OR INFINITE LOOP
  return 0;
}