/*  demo.c*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include <stdio.h>

int windowId, menu;

int x,y,l;

void setup()
{
    x=0; y=0; l=10;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void display()
{
    if (x==0 && y==0) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(x,y, x+l, y+l);
    glutSwapBuffers();
}

void procmenu (int value)
{
    switch (value)
    {
        case 1: setup();
            glutPostRedisplay();
            break;
        case 2: glutDestroyWindow(windowId);
            break;
    }
}


void prockey(unsigned char key, int x_, int y_)
{
    switch (key) {
        case 'k':
        case 'K': if (x>0)
            {
                x--;
                glutPostRedisplay();
            }
            break;
        case 'l':
        case 'L': if (x<glutGet(GLUT_WINDOW_WIDTH)-l-1)
            {
                x++;
                glutPostRedisplay();
            }
            break;
        case 'a':
        case 'A': if (y>0)
            {
                y--;
                glutPostRedisplay();
            }
            break;
        case 'q':
        case 'Q': if (y<glutGet(GLUT_WINDOW_HEIGHT)-l-1)
            {
                y++;
                glutPostRedisplay();
            }
            break;
    }
}

void specialInputHandler(int key, int x_, int y_) {
    switch (key) {
        case GLUT_KEY_UP:
            if (y < glutGet(GLUT_WINDOW_HEIGHT)-l-1) {
                y++;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_DOWN:
            if (y>0) {
                y--;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_LEFT:
            if (x>0) {
                x--;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_RIGHT:
            if (x < glutGet(GLUT_WINDOW_WIDTH)-l-1) {
                x++;
                glutPostRedisplay();
            }
            break;
        default:
            break;

    }
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800,600);

    windowId = glutCreateWindow("Hello World");

    gluOrtho2D(0, 799, 0,599);

    glutCreateMenu(procmenu);
    glutAddMenuEntry("Limpar", 1);
    glutAddMenuEntry("Sair", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    setup();
    glutDisplayFunc(display);
    glutKeyboardFunc(prockey);
    glutSpecialFunc(specialInputHandler);
    glutMainLoop();

    return 0;
}