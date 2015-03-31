#pragma once

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class DragonHead : public Renderable
{
    public :

        void init(Viewer&);

        void draw();

};
