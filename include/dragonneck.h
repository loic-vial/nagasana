#pragma once

#include <renderable.h>
#include <glut.h>
#include <cylinder.h>
#include<sphere.h>

class DragonNeck : public Renderable
{
    public :

    DragonNeck();
        void init(Viewer&);

        void draw();
private:
        Cylinder first_part;
        Cylinder second_part;
        Cylinder third_part;
        Sphere first_joint;
        Sphere second_joint;
};
