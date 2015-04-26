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
    velocity = Vec(0, 0, 0);
    viewer = &v;

    state = ON_THE_GROUND;
    delay_before_castle_burn = 30;
    delay_before_castle_burn2 = 60;
    delay_before_castle_burn3 = 90;
    delay_before_circleing_around = 100;
    angle_around_castle = 4;
}

void Dragon::set_castle_to_burn(BigCastle &castle)
{
    this->castle_to_burn = &castle;
}

void Dragon::draw()
{
<<<<<<< HEAD

    GLfloat    surf_diffuse[]={0.8,0.0,0.0,1.0};
    GLfloat surf_speculaire[]={0.5,0.5,0.5,1.0};
    GLfloat   surf_shininess[]={1.0};
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,surf_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK ,GL_SPECULAR,surf_speculaire);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,surf_shininess);



=======
>>>>>>> ed886fa7547877f84bb7d544cd37457557ec0c2c
    GLfloat sol[3][3] = {{0.0f,0.0f,0.05f},
                         {4.0f,0.0f,0.05f},
                         {0.0f,4.0f,0.05f}};
    GLfloat ombre[4][4];
    GLfloat light_pos[] =  {20.0f, 100.0f, 100.0f, 0.0f};

    glPushMatrix();

    glTranslatef(-1100, -1100, 0);
    glScalef(1.5, 1.5, 1.5);

    glPushMatrix();

    glEnable(GL_LIGHT0);
    draw_with_color(true);
    glPopMatrix();

    //on initialise la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Calcul de la matrice de projection sur le sol
    MakeShadowMatrix(sol,light_pos,ombre);

    glMultMatrixf((GLfloat *) ombre);
    //dessin de l'objet

    //on dessine le cube en noir transparent
    glPushMatrix();
    glDisable(GL_LIGHT0);
    draw_with_color(false);
    glPopMatrix();
    glEnable(GL_LIGHT0);
    glPopMatrix();

    glDisable(GL_BLEND);



}

void Dragon::draw_with_color(bool color)
{

    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);
    glScalef(2, 2, 2);


    body.black = !color;
    left_wing.black = !color;
    right_wing.black=!color;
    tail.black=!color;

    if(!color)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);


    if(color) { glEnable(GL_TEXTURE_2D);}
    else glDisable(GL_TEXTURE_2D);

    glPushMatrix();

    glPushMatrix();
    glTranslatef(0, 45,34);
    glRotatef(-55,1,0,0);
    if(color){
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


    }
    glPopMatrix();


    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glPushMatrix();
    glTranslatef(-18, 0, 4);
    tail.draw();
    glPopMatrix();



    if(state == FLY_AND_FIRE)
    {
        glEnable(GL_LIGHT2);
        body.is_fired = true;
    }
    else
    {
        glDisable(GL_LIGHT2);
        body.is_fired = false;
    }
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-1.8,1,0,0);
    body.draw();
    glPopMatrix();

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


//glDisable(GL_LIGHT2);
    if(color)
    { glPushMatrix();
        glTranslatef(0, 45,34);
       glRotatef(-55,1,0,0);

        glRotatef(90,0,1,0);
        glScalef(2, 4, 2);
        fire.draw();
        glPopMatrix();}

    glPopMatrix();


    if(state == FLY_AND_FIRE)
    {
        glEnable(GL_LIGHT3);
    }
    else
    {
        glDisable(GL_LIGHT3);
    }

}

void Dragon::animate()
{
    if (state == ON_THE_GROUND)
    {
        velocity = Vec(0, 0, 0);
    }
    else if (state == FLY_HOLD_POSITION)
    {
        body.debut_rotate = true;
        if (rotate_backward)
        {
            velocity = Vec(0, 0, 15);
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
        if (position.z > 120)
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
        if (delay_before_castle_burn-- < 0)
        {
            castle_to_burn->burn1();
        }
        if (delay_before_castle_burn2-- < 0)
        {
            castle_to_burn->burn2();
        }
        if (delay_before_castle_burn3-- < 0)
        {
            castle_to_burn->burn3();
        }
        if (delay_before_circleing_around-- < 0)
        {
            state = PLACE_FOR_ROUND;
        }
    }
    else if (state == PLACE_FOR_ROUND)
    {
        if (rotate_backward)
        {
            velocity = Vec(0, 0, 15);
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
        fire.stop();
        rotation.z -= abs(-135 - rotation.z) * 0.05;
        if (position.z > 200)
        {
            state = GET_AROUND_TOWN;
        }
    }
    else if (state == GET_AROUND_TOWN)
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
        fire.stop();
        angle_around_castle = angle_around_castle + 0.07;
        if (angle_around_castle > 2 * 3.14) angle_around_castle = 0;
        position.x = 700 + 300 * cos(angle_around_castle);
        position.y = 700 + 300 * sin(angle_around_castle);
        rotation.z = (angle_around_castle / 6.28) * 360;
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
