#pragma once

#include "dragonbody.h"
#include "dragonwing.h"
#include "dragontail.h"

class Dragon : public Renderable
{
    public:

        void init(Viewer&);

        void draw();

        void animate();

    private :

        DragonBody body;

        DragonWing left_wing;

        DragonWing right_wing;

        DragonTail tail;
};
