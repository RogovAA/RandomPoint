#include <GL/glut.h>
#include <stdlib.h>

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for(int i = 0; i < 5; i++){
        glVertex3f(rand()%200, rand()%200, rand()%200);
    }
    glEnd();
    glutSwapBuffers();
}

int main1(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tochka");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 400, 0, 400, 0, 400);
    glutDisplayFunc(display1);
    glutMainLoop();
}
