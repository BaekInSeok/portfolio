#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//컴퓨터소프트웨어공학과
//20184045_백인석


void display(void)
{
    glColor3f(1.0, 1.0, 1.0);

    glLineWidth(10.0);
    glPointSize(10);
    double radius = 2;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = -33; i < 180; i++)
    {
        double angle = i * 3.141592 / 180;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x - 1, y);
    }
    glEnd();
    radius = 2;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = -33; i > -210; i--)
    {
        double angle = i * 3.141592 / 180;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x - 1, y);
    }
    glEnd();
    radius = 1;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++)
    {
        double angle = i * 3.141592 / 180;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x - 1.9, y + 0.38);
    }
    glEnd();
    radius = 1;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        double angle = i * 3.141592 / 180;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x - 0.1, y - 0.4);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(3,1.5);
    glVertex2f(1,3.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(4, 2.5);
    glVertex2f(2, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(1, 1.5);
    glVertex2f(5,5.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(3.5, 2);
    glVertex2f(1.5, 4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-5.5, 1.5);
    glVertex2f(-3.5, 3.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-6.5, 2.5);
    glVertex2f(-4.5, 4.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-6, 2);
    glVertex2f(-4, 4);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-6, -2);
    glVertex2f(-4, -4);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-7, -5);
    glVertex2f(-4, -2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-6.5, -2.5);
    glVertex2f(-4.5, -4.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-5.5, -1.5);
    glVertex2f(-3.5, -3.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(3, -1.5);
    glVertex2f(1, -3.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(4, -2.5);
    glVertex2f(2, -4.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(3.5, -2);
    glVertex2f(1.5, -4);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(1, -1.5);
    glVertex2f(5, -5.5);
    glEnd();


    glFlush();
}



void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape(int new_w, int new_h)
{
    glViewport(0, 0, new_w, new_h);
    float  WidthFactor = (float)new_w / 250.0;
    float  HeightFactor = (float)new_h / 250.0; \

        glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-5.0 * WidthFactor, 5.0 * WidthFactor, -5.0 * HeightFactor, 5.0 * HeightFactor);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("01 사각형 그리기 ");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}