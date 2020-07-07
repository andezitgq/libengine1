#include <GL/glew.h>
#include <GL/glx.h>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <glm/mat4x4.hpp>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "stb_image.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#pragma once

using namespace std;

//:===========================:RENDERER:===========================:
typedef GLFWwindow GameWindow;

class Renderer
{

private:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
    Renderer();
    ~Renderer();
    static GameWindow *InitWindow(int w, int h, const char *title);
    static bool ShouldClose(GameWindow *window);
    static void ProcessInput(GameWindow *window);
    static void ToggleFullscreen();
    static int Exit();
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
    aiString path;
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
//:==========================:MODEL:==========================:
class Model
{
    public:
        Model(string path);
        void Draw(Shader &shader);

    private:
        vector<Mesh> meshes;
        string directory;

        void loadModel(string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};
