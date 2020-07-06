#include <GL/glew.h>
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

//:===========================:RENDERER:===========================:
class Renderer
{

private:

public:
    Renderer();
    ~Renderer();
    static void Init(int argc, char *argv[], int x, int y, int w, int h, const char *title);
    static void ToggleFullscreen();
};

//:===========================:DEBUG:===========================:
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

//:===========================:TRANSFORM:===========================:
class Transform
{

private:

public:

};

//:===========================:GAMEOBJECT:===========================:
class GameObject : public Transform
{

private:

public:

};

//:===========================:RIGIDBODY:===========================:
class RigidBody
{

private:

public:

};

//:===========================:MESH:===========================:
class Mesh
{

private:

public:

};

//:===========================:CAMERA:===========================:
class Camera : public Transform
{

private:

public:

};

//:===========================:COLLIDER:===========================:
class Collider : public Transform
{

private:

public:

};

//:===========================:TEXTURE:===========================:
class Texture
{

private:

public:

};

//:===========================:MATERIAL:===========================:
class Material
{

private:

public:

};

//:===========================:AUDIOSOURCE:===========================:
class AudioSource
{

private:

public:

};

//:===========================:AUDIOLISTENER:===========================:
class AudioListener
{

private:

public:

};
