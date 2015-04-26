#pragma once

#include <renderable.h>
#include <glut.h>

class Skybox : public Renderable
{
    public :

        Skybox();

        virtual ~Skybox() {}

        void init(Viewer&);

        void draw();

    private :

        GLuint texture_back, texture_front, texture_top, texture_left, texture_right, texture_sky;

};
