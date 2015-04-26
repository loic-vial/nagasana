#pragma once

#include <cylinder.h>
#include <sphere.h>
#include <renderable.h>
#include <glut.h>
#include <membrane.h>
#include <foot.h>

class DragonLegBackward : public Renderable
{
public :


    DragonLegBackward();
    void init(Viewer&);

    void draw();

    bool black;

private :
    Cylinder first_part;
    Cylinder second_part;
    GLuint scale_id;
};

