#pragma once

#include <renderable.h>
#include <sphere.h>
#include <cylinder.h>
#include <glut.h>
#include <dragonleg.h>

class DragonBody : public Renderable
{
    public :
        DragonBody();
        void init(Viewer&);

        void draw();
    private :
        Cylinder body;
        DragonLeg leftleg;
        DragonLeg rightleg;

};
