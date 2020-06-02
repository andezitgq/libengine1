#include "LibreGE.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

//:===========================:WINDOW:===========================:

void Application::Init(int argc, char *argv[], int x, int y, int w, int h, const char *title) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(x, y);
    glutCreateWindow(title);
}

void Application::ToggleFullscreen() {
    glutFullScreenToggle();
}

//:===========================:DEBUG:===========================:

void Debug::Log(string msg) {
    cout << msg << endl;
}

void Debug::Error(string msg) {
    cout << RED << msg << RESET << endl;
}

void Debug::Warn(string msg) {
    cout << YELLOW << msg << RESET << endl;
}

//:===========================:INPUT:===========================:

bool Input::mouseBool = false;

Input::Input(){
    
}

void Input::mouseLeft(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            mouseBool = true;
        }
    }
}

void Input::mouseRight(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN){
            mouseBool = true;
        }
    }
}

void Input::mouseMiddle(int button, int state, int x, int y) {
    if (button == GLUT_MIDDLE_BUTTON){
        if(state == GLUT_DOWN){
            mouseBool = true;
        }
    }
}

bool Input::GetMouseButtonDown(int key) {
    switch (key)
    {
    case 0:
        glutMouseFunc(mouseLeft);
    
    case 1:
        glutMouseFunc(mouseRight);

    case 2:
        glutMouseFunc(mouseMiddle);
    }

    return mouseBool;
}

//:===========================:MESH:===========================: