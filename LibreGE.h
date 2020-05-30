#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include <iostream>
#include <string>

using namespace std;

class Debug
{

private:

public:
    static void Log(string msg);
    static void Error(string msg);
    static void Warn(string msg);
};

//:====================================================:

class Input 
{

private:
    static void mouseLeft(int button, int state, int x, int y);
    static void mouseRight(int button, int state, int x, int y);
    static void mouseMiddle(int button, int state, int x, int y);
    static bool mouseBool;

public:
    Input();
    ~Input();
    static bool GetMouseButtonDown(int button);
    static bool GetMouseButtonUp(int button);
};
