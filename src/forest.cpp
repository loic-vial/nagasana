#include <forest.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Forest::init(Viewer &v)
{
    trees_nb = 20;
    for (int i = 0 ; i < trees_nb ; i++)
    {
        Tree* tree = new Tree();
        tree->init(v);
        float angle = -0.50 + (((float)i) / ((float)trees_nb)) * 3.14 * 1.0;
        float posx = (1100 + rand() % 1000) * cos(angle);
        float posy = (1100 + rand() % 1000) * sin(angle);
        tree->position.x = posx;
        tree->position.y = posy;
        tree->rotation = rand() % 360;
        trees.push_back(tree);
    }
}

void Forest::draw()
{
    for (int i = 0 ; i < trees_nb ; i++)
    {
        trees[i]->draw();
    }
}
