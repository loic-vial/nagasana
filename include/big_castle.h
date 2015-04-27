#pragma once

#include <renderable.h>
#include <glut.h>
#include <castle.h>

class BigCastle : public Renderable
{
    public:

        BigCastle();

        void init(Viewer&);

        void draw();

        void animate();

        void burn1();

        void burn2();

        void burn3();

    private:

        Castle first;

        Castle second;

        bool burned;

        bool black;
};
