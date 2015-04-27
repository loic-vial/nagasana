#pragma once

#include <renderable.h>
#include <glut.h>
#include <vec3f.h>

class Terrain : public Renderable
{
    public :

        Terrain();

        virtual ~Terrain() {}

        void init(Viewer&);

        void draw();

    private :

        float* h;

        int height;

        int size;

        GLuint texture;
};
