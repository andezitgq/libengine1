#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include <iostream>
#include <string>

#pragma once

using namespace std;

//:====================================================:

class Application
{

private:

public:
    Application();
    ~Application();
    static void Init(int argc, char *argv[], int x, int y, int w, int h, const char *title);
    static void ToggleFullscreen();
};

//:====================================================:

class Debug
{

private:
    

public:
    Debug();
    ~Debug();
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

//:====================================================:

class Transform
{

private:

public:

}

//:====================================================:
class GameObject : public Transform
{

private:

public:

};