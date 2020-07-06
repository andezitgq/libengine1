#include "LibreGE.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Renderer::Init(argc, argv, 250, 250, 250, 250, "Hello World");
    glutMainLoop();
    return 0;
}
