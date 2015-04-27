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

        bool black;

    private :

        Cylinder first_part;

        Cylinder second_part;

        Cylinder member;

        Membrane first_membrane;

        Membrane second_membrane;

        GLuint scale_id;
};

