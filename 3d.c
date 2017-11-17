#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

float original_cube[8][4] = {{-20, 20, 20, 1}, {20, 20, 20, 1}, {20, 20, -20, 1}, {-20, 20, -20, 1}, {-50, -50, 50, 1}, {50, -50, 50, 1}, {50, -50, -50, 1}, {-50, -50, -50, 1}};
float tx = 0, ty = 0, tz = 0;
float Sx = 0, Sy = 0, Sz;
float qx, qy, qz;

void Draw(float Cube[8][4])
{
  glClear(GL_COLOR_BUFFER_BIT); //clearing Screen

  glBegin(GL_QUADS);

  glColor3f(1.0, 0.627, 0.478);
  glVertex3f(Cube[3][0], Cube[3][1], Cube[3][2]); //back surface
  glVertex3f(Cube[2][0], Cube[2][1], Cube[2][2]);
  glVertex3f(Cube[6][0], Cube[6][1], Cube[6][2]);
  glVertex3f(Cube[7][0], Cube[7][1], Cube[7][2]);

  glColor3f(0.576, 0.439, 0.859);
  glVertex3f(Cube[4][0], Cube[4][1], Cube[4][2]); //bottom surface
  glVertex3f(Cube[5][0], Cube[5][1], Cube[5][2]);
  glVertex3f(Cube[6][0], Cube[6][1], Cube[6][2]);
  glVertex3f(Cube[7][0], Cube[7][1], Cube[7][2]);

  glColor3f(0.0, 0.980, 0.604);
  glVertex3f(Cube[0][0], Cube[0][1], Cube[0][2]); //left surface
  glVertex3f(Cube[4][0], Cube[4][1], Cube[4][2]);
  glVertex3f(Cube[7][0], Cube[7][1], Cube[7][2]);
  glVertex3f(Cube[3][0], Cube[3][1], Cube[3][2]);

  glColor3f(1.0, 0.627, 0.478);
  glVertex3f(Cube[0][0], Cube[0][1], Cube[0][2]); //front surface
  glVertex3f(Cube[1][0], Cube[1][1], Cube[1][2]);
  glVertex3f(Cube[5][0], Cube[5][1], Cube[5][2]);
  glVertex3f(Cube[4][0], Cube[4][1], Cube[4][2]);

  glColor3f(0.576, 0.439, 0.859);
  glVertex3f(Cube[0][0], Cube[0][1], Cube[0][2]); //top surface
  glVertex3f(Cube[1][0], Cube[1][1], Cube[1][2]);
  glVertex3f(Cube[2][0], Cube[2][1], Cube[2][2]);
  glVertex3f(Cube[3][0], Cube[3][1], Cube[3][2]);

  glColor3f(0.0, 0.980, 0.604);
  glVertex3f(Cube[1][0], Cube[1][1], Cube[1][2]); //right surface
  glVertex3f(Cube[5][0], Cube[5][1], Cube[5][2]);
  glVertex3f(Cube[6][0], Cube[6][1], Cube[6][2]);
  glVertex3f(Cube[2][0], Cube[2][1], Cube[2][2]);

  glEnd();
  glFlush();
}

void display()
{
  const char *str2 = "Utkarsh Gupta";
  int j = strlen(str2);
  glColor3f(0.9, 0.5, 1.0);
  glRasterPos2f(-280, 280);
  for (int i = 0; i < j; i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
  }
  Draw(original_cube);
  glFlush();
}

void mul(float a[][4], float b[][4], float c[][4])
{
  int i, j, k;
  float sum;
  for (i = 0; i < 1; i++)
  {
    for (j = 0; j < 4; j++)
    {
      sum = 0;
      for (k = 0; k < 4; k++)
      {
        sum += a[i][k] * b[k][j];
      }
      c[i][j] = sum;
    }
  }
}

void modify(float mul_matrix[][4])
{
  float resultant_matrix[][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  for (int i = 0; i < 8; i++)
    mul(original_cube + i, mul_matrix, resultant_matrix + i);
  Draw(resultant_matrix);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      original_cube[i][j] = resultant_matrix[i][j];
    }
  }
}

void showOption()
{
  printf("Choose the transformation:");
  printf("\t\nTranslation: '<-' with a, '^' with w, 'down' with s, '->' with d\n");
  printf("Orignal: o");
  printf("\tScaling: q and p");
  printf("\tRotation: x, y, z");
}

void myKey(unsigned char key, int x, int y)
{
  if (key == 97) //move left with 'a'
  {
    tx = tx - 20;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {tx, ty, tz, 1}};
    modify(mulmatrix);
    tx = 0;
  }
  else if (key == 119) //move up with 'w'
  {
    ty = ty + 20;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {tx, ty, tz, 1}};
    modify(mulmatrix);
    ty = 0;
  }
  else if (key == 100) //move right with 'd'
  {
    tx = tx + 20;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {tx, ty, tz, 1}};
    modify(mulmatrix);
    tx = 0;
  }
  else if (key == 115) //move down with 's'
  {
    ty = ty - 20;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {tx, ty, tz, 1}};
    modify(mulmatrix);
    ty = 0;
  }
  else if (key == 'p') // scale out with 'p'
  {
    Sx = 2;
    Sy = 2;
    Sz = 2;
    float mulmatrix[][4] = {{Sx, 0, 0, 0}, {0, Sy, 0, 0}, {0, 0, Sz, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    Sx = 0;
    Sy = 0;
    Sz = 0;
  }
  else if (key == 'q') // scale in with 'q'
  {
    Sx = 0.5;
    Sy = 0.5;
    Sz = 0.5;
    float mulmatrix[][4] = {{Sx, 0, 0, 0}, {0, Sy, 0, 0}, {0, 0, Sz, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    Sx = 0;
    Sy = 0;
    Sz = 0;
  }
  else if (key == 'x') // rotate about x axis
  {
    qx = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, cos(qx), -sin(qx), 0}, {0, sin(qx), cos(qx), 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qx = 0;
  }
  else if (key == 'y') // rotate about y axis
  {
    qy = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{cos(qy), 0, sin(qy), 0}, {0, 1, 0, 0}, {-sin(qy), 0, cos(qy), 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qy = 0;
  }
  else if (key == 'z') // rotate about z axis
  {
    qz = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{cos(qz), -sin(qz), 0, 0}, {sin(qz), cos(qz), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qz = 0;
  }
  else if (key == 'j') // reflect about xy axis
  {
    qx = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, -1, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qx = 0;
  }
  else if (key == 'k') // reflect about yz axis
  {
    qy = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{-1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qy = 0;
  }
  else if (key == 'l') // reflect about xz axis
  {
    qz = 30 * 3.14 / 180;
    float mulmatrix[][4] = {{1, 0, 0, 0}, {0, -1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    modify(mulmatrix);
    qz = 0;
  }
  else if (key == 'o')
  {
    float reset_cube[8][4] = {{-20, 20, 20, 1}, {20, 20, 20, 1}, {20, 20, -20, 1}, {-20, 20, -20, 1}, {-50, -50, 50, 1}, {50, -50, 50, 1}, {50, -50, -50, 1}, {-50, -50, -50, 1}};
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        original_cube[i][j] = reset_cube[i][j];
      }
    }
    Draw(original_cube);
  }
}

int main(int argc, char **argv)
{
  showOption();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3D");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-300, 300, -300, 300, 300, -300);
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}