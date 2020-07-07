#include "LibreGE.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    GameWindow *window = Renderer::InitWindow(800, 600, "Hello World");
    while (!Renderer::ShouldClose(window)){
        Renderer::ProcessInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return Renderer::Exit();
}
