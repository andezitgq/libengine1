TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        LibreGE.cpp \
        LibreGE/Lua.cpp \
        LibreGE/UI.cpp \
        main.cpp

LIBS += -lGLU -lglut -lGLEW -lGL

HEADERS += \
    LibreGE.h \
    LibreGE/Lua.h \
    LibreGE/UI.h \
