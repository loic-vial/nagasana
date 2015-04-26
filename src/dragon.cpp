#include <glew.h>
#include <dragon.h>
#include <viewer.h>
#include <iostream>
#include <utils.h>
#include <cmath>

using qglviewer::Vec;
using namespace std;

void Dragon::init(Viewer& v)
{
    body.init(v);
    left_wing.init(v);
    right_wing.init(v);
    tail.init(v);
    fire.init(v);

    max_rotation = 50;
    min_rotation = -10;
    wings_rotation = 20;
    rotate_backward = true;
    is_flying = false;
    camera_focus = false;
    position = Vec(0, 0, 0);
    rotation = Vec(0, 0, 0);
    velocity = Vec(0, 0, 0);
    viewer = &v;
    state = ON_THE_GROUND;
}

void Dragon::draw()

{
    glEnable(GL_LIGHT0);

    glPushMatrix();

    glTranslatef(-600, -600, 0);

    //  glTranslatef(0, 44,38);
    //  glRotatef(-55,1,0,0);

    //lumiere


    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);

    glPushMatrix();
 glTranslatef(0, 45,34);
  glRotatef(-55,1,0,0);

    glEnable(GL_LIGHT2);
    GLfloat ambient2[] = {0.15f,0.15f,0.15f,1.0f};
    GLfloat diffuse2[] = {10.0f,-0.39f,-0.5f,1.0f};
    GLfloat light2_position [] = {0.0f, 0.0f, 0.0f, 1.0f};

    GLfloat light2_direction [] = {0.0f, -1.0f,-0.5f};
    glLightfv(GL_LIGHT2,GL_AMBIENT,ambient2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,diffuse2);
    glLightfv(GL_LIGHT2,GL_POSITION,light2_position);
    glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,light2_direction);
    glLighti(GL_LIGHT2,GL_SPOT_CUTOFF,90);
    glLighti(GL_LIGHT2,GL_SPOT_EXPONENT,1);

  glEnable(GL_LIGHT3);
    GLfloat ambient3[] = {0.15f,0.15f,0.15f,1.0f};
    GLfloat diffuse3[] = {10.0f,-0.39f,-0.5f,1.0f};
    GLfloat light3_position [] = {0.0f, 10.0f, 0.0f, 1.0f};
    GLfloat light3_direction [] = {0.0f, 0.8f,-0.0f};
    glLightfv(GL_LIGHT3,GL_AMBIENT,ambient3);
    glLightfv(GL_LIGHT3,GL_DIFFUSE,diffuse3);
    glLightfv(GL_LIGHT3,GL_POSITION,light3_position);
    glLightfv(GL_LIGHT3,GL_SPOT_DIRECTION,light3_direction);
    glLighti(GL_LIGHT3,GL_SPOT_CUTOFF,70);
    glLighti(GL_LIGHT3,GL_SPOT_EXPONENT,10);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 8.0);;



    fire.draw();
    glPopMatrix();

    glDisable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(-18, 0, 4);
    tail.draw();
    glPopMatrix();

    glEnable(GL_LIGHT2);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
    glPopMatrix();
    //  glDisable(GL_LIGHT2);



    glPushMatrix();

    glTranslatef(2, 16, 22);
    glRotatef(100,0,0,1);
    glRotatef(45,-1,0,0);
    glRotatef(wings_rotation, 0, 0, 1);
    right_wing.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, 16, 22);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    glRotatef(-wings_rotation, 0, 0, 1);
    left_wing.draw();
    glPopMatrix();

    glPopMatrix();

}

void Dragon::animate()
{
    if (state == ON_THE_GROUND)
    {
        velocity = Vec(0, 0, 0);
    }
    else if (state == FLY_HOLD_POSITION)
    {
        if (rotate_backward)
        {
            velocity = Vec(0, 0, 10);
            wings_rotation -= 5;
        }
        else
        {
            velocity = Vec(0, 0, -10);
            wings_rotation += 10;
        }
        if (wings_rotation > max_rotation)
        {
            rotate_backward = true;
        }
        if (wings_rotation < min_rotation)
        {
            rotate_backward = false;
        }
        if (position.z > 50)
        {
            state = FLY_TOWARD_CASTLE;
        }
    }
    else if (state == FLY_TOWARD_CASTLE)
    {
        if (rotate_backward)
        {
            velocity = Vec(0, 0, 5);
            wings_rotation -= 5;
        }
        else
        {
            velocity = Vec(0, 0, -10);
            wings_rotation += 10;
        }
        if (wings_rotation > max_rotation)
        {
            rotate_backward = true;
        }
        if (wings_rotation < min_rotation)
        {
            rotate_backward = false;
        }
        position.x += 2;
        position.y += 2;
        rotation.z -= abs((float)(-45 - rotation.z)) * 0.1;
        if (position.x > 500 && position.y > 500)
        {
            state = FLY_AND_FIRE;
        }
    }
    else if (state == FLY_AND_FIRE)
    {
        if (rotate_backward)
        {
            velocity = Vec(0, 0, 5);
            wings_rotation -= 5;
        }
        else
        {
            velocity = Vec(0, 0, -10);
            wings_rotation += 10;
        }
        if (wings_rotation > max_rotation)
        {
            rotate_backward = true;
        }
        if (wings_rotation < min_rotation)
        {
            rotate_backward = false;
        }
        fire.start();
        body.display_mouth();
    }

    position.x += velocity.x * 0.1;
    position.y += velocity.y * 0.1;
    position.z += velocity.z * 0.1;

    body.animate();
    left_wing.animate();
    right_wing.animate();
    tail.animate();
    fire.animate();

    if (camera_focus) viewer->camera()->lookAt(position);
}

void Dragon::keyPressEvent(QKeyEvent* key, Viewer&)
{
    if (key->key() == Qt::Key_O)
    {
        state = FLY_HOLD_POSITION;
    }
    else if (key->key() == Qt::Key_P)
    {
        camera_focus = !camera_focus;
    }
}
