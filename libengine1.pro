TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        LibreGE.cpp \
        LibreGE/Lua.cpp \
        LibreGE/UI.cpp \
        main.cpp \
        stb_image.cpp

LIBS += -lGLU -lglut -lGLEW -lGL -lassimp -lglfw

HEADERS += \
    LibreGE.h \
    LibreGE/Lua.h \
    LibreGE/UI.h \ \
    stb_image.h
