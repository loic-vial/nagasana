#pragma once

#include <renderable.h>
#include <glut.h>

class Cylinder : public Renderable
{
    public:

        Cylinder(GLfloat plength,GLfloat pstarting_point,GLfloat pradiusR, GLfloat pradiusL);

        void init(Viewer&);

        void draw();


    private:

        GLfloat plength;

        GLfloat pstarting_point;

        GLfloat pradiusR;

        GLfloat pradiusL;

        void drawImmediate();

};

