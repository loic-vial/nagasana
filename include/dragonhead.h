#pragma once

#include <renderable.h>
#include <glut.h>

class DragonHead : public Renderable
{
    public :

        void init(Viewer&);

        void draw();

};
