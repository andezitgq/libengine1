#include <GL/glew.h>
#include <GL/glx.h>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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


typedef GLFWwindow GameWindow;

//:===========================:INPUT:===========================:
class Input {

public:
    static bool GetKey(GameWindow *window, int key);
    static bool GetKeyDown(GameWindow *window, int key);
    static bool GetKeyUp(GameWindow *window, int key);
};

//:===========================:RENDERER:===========================:
class Renderer
{

private:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
    Renderer();
    ~Renderer();
    static GameWindow *InitWindow(int w, int h, const char *title);
    static bool ShouldClose(GameWindow *window);
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
    int ID;

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
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
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
        vector<Texture> textures_loaded;
        vector<Mesh>    meshes;
        string directory;

        bool gammaCorrection;
        Model(string path);
        void Draw(Shader &shader);

    private:
        unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);
        void loadModel(string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};
