#pragma once

#include <renderable.h>
#include <glut.h>
#include <cylinder.h>

class DragonHead : public Renderable
{
    public :

    DragonHead();
        void init(Viewer&);

        void draw();
private:
        Cylinder face;
};
