#include <glew.h>
#include <utils.h>
#include <dragonlegforward.h>
#include <glut.h>
#include <glcheck.h>

using qglviewer::Vec;
using namespace std;

DragonLegForward::DragonLegForward():
    first_part(15,2,3.5),
    second_part(13,1,2)
{

}

void DragonLegForward::init(Viewer&)
{
    scale_id = loadTexture("res/scale.jpg");
    black=false;
    debut_rotate=false;
    rotate =0;
}

void DragonLegForward::draw()
{
    first_part.setId(scale_id);
    second_part.setId(scale_id);

    glPushMatrix();

    if(black)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
    else  glColor3ub(255,255,255);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, scale_id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D,scale_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    GLUquadric* joint = gluNewQuadric();
    gluQuadricDrawStyle(joint,GLU_FILL);
    if(!black) { gluQuadricTexture(joint,GL_TRUE); }
    else gluQuadricTexture(joint,GL_FALSE);
    gluSphere(joint,3.5,10,10);

    first_part.draw();
    glTranslatef(0,0,15);
    gluSphere(joint,2,10,10);
    glPopMatrix();


    glPushMatrix();
    glRotatef(rotate,-1,0,0);
    glPushMatrix();
    glTranslatef(0,0,15);
    glRotatef(80,-1,0,0);
    second_part.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,12.6,17.2);
    gluSphere(joint,1,10,10);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPopMatrix();

    gluDeleteQuadric(joint);
}

void DragonLegForward::animate()
{

}
