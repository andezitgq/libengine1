//   __           __                   ____    ____      
//  /\ \       __/\ \                 /\  _`\ /\  _`\*
//  \ \ \     /\_\ \ \____  _ __    __\ \ \L\_\ \ \L\_\*
//   \ \ \  __\/\ \ \ '__`\/\`'__\/'__`\ \ \L_L\ \  _\L  
//    \ \ \L\ \\ \ \ \ \L\ \ \ \//\  __/\ \ \/, \ \ \L\ \*
//     \ \____/ \ \_\ \_,__/\ \_\\ \____\\ \____/\ \____/
//      \/___/   \/_/\/___/  \/_/ \/____/ \/___/  \/___/ 
//                                                       
//                                                       
//  
//                                          Version 1.0
//  
//                         Andezit: <admin@andezit.net>
//  
//  =====================================================
//  
//  Copyright (C) 2020 Andezit
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  =====================================================
//   


#include "LibreGE.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

//:===========================:RENDERER:===========================:

void Renderer::Init(int argc, char *argv[], int x, int y, int w, int h, const char *title) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(x, y);
    glutCreateWindow(title);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
}

void Renderer::ToggleFullscreen() {
    glutFullScreenToggle();
}

//:===========================:DEBUG:===========================:

void Debug::Log(string msg) {
    cout << msg << endl;
}

void Debug::Error(string msg) {
    cout << RED << msg << RESET << endl;
}

void Debug::Warn(string msg) {
    cout << YELLOW << msg << RESET << endl;
}

//:===========================:MESH:===========================:
