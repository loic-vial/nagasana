#pragma once

#include <renderable.h>
#include <glut.h>
#include <cylinder.h>

class DragonHead : public Renderable
{
    public :

        DragonHead();

        void init(Viewer&);

        void eye();

        void ear();

        void mouth();

        void draw();

        void display_mouth();

    private:

        Cylinder face;

        GLuint eye_id;

        GLuint scale_id;

        bool mouth_displayed;
};
