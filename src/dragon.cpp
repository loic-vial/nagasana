#include <glew.h>
#include <dragon.h>
#include <viewer.h>
#include <iostream>
#include <utils.h>

using qglviewer::Vec;
using namespace std;

void Dragon::init(Viewer& v)
{
    black=false;
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
    GLfloat sol[3][3] = {{0.0f,0.0f,0.05f},
                         {4.0f,0.0f,0.05f},
                         {0.0f,4.0f,0.05f}};
    GLfloat ombre[4][4];
    GLfloat light_pos[] =  {20.0f, 100.0f, 100.0f, 0.0f};
    glPushMatrix();
    glEnable(GL_LIGHT0);
    draw_with_color(true);
    glPopMatrix();

    //on initialise la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Calcul de la matrice de projection sur le sol
    MakeShadowMatrix(sol,light_pos,ombre);
    glPushMatrix();
    glMultMatrixf((GLfloat *) ombre);
    //dessin de l'objet

    //on dessine le cube en noir transparent
    glPushMatrix();
       glDisable(GL_LIGHT0);
    draw_with_color(false);
    glPopMatrix();

    glPopMatrix();

    glDisable(GL_BLEND);

}

void Dragon::draw_with_color(bool color)
{

    body.black = !color;
    left_wing.black = !color;
    right_wing.black=!color;
    tail.black=!color;


    if(!black) { glEnable(GL_TEXTURE_2D);}
    else glDisable(GL_TEXTURE_2D);


    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);

    glPushMatrix();
    glTranslatef(0, 45,34);
    glRotatef(-55,1,0,0);

    if(color){
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
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 8.0);

    fire.draw();

    }
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
