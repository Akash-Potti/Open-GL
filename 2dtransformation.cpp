#include <GL/glut.h>
#include <stdio.h>

char T;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glVertex2f(0, -500);
    glVertex2f(0, 500);
    glEnd();

    glColor3f(0, 0, 0);
    glRecti(0, 0, 100, 150);

    if (T == 't')
    {
        printf("\nTranslation");
        glLoadIdentity();
        glColor3f(1, 0, 0);
        glTranslatef(-100, -50, 0);
        glRecti(0, 0, 100, 150);
    }
    if (T == 'r')
    {
        printf("\nRotation");
        glLoadIdentity();
        glColor3f(0, 1, 0);
        glRotatef(45, 0, 0, 0);
        glRecti(0, 0, 100, 150);
    }
    if (T == 's')
    {
        printf("\nScaling");
        glLoadIdentity();
        glColor3f(0, 0, 1);
        glScalef(0.5, 0.5, 0);
        glRecti(0, 0, 100, 150);
    }

    glFlush();
}

void keys(unsigned char key, int x, int y)
{
    if (key == 't' || key == 'r' || key == 's')
    {
        T = key;
        glutPostRedisplay();
    }
}

void myinit()
{
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    glPointSize(1);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformation");
    myinit();
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutMainLoop();
    return 0;
}
