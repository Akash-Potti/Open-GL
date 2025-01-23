#include <GL/glut.h>
#include <stdio.h>

float v[4][3] = {{0, 0, 1}, {0, 1, 0}, {-1, -0.5, 0}, {1, -0.5, 0}};
float color[4][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
int m;

void triangles(float *va, float *vb, float *vc)
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
    glEnd();
}

void tetra(float *a, float *b, float *c, float *d)
{
    glColor3fv(color[0]);
    triangles(a, b, c);
    glColor3fv(color[1]);
    triangles(a, c, d);
    glColor3fv(color[2]);
    triangles(a, d, b);
    glColor3fv(color[3]);
    triangles(b, d, c);
}

void dividetetra(float *a, float *b, float *c, float *d, int m)
{
    float midpoints[6][3];
    int j;

    if (m > 0)
    {
        for (j = 0; j < 3; j++)
        {
            midpoints[0][j] = (a[j] + b[j]) / 2;
            midpoints[1][j] = (a[j] + c[j]) / 2;
            midpoints[2][j] = (a[j] + d[j]) / 2;
            midpoints[3][j] = (b[j] + c[j]) / 2;
            midpoints[4][j] = (c[j] + d[j]) / 2;
            midpoints[5][j] = (b[j] + d[j]) / 2;
        }

        dividetetra(a, midpoints[0], midpoints[1], midpoints[2], m - 1);
        dividetetra(midpoints[0], b, midpoints[3], midpoints[5], m - 1);
        dividetetra(midpoints[1], midpoints[3], c, midpoints[4], m - 1);
        dividetetra(midpoints[2], midpoints[5], midpoints[4], d, m - 1);
    }
    else
    {
        tetra(a, b, c, d);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dividetetra(v[0], v[1], v[2], v[3], m);
    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glClearColor(1, 1, 1, 1);
    glColor3f(0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    printf("Enter the number of subdivisions: ");
    scanf_s("%d", &m);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Sierpinski Tetrahedron");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
