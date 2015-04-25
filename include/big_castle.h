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
private:
        Castle first;
        Castle second;
        bool burned;
};
