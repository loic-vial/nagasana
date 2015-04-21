#pragma once

#include <renderable.h>
#include <shaderprogram.h>

class Foot
{
public:

    void init(Viewer&);
    void draw();



private:
    GLuint foot_id;

    ShaderProgram program;

    GLint texture0;

    GLint texcoord0;
};
