#include <glew.h>
#include <dragon.h>
#include <viewer.h>
#include <iostream>
#include <utils.h>

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

    viewer = &v;
}

void Dragon::draw()

{
    glEnable(GL_LIGHT0);

    glPushMatrix();
    //  glTranslatef(0, 44,38);
    //  glRotatef(-55,1,0,0);

    //lumiere
    glEnable(GL_LIGHT2);
    GLfloat ambient2[] = {0.15f,0.15f,0.15f,1.0f};
    GLfloat diffuse2[] = {1.0f,-0.29f,-0.4f,1.0f};
    GLfloat light2_position [] = {0.0f, 20.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT2,GL_AMBIENT,ambient2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,diffuse2);
    glLightfv(GL_LIGHT2,GL_POSITION,light2_position);


    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);

    glPushMatrix();
    glTranslatef(0, 45,34);
    glRotatef(-55,1,0,0);
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
    if (is_flying) glRotatef(wings_rotation, 0, 0, 1);
    //if (is_flying) glRotatef(rotation, 0, 1, 0);
    right_wing.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, 16, 22);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    if (is_flying) glRotatef(-wings_rotation, 0, 0, 1);
    //if (is_flying) glRotatef(-rotation, 0, 1, 0);
    left_wing.draw();
    glPopMatrix();

    glPopMatrix();

    glDisable(GL_LIGHT1);
}

void Dragon::animate()
{
    if (rotate_backward) wings_rotation -= 5;
    else wings_rotation += 10;
    if (wings_rotation > max_rotation) rotate_backward = true;
    if (wings_rotation < min_rotation) rotate_backward = false;
    if (is_flying)
    {
        if (position.x < 400 && position.y < 400)
        {
            position.x += 1.5;
            position.y += 1.5;
        }
        if (position.z < 60)
        {
            position.z += 0.5;
        }

        if (rotation.z > -45)
        {
            rotation.z -= 4;
        }
    }

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
        is_flying = !is_flying;
    }
    else if (key->key() == Qt::Key_P)
    {
        camera_focus = !camera_focus;
    }
}
