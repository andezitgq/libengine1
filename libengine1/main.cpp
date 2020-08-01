#include "LibreGE.h"
#include <iostream>

using namespace std;

void framebuffer_size_callback(GameWindow* window, int width, int height);
void mouse_callback(GameWindow* window, double xpos, double ypos);
void scroll_callback(GameWindow* window, double xoffset, double yoffset);
void processInput(GameWindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
    GameWindow *window = Renderer::InitWindow(800, 600, "Hello, LibreGE!");
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);

    Shader ourShader("shaders/model.vs", "shaders/model.fs");
    Model ourModel("resources/objects/backpack/backpack.dae");

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return Renderer::Exit();
}

void processInput(GameWindow* window)
{
    if (Input::GetKey(window, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
    if (Input::GetKey(window, GLFW_KEY_W))
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (Input::GetKey(window, GLFW_KEY_S))
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (Input::GetKey(window, GLFW_KEY_A))
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (Input::GetKey(window, GLFW_KEY_D))
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GameWindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GameWindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GameWindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
