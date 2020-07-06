#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <GL/glx.h>
#include <GL/freeglut.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

//:===========================:SHADER:==========================:
class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void use();
    void setBool(const string &name, bool value) const;
    void setInt(const string &name, int value) const;
    void setFloat(const string &name, float value) const;

private:
    void checkCompileErrors(unsigned int shader, string type);
};

//:===========================:MESH:===========================:

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
};

class Mesh {
    public:
        vector<Vertex>       vertices;
        vector<unsigned int> indices;
        vector<Texture>      textures;

        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
        void Draw(Shader shader);
    private:
        unsigned int VAO, VBO, EBO;

        void setupMesh();
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
