#pragma once

#include <renderable.h>
#include <glut.h>

class Cylinder : public Renderable
{
    public:

        Cylinder(GLfloat length, GLfloat starting_point, GLfloat radiusR, GLfloat radiusL);

        void init(Viewer&);

        void draw();

    private:

        GLfloat length;

        GLfloat starting_point;

        GLfloat radiusR;

        GLfloat radiusL;

};

