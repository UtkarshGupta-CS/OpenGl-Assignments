#include <iostream>
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320, 320, -240, 240);
}

void drawDot(GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{
    glColor3f(r, g, b);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void symmetricPixels(int x, int y, int xc, int yc, float r, float g, float b)
{
    drawDot(xc + x, yc + y, r, g, b);
    drawDot(xc - x, yc + y, r, g, b);
    drawDot(xc + x, yc - y, r, g, b);
    drawDot(xc - x, yc - y, r, g, b);
}

void Ellipse(int a, int b, int xc, int yc, float r, float g, float bl)
{
    int aSq, bSq, twoASq, twoBSq, d, dx, dy, x, y;
    aSq = a * a;
    bSq = b * b;
    twoASq = 2 * aSq;
    twoBSq = 2 * bSq;
    d = bSq - b * aSq + aSq / 4;
    dx = 0;
    dy = twoASq * b;
    x = 0;
    y = b;
    symmetricPixels(x, y, xc, yc, r, g, bl);
    while (dx < dy)
    {
        x++;
        dx += twoBSq;
        if (d >= 0)
        {
            y--;
            dy -= twoASq;
        }
        if (d < 0)
            d += bSq + dx;
        else
            d += bSq + dx - dy;
        symmetricPixels(x, y, xc, yc, r, g, bl);
    }
    d = (int)(bSq * (x + 0.5) * (x + 0.5) + aSq * (y - 1) * (y - 1) -
              aSq * bSq);
    while (y > 0)
    {
        y--;
        dy -= twoASq;
        if (d <= 0)
        {
            x++;
            dx += twoBSq;
        }
        if (d > 0)
            d += aSq - dy;
        else
            d += aSq - dy + dx;
        symmetricPixels(x, y, xc, yc, r, g, bl);
    }
    glFlush();
}

void ellipsy()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Ellipse(100, 50, 0, 0, 0, 1, 1);
    int flager = 0;
    float blue = 0.0;
    for (int x = 0; x <= 221;)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        Ellipse(100, 70, x, 0, 0, 0, blue);
        if (flager == 0)
            x++;
        else
            x--;
        if (x >= 220)
        {
            flager = 1;
            for (int y = 100; y > 0; y--)
            {
                glClear(GL_COLOR_BUFFER_BIT);
                Ellipse(y, 70, x + (100 - y), 0, 0, 0, blue);
            }
            x = 320;
            for (int y = 0; y < 100; y++)
            {
                glClear(GL_COLOR_BUFFER_BIT);
                Ellipse(y, 70, x - y, 0, 0, 0, blue);
            }
            x = 220;
        }
        if (x <= -220)
        {
            flager = 0;
            for (int y = 100; y > 0; y--)
            {
                glClear(GL_COLOR_BUFFER_BIT);
                Ellipse(y, 70, x - (100 - y), 0, 0, 0, blue);
            }
            x = -320;
            for (int y = 0; y < 100; y++)
            {
                glClear(GL_COLOR_BUFFER_BIT);
                Ellipse(y, 70, x + y, 0, 0, 0, blue);
            }
            x = -220;
        }
        blue += 0.001;
        if (blue >= 1)
            blue = 0.000;
    }
}

void launcher(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Many Amaze Very GL WOW");

    glutDisplayFunc(ellipsy);

    init();
    glutMainLoop();
}

int main(int argc, char **argv)
{
    int choice;
    cout << " Mid Point Ellipse";
    launcher(argc, argv);
    return 0;
}
