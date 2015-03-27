TEMPLATE = app
TARGET = nagasana
CONFIG += qt opengl warn_on debug
QT *= xml opengl 

HEADERS  = *.h \
    particle.h \
    spring.h \
    dragon.h \
    dragonbody.h \
    dragonhead.h \
    dynamicsystem.h \
    dragontail.h \
    dragonwings.h
SOURCES  = *.cpp \
    particle.cpp \
    spring.cpp \
    dragon.cpp \
    dragonbody.cpp \
    dragonhead.cpp \
    dynamicsystem.cpp \
    dragontail.cpp \
    dragonwings.cpp

macx:LIBS *= -framework Glut
linux-g++*:LIBS *= -lglut

QGL = -lqglviewer

exists( /usr/lib/libqglviewer-qt4.so): QGL = -lqglviewer-qt4
exists( /usr/lib/x86_64-linux-gnu/libqglviewer-qt4.so ): QGL = -lqglviewer-qt4
exists( /usr/lib/x86_64-linux-gnu/libQGLViewer.so.2 ): QGL=-lQGLViewer -lGLU
exists( /usr/lib64/libQGLViewer.so ): QGL=-lQGLViewer

LIBS *= $${QGL}
