TEMPLATE = app
TARGET = nagasana
CONFIG += qt opengl warn_on debug
QT *= xml opengl 

macx:LIBS *= -framework Glut
linux-g++*:LIBS *= -lglut

QGL = -lqglviewer

exists( /usr/lib/libqglviewer-qt4.so): QGL = -lqglviewer-qt4
exists( /usr/lib/x86_64-linux-gnu/libqglviewer-qt4.so ): QGL = -lqglviewer-qt4
exists( /usr/lib/x86_64-linux-gnu/libQGLViewer.so.2 ): QGL=-lQGLViewer -lGLU
exists( /usr/lib64/libQGLViewer.so ): QGL=-lQGLViewer

LIBS *= $${QGL}

HEADERS += \
    cube.h \
    cylinder.h \
    dragon.h \
    dragonbody.h \
    dragonhead.h \
    dragontail.h \
    dragonwing.h \
    dynamicsystem.h \
    particle.h \
    renderable.h \
    spring.h \
    viewer.h \
    glut.h \
    ground.h \
    sphere.h

SOURCES += \
    cube.cpp \
    cylinder.cpp \
    dragon.cpp \
    dragonbody.cpp \
    dragonhead.cpp \
    dragontail.cpp \
    dragonwing.cpp \
    dynamicsystem.cpp \
    main.cpp \
    particle.cpp \
    spring.cpp \
    viewer.cpp \
    ground.cpp \
    sphere.cpp
