#include <dragonneck.h>
#include <utils.h>
using qglviewer::Vec;
using namespace std;
DragonNeck::DragonNeck():
    first_part(10,4,9),
    second_part(8,3,4),
    third_part(8,1.5,3),
    first_joint(4, Vec(0, 0, 0)),
    second_joint(3, Vec(0, 0, 15))
{}

void DragonNeck::init(Viewer&)
{
    scale_id = loadTexture("res/scalea.jpg");
    black=false;
}

void DragonNeck::draw()
{

    first_part.setId(scale_id);
    second_part.setId(scale_id);
    third_part.setId(scale_id);
    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    glPushMatrix();
    first_part.draw();
    glTranslatef(0,0,10);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scale_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* joint_first = gluNewQuadric();
    gluQuadricDrawStyle(joint_first,GLU_FILL);
    if(!black) { gluQuadricTexture(joint_first,GL_TRUE); }
    else gluQuadricTexture(joint_first,GL_FALSE);
    gluSphere(joint_first,4,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,11);
    glRotatef(20,1,0,0);
    second_part.draw();

    glTranslatef(0,0,8.3);
    GLUquadric* joint_second = gluNewQuadric();
    gluQuadricDrawStyle(joint_second,GLU_FILL);
    if(!black) { gluQuadricTexture(joint_second,GL_TRUE); }
    else gluQuadricTexture(joint_second,GL_FALSE);
    gluSphere(joint_second,3,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-2.5,20);
    glRotatef(-12,1,0,0);
    third_part.draw();
    glPopMatrix();

    gluDeleteQuadric(joint_second);
    gluDeleteQuadric(joint_first);
}


