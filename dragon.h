#ifndef DRAGON_H
#define DRAGON_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "dragonbody.h"
#include "dragonwing.h"
#include "dragontail.h"

class Dragon : public Renderable
{
    public:

        void init(Viewer&);

        void draw();

    private :

        DragonBody body;

        DragonWing left_wing;

        DragonWing right_wing;

        DragonTail tail;
};

#endif // DRAGON_H
