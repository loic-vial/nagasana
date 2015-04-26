#include <forest.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Forest::init(Viewer &v)
{
    trees_nb = 10;
    tree = new Tree();
    tree->init(v);
}

void Forest::draw()
{
    for (int i = 0 ; i < trees_nb ; i++)
    {
        glPushMatrix();
        float angle = (((float)i) / ((float)trees_nb)) * 3.14 / 2.0;
        float posx = 1000 * cos(angle);
        float posy = 1000 * sin(angle);
        glTranslatef(posx, posy, 0);
        tree->draw();
        glPopMatrix();
    }
}
