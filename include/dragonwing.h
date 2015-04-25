#pragma once

#include <renderable.h>
#include <cylinder.h>
#include <sphere.h>
#include <membrane.h>

class DragonWing : public Renderable
{
    public :

        DragonWing();

        void init(Viewer&);

        void draw();

        void animate();

    private :

        Cylinder first_part;

        Cylinder second_part;

        Cylinder member;

        Sphere joint_body;

        Sphere joint;

        Membrane first_membrane;

        Membrane second_membrane;
};

