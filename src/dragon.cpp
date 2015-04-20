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

    glPushMatrix();
    glTranslatef(6, 20, 16);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    left_wing.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6, 20, 16);

    glRotatef(100,0,0,1);
       glRotatef(45,-1,0,0);
    right_wing.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18, -3, 5);
    tail.draw();
    glPopMatrix();

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
