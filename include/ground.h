#pragma once

#include <renderable.h>
#include <glew.h>
#include <shaderprogram.h>

class Ground : public Renderable
{
    public:

        Ground();

        void init(Viewer&);

        void draw();

    private :

        GLuint texture_id;

        ShaderProgram program;

        GLint texture0;

        GLint texcoord0;
};
