TEMPLATE = app
TARGET = nagasana
CONFIG += qt opengl warn_on debug
QT *= xml opengl 

macx:LIBS *= -framework Glut
linux-g++*:LIBS *= -lglut

QGL = -lqglviewer
exists(/usr/lib/libqglviewer-qt4.so): QGL = -lqglviewer-qt4
exists(/usr/lib/x86_64-linux-gnu/libqglviewer-qt4.so): QGL = -lqglviewer-qt4
exists(/usr/lib/x86_64-linux-gnu/libQGLViewer.so.2): QGL = -lQGLViewer -lGLU
exists(/usr/lib64/libQGLViewer.so): QGL = -lQGLViewer

LIBS *= $${QGL}

INCLUDEPATH += include

HEADERS += \
    include/cube.h \
    include/cylinder.h \
    include/dragon.h \
    include/dragonbody.h \
    include/dragonhead.h \
    include/dragontail.h \
    include/dragonwing.h \
    include/particle.h \
    include/renderable.h \
    include/spring.h \
    include/viewer.h \
    include/glut.h \
    include/ground.h \
    include/sphere.h \
    include/membrane.h \
    include/fire.h \
    include/fireParticle.h \
    src/leg.h \
    include/dragonleg.h

SOURCES += \
    src/cube.cpp \
    src/cylinder.cpp \
    src/dragon.cpp \
    src/dragonbody.cpp \
    src/dragonhead.cpp \
    src/dragontail.cpp \
    src/dragonwing.cpp \
    src/main.cpp \
    src/particle.cpp \
    src/spring.cpp \
    src/viewer.cpp \
    src/ground.cpp \
    src/sphere.cpp \
    src/membrane.cpp \
    src/fire.cpp \
    src/fireParticle.cpp \
    src/dragonleg.cpp

