#pragma once

#include <renderable.h>
#include <glut.h>

class Cylinder : public Renderable
{
    public:

        Cylinder(GLfloat lengt, GLfloat radiusR, GLfloat radiusL);

        void init(Viewer&);

        void draw();

        void setId(GLuint id);

    private:

        GLfloat length;

        GLuint id;

        GLfloat radiusR;

        GLfloat radiusL;

};

