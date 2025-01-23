#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846
float t, r = 0.5, x, y, t1 = 360, i = 0.5;

void idle();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 0, 0, 0); // Background color (red)
    glColor3f(1, 1, 1);       // Drawing color (white)

    // Draw the circle
    glBegin(GL_POINTS);
    for (t = 0; t <= 360; t += 1) // Increment t by 1 degree
    {
        float rad = t * M_PI / 180.0; // Convert degrees to radians
        x = r * cos(rad) - i;
        y = r * sin(rad);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw cross lines
    glBegin(GL_LINES);

    glVertex2f(r * -sin(t1 * M_PI / 180.0) - i, r * cos(t1 * M_PI / 180.0));
    glVertex2f(r * sin(t1 * M_PI / 180.0) - i, r * -cos(t1 * M_PI / 180.0));
    glEnd();

    glFlush();
}

void move(int b, int s, int x, int y)
{
    if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
    {
        glutIdleFunc(idle); // Start animation on left-click
    }
    if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
    {
        glutIdleFunc(NULL); // Stop animation on right-click
    }
    if (b == GLUT_MIDDLE_BUTTON && s == GLUT_DOWN)
    {
        exit(0); // Exit on middle-click
    }
}

void idle()
{
    i += 0.001; // Update position
    if (i > 1)
    {
        i = -0.5; // Reset position
    }
    t1 += 1; // Rotate lines
    if (t1 >= 360)
    {
        t1 = 0; // Reset rotation
    }

    glutPostRedisplay(); // Trigger a redraw
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Wheel Animation");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1); // Set up a 2D orthographic viewing region

    glutDisplayFunc(display);
    glutMouseFunc(move);
    glutIdleFunc(NULL);
    glutMainLoop();
    return 0;
}
