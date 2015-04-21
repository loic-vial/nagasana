#pragma once

#include <glut.h>
#include <viewer.h>

class Foot
{
    public:

        void init(Viewer&);

        void draw();

    private:

        GLuint foot_id;
};
