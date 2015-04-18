#pragma once

#include <renderable.h>
#include <glut.h>

class DragonBody : public Renderable
{
    public :

        void init(Viewer&);

        void draw();

};
