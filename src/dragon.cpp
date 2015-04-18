#include <dragon.h>
#include <viewer.h>
#include <iostream>

using namespace std;

void Dragon::init(Viewer& viewer)
{
    body.init(viewer);
    left_wing.init(viewer);
    right_wing.init(viewer);
    tail.init(viewer);
    fire.init(viewer);
}

void Dragon::draw()
{
    body.draw();
    left_wing.draw();
    right_wing.draw();
    tail.draw();
    fire.draw();
}

void Dragon::animate()
{
    body.animate();
    left_wing.animate();
    right_wing.animate();
    tail.animate();
    fire.animate();
}
