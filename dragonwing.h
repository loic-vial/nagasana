#pragma once

#include "cylinder.h"
#include "sphere.h"
#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class DragonWing : public Renderable
{
    public :


         DragonWing();
        void init(Viewer&);

        void draw();

private :
        Cylinder first_part;
        Cylinder second_part;
        Sphere joint_body;
        Sphere joint;



};

