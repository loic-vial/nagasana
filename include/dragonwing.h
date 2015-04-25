#pragma once

#include <cylinder.h>
#include <sphere.h>
#include <renderable.h>
#include <glut.h>
#include <membrane.h>

class DragonWing : public Renderable
{
public :


    DragonWing();
    void init(Viewer&);

    void draw();

private :
    Cylinder first_part;
    Cylinder second_part;
    Cylinder member;
    Sphere joint_body;
    Sphere joint;
    Membrane first_membrane;
    Membrane second_membrane;
      GLuint scale_id;
};

