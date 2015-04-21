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
    glPushMatrix();
glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); 	// Active l'éclairage
    glEnable(GL_LIGHT0);

    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
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


    glPushMatrix();
    glTranslatef(-18, -3, 5);
    tail.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-20, 18,45);
    glRotatef(-44,1,0,0);
    fire.draw();
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
