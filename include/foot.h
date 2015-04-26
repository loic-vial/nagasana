#pragma once

#include <glut.h>
#include <viewer.h>

class Foot
{
    public:

        void init(Viewer&);

        void draw();

        bool black;
    private:

        GLuint foot_id;

        GLuint scale_id;
};
