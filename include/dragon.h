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

        void animate();

        void keyPressEvent(QKeyEvent*, Viewer&);

    private :

        DragonBody body;

        DragonWing left_wing;

        DragonWing right_wing;

        DragonTail tail;

        Fire fire;

        float max_rotation;

        float min_rotation;

        float rotation;

        bool rotate_backward;

        bool is_flying;

        float position;
};
