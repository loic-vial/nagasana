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

    glEnable(GL_LIGHT0);

    glPushMatrix();
    glTranslatef(0, 44,38);
    glRotatef(-55,1,0,0);

    //lumiere
   glEnable(GL_LIGHT2);
    GLfloat ambient2[] = {0.15f,0.15f,0.15f,1.0f};
 //   GLfloat diffuse2[] = {1.0f,-0.19f,-0.3f,1.0f};
      GLfloat diffuse2[] = {1.0f,-0.29f,-0.4f,1.0f};
    GLfloat light2_position [] = {0.0f, 20.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT2,GL_AMBIENT,ambient2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,diffuse2);
    glLightfv(GL_LIGHT2,GL_POSITION,light2_position);

    fire.draw();
    glPopMatrix();

    glDisable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(-20, -3, 2);
    tail.draw();
    glPopMatrix();

    glEnable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
    glPopMatrix();
    glDisable(GL_LIGHT2);

    glPushMatrix();
    glTranslatef(2, 16, 22);
    glRotatef(100,0,0,1);
    glRotatef(45,-1,0,0);
    right_wing.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, 16, 22);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    left_wing.draw();
    glPopMatrix();

    glDisable(GL_LIGHT1);

}

void Dragon::animate()
{
    body.animate();
    left_wing.animate();
    right_wing.animate();
    tail.animate();
    fire.animate();
}


