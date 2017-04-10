#include <iostream>
#include <GL/glut.h>

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const char *const WINDOW_TITLE = "Drawing board window";

static const int CLEAR_SCREEN_MENU_ENTRY = 1;
static const char *const CLEAR_SCREEN_LABEL = "Limpar tudo";

void draw();
void centerWindow();
void menuItemClicked(int clickedItem);
void createContextMenu();

void clearScreen();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    centerWindow();
    glutCreateWindow(WINDOW_TITLE);
    createContextMenu();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(draw);
    glutMainLoop();
}

void createContextMenu() {
    glutCreateMenu(menuItemClicked);
    glutAddMenuEntry(CLEAR_SCREEN_LABEL, CLEAR_SCREEN_MENU_ENTRY);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
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
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutSwapBuffers();
}

void menuItemClicked(int clickedItem) {
    switch (clickedItem) {
        case CLEAR_SCREEN_MENU_ENTRY:
            clearScreen();
            break;
        default:
            break;
    }
}

void clearScreen() {
    std::cout << "Cliquei em limpar tela!" << std::endl;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}
