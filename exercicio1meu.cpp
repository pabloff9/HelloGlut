#include <iostream>
#include <GL/glut.h>

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

static const char *const WINDOW_TITLE = "Drawing board window";

void draw();

void centerWindow();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    centerWindow();
    glutCreateWindow(WINDOW_TITLE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(draw);
    glutMainLoop();
}

void centerWindow() {
    unsigned int screenWidth = static_cast<unsigned int>(glutGet(GLUT_SCREEN_WIDTH));
    unsigned int screenHeight = static_cast<unsigned int>(glutGet(GLUT_SCREEN_HEIGHT));
    glutInitWindowPosition(
            (screenWidth-WINDOW_WIDTH)/2,
            (screenHeight-WINDOW_HEIGHT)/2
    );
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
