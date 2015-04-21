#include <glew.h>
#include <dragon.h>
#include <viewer.h>
#include <iostream>
#include <utils.h>

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

    GLfloat direction[4];
    direction[0]=0 ;
    direction[1]=0;
    direction[2]=10;
    direction[3]=0.0;
    glLightfv(GL_LIGHT0, GL_POSITION, direction);

    glPushMatrix();

    glPushMatrix();
    glTranslatef(0, 50,42);
    glRotatef(-50,1,0,0);
    fire.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-18, -3, 5);
    tail.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6, 16, 26);
    glRotatef(100,0,0,1);
    glRotatef(45,-1,0,0);
    right_wing.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6, 16, 26);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    left_wing.draw();
    glPopMatrix();

    glPopMatrix();



}

void Dragon::animate()
{
    body.animate();
    left_wing.animate();
    right_wing.animate();
    tail.animate();
    fire.animate();
}
