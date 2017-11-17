
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
void draw()
{
  glClearColor(1, 1, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 50.0, -10.0, 40.0);
  glViewport(0, 0, 250, 250);
  glColor3f(0, 0, 1);
  glRectf(0.0, 0.0, 10.0, 30.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 50.0, -10.0, 40.0);
  glViewport(250, 250, 250, 250);
  glColor3f(1, 0, 0);
  glRectf(0.0, 0.0, 10.0, 30.0);
  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == 'q')
    exit(0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitWindowSize(500, 500);
  glutCreateWindow("single viewport spans the left-bottom interface window quarter");
  glutDisplayFunc(draw);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
