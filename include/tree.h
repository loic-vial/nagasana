#pragma once

#include <renderable.h>
#include <glut.h>

class Tree : public Renderable
{
    public :

        void init(Viewer& v);

        void draw();

    private :

        GLuint texture;
};
