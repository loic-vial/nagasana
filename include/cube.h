#pragma once

#include <renderable.h>
#include <glut.h>

class Cube : public Renderable
{
    public:

        void draw();

    private:

        void drawImmediate();

        void drawElements();

        void drawArrays();
};
