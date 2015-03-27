#pragma once

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "dynamicsystem.h"

class DragonTail : public Renderable
{
    public :

        void init(Viewer&);

        void draw();

    private :

        DynamicSystem system;

};

