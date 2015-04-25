#pragma once

#include <dragonbody.h>
#include <dragonwing.h>
#include <dragontail.h>
#include <fire.h>

class Dragon : public Renderable
{
public:

    void init(Viewer&);

    void draw();

        void draw1();
    void animate();

    void ombre();

private :

    DragonBody body;

    DragonWing left_wing;

    DragonWing right_wing;

    DragonTail tail;

    Fire fire;
};
