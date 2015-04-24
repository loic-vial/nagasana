#include <glew.h>
#include <utils.h>
#include <castle.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;


void Castle::init(Viewer& v)
{

        wall_id = loadTexture("res/oeil.jpg");
}


void Castle::draw()
{

    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //first tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(80, 80,0);
    glBindTexture(GL_TEXTURE_2D,wall_id);
    GLUquadric* tower = gluNewQuadric();
    gluQuadricDrawStyle(tower,GLU_FILL);
    gluQuadricTexture(tower,GL_TRUE);
    gluCylinder(tower,21,20,70,20,20);
    glPopMatrix();


    //second tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-80, 80,0);
    glBindTexture(GL_TEXTURE_2D,wall_id);
    gluQuadricDrawStyle(tower,GLU_FILL);
    gluQuadricTexture(tower,GL_TRUE);
    gluCylinder(tower,21,20,70,20,20);
    glPopMatrix();


    //third tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-80, -80,0);
    glBindTexture(GL_TEXTURE_2D,wall_id);
    gluQuadricDrawStyle(tower,GLU_FILL);
    gluQuadricTexture(tower,GL_TRUE);
    gluCylinder(tower,21,20,70,20,20);
    glPopMatrix();

    //fourth tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(80, -80,0);
    glBindTexture(GL_TEXTURE_2D,wall_id);
    gluQuadricDrawStyle(tower,GLU_FILL);
    gluQuadricTexture(tower,GL_TRUE);
    gluCylinder(tower,21,20,70,20,20);
    glPopMatrix();

    //wall

     gluDeleteQuadric(tower);
}


void Castle::animate()
{
}

