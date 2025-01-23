#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int X1, X2, Y1, Y2;

void draw_pixel(int x, int y)
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bres()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int dx = abs(X2 - X1);
    int dy = abs(Y2 - Y1);
    int p = 2 * dy - dx;
    int twody = 2 * dy;
    int twodydx = 2 * (dy - dx);
    int x, y;
    if (X1 > X2)
    {
        x = X2;
        y = Y2;
        X2 = X1;
    }
    else
    {
        x = X1;
        y = Y1;
        Y2 = X2;
    }
    draw_pixel(x, y);
    while (x < X2)
    {
        x++;
        if (p < 0)
            p += twody;
        else
        {
            y++;
            p += twodydx;
        }
        draw_pixel(x, y);
    }
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glPointSize(1.0);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Enter the value of X1: ");
    scanf_s("%d", &X1);
    printf("Enter the value of Y1: ");
    scanf_s("%d", &Y1);
    printf("Enter the value of X2: ");
    scanf_s("%d", &X2);
    printf("Enter the value of Y2: ");
    scanf_s("%d", &Y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    init();
    glutDisplayFunc(bres);
    glutMainLoop();
    return 0;
}