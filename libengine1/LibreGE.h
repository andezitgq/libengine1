#include <GL/glew.h>
#include <GL/glx.h>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
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
    static void posix_death_signal(int signum)
    {
        Debug::Error("Segfault detected!");
        signal(signum, SIG_DFL);
        exit(3);
    }

public:
    Debug();
    ~Debug();
    static void Log(string msg);
    static void Error(string msg);
    static void Warn(string msg);
    static void CatchSegfault(){
        signal(SIGSEGV, posix_death_signal);
    }
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
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec2(const std::string& name, float x, float y) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec3(const std::string& name, float x, float y, float z) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;
    void setVec4(const std::string& name, float x, float y, float z, float w) const;
    void setMat2(const std::string& name, const glm::mat2& mat) const;
    void setMat3(const std::string& name, const glm::mat3& mat) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

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
        static unsigned int StaticTextureFromFile(const char *path, const string &directory, bool gamma = false);
        void loadModel(string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};

//:==========================:CAMERA:==========================:
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW         = -90.0f,
            PITCH       =  0.0f,
            SPEED       =  2.5f,
            SENSITIVITY =  0.1f,
            ZOOM        =  45.0f;

class Camera
{
public:
    // Атрибуты камеры
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    float Yaw;
    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    glm::mat4 GetViewMatrix();
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

private:
    void updateCameraVectors();
};
