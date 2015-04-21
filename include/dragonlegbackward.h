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

private :
    Cylinder first_part;
    Cylinder second_part;
    Sphere joint_body;
    Sphere joint;
    Sphere footjoint;
};
