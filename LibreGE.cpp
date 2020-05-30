#include "LibreGE.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

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

Input::Input(){
    mouseBool = false;
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