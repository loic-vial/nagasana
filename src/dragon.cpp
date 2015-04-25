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

    max_rotation = 50;
    min_rotation = -10;
    rotation = 20;
    rotate_backward = true;
    is_flying = false;
    position = 0;
}

void Dragon::draw()
{
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); 	// Active l'éclairage
    glEnable(GL_LIGHT0);

    glTranslatef(0, 0, position);

    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-6, 16, 26);
    glRotatef(100,0,0,1);
    glRotatef(45,-1,0,0);
    if (is_flying) glRotatef(rotation, 0, 0, 1);
    if (is_flying) glRotatef(rotation, 0, 1, 0);
    right_wing.draw();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6, 16, 26);
    glRotatef(100,0,0,-1);
    glRotatef(45,-1,0,0);
    if (is_flying) glRotatef(-rotation, 0, 0, 1);
    if (is_flying) glRotatef(-rotation, 0, 1, 0);
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
    if (rotate_backward) rotation -= 5;
    else rotation += 10;
    if (rotation > max_rotation) rotate_backward = true;
    if (rotation < min_rotation) rotate_backward = false;
    if (is_flying) position += 2;

    body.animate();
    left_wing.animate();
    right_wing.animate();
    tail.animate();
    fire.animate();
}

void Dragon::keyPressEvent(QKeyEvent* key, Viewer&)
{
    if (key->key() == Qt::Key_Space)
    {
        is_flying = !is_flying;
    }
}
