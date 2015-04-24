#pragma once
#include <renderable.h>
#include <glut.h>


class Castle : public Renderable
{
    public:

    void init(Viewer&);

    void draw();

    void animate();

    private:
    GLuint wall_id;

};
