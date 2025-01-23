#include <GL/glut.h>
#include <stdio.h>

float v[3][2] = {{0, 1}, {-0.5, -0.5}, {0.5, -0.5}};
int m;

void triangle(float *a, float *b, float *c)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
    glEnd();
}

void dividetriangle(float *a, float *b, float *c, int m)
{
    float v1[2], v2[2], v3[2];
    int j;
    if (m > 0)
    {
        for (j = 0; j < 2; j++)
        {
            v1[j] = (a[j] + b[j]) / 2;
            v2[j] = (a[j] + c[j]) / 2;
            v3[j] = (b[j] + c[j]) / 2;
        }
        dividetriangle(a, v1, v2, m - 1);
        dividetriangle(v1, b, v3, m - 1);
        dividetriangle(v2, v3, c, m - 1);
    }
    else
    {
        triangle(a, b, c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    dividetriangle(v[0], v[1], v[2], m);
    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 0);
    glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char **argv)
{
    printf("Enter the number of subdivisions: ");
    scanf_s("%d", &m);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Sierpinski Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
