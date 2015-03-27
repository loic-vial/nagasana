#include "dragon.h"

void Dragon::init(Viewer& viewer)
{
    body.init(viewer);
    left_wing.init(viewer);
    right_wing.init(viewer);
    tail.init(viewer);
}

void Dragon::draw()
{
    body.draw();
    left_wing.draw();
    right_wing.draw();
    tail.draw();
}

