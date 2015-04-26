#include <glew.h>
#include <utils.h>
#include <dragonhead.h>
#include <glut.h>
#include <glcheck.h>
DragonHead::DragonHead():
    face(9,5.5,3.5)
{}

void DragonHead::display_mouth()
{
    mouth_displayed = true;
}

void DragonHead::init(Viewer&)
{
    eye_id = loadTexture("res/oeil.jpg");
    scale_id = loadTexture("res/scale.jpg");
    mouth_displayed = false;
    black=false;
}

void DragonHead::draw()
{

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, eye_id);
    //  GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    face.setId(scale_id);
    //oeil
    glPushMatrix();
    glTranslatef(-2.2, 4.3,7.5);
    eye();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2, 4.3,7.5);
    eye();
    glPopMatrix();

    glPushMatrix();
    face.draw();
    GLUquadric* nose = gluNewQuadric();
    gluQuadricDrawStyle(nose,GLU_FILL);
    if(!black) { gluQuadricTexture(nose,GL_TRUE); }
    else gluQuadricTexture(nose,GL_FALSE);
    gluSphere(nose,3.5,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0,9);
    GLUquadric* top = gluNewQuadric();
    gluQuadricDrawStyle(top,GLU_FILL);
    if(!black) { gluQuadricTexture(top,GL_TRUE); }
    else gluQuadricTexture(top,GL_FALSE);
    gluSphere(top,5.5,10,10);
    glPopMatrix();

    if (mouth_displayed)
    {
        glPushMatrix();
        mouth();
        glPopMatrix();
    }

    //oreille
    glPushMatrix();
    glTranslatef(2.5, 3.5, 12);
    glRotatef(-30, 0, 0, 1);
    ear();
    glPopMatrix();


    //oreille
    glPushMatrix();
    glTranslatef(-2.5, 3.5, 12);
    glRotatef(30, 0, 0, 1);
    ear();
    glPopMatrix();

}


void DragonHead::ear()
{


    glRotatef(90, -1, 0, 0);
    glRotatef(90, 0, 0, 1);
    glEnable(GL_NORMALIZE);
    GLfloat size = 1.8;
    GLfloat height =5;

    //face du bas
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glTexCoord2d(0, 0); glVertex3f(0, -size, 0);
    glTexCoord2d(0, 1); glVertex3f(0, size, 0);
    glTexCoord2d(0.5, 0.7); glVertex3f(0, 0, height);
    glTexCoord2d(0, 0); glVertex3f(0, -size, 0);
    glEnd();

    //face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(0,0,255);
    glTexCoord2d(0, 0); glVertex3f(1, -size, 0);
    glTexCoord2d(0, 1); glVertex3f(1, size, 0);
    glTexCoord2d(0.5, 0.7); glVertex3f(1, 0, height);
    glTexCoord2d(0, 0); glVertex3f(1, -size, 0);
    glEnd();

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,1,0.0);
    glTexCoord2d(0, 0); glVertex3f(1, -size, 0);
    glTexCoord2d(0, 1); glVertex3f(1, size, 0);
    glTexCoord2d(1, 1); glVertex3f(0, size, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -size, 0);
    glEnd();

    //1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,1);
    glTexCoord2d(0, 0); glVertex3f(1, size, 0);
    glTexCoord2d(0, 0.5); glVertex3f(1, 0, height);
    glTexCoord2d(0.5, 0.5); glVertex3f(0, 0, height);
    glTexCoord2d(0.5, 0); glVertex3f(0, size, 0);
    glEnd();



    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 1);
    glTexCoord2d(0, 0); glVertex3f(1, 0, height);
    glTexCoord2d(0, 0.5); glVertex3f(1, -size, 0);
    glTexCoord2d(0.5, 0.5); glVertex3f(0, -size, 0);
    glTexCoord2d(0.5, 0); glVertex3f(0, 0, height);
    glEnd();
}

void DragonHead::eye()
{
    glRotatef(240 ,-1, 0, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,eye_id);
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    if(!black) { gluQuadricTexture(params,GL_TRUE); }
    else gluQuadricTexture(params,GL_FALSE);
    gluSphere(params,1.5,10,10);
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(params);
}
void DragonHead::mouth()
{
    glEnable(GL_TEXTURE_2D);
    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    glBindTexture(GL_TEXTURE_2D, scale_id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTranslatef(0, -7, -1);
    glRotatef(25, -1, 0, 0);
    glRotatef(90, 0, 0, 1);
    glEnable(GL_NORMALIZE);

    GLfloat begin = 4;
    GLfloat end = 8;
    //face du bas
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0.3); glVertex3f(0, -1, 0);
    glTexCoord2d(1, 0.8); glVertex3f(0, 1, 0);
    glTexCoord2d(0, 1); glVertex3f(0, begin, end);
    glTexCoord2d(0, 0); glVertex3f(0, -begin, end);
    glTexCoord2d(1, 0.3); glVertex3f(0, -1, 0);
    glEnd();
    //face du haut
    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else glColor3ub(100,0,0);
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(1, 0.3); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0.8); glVertex3f(1, 1, 0);
    glTexCoord2d(0, 1); glVertex3f(1, begin, end);
    glTexCoord2d(0, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(1, 0.3); glVertex3f(1, -1, 0);
    glEnd();
    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,-1,0.0);
    glTexCoord2d(0, 0.3); glVertex3f(1, -1, 0);
    glTexCoord2d(0.3, 0.3); glVertex3f(1, 1, 0);
    glTexCoord2d(0, 0); glVertex3f(0, 1, 0);
    glTexCoord2d(0.3, 0); glVertex3f(0, -1, 0);
    glEnd();

    //1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glTexCoord2d(0, 0.7); glVertex3f(1, 1, 0);
    glTexCoord2d(0.2, 0.7); glVertex3f(1, begin, end);
    glTexCoord2d(0, 0); glVertex3f(0, begin, end);
    glTexCoord2d(0.2, 0); glVertex3f(0, 1, 0);
    glEnd();

    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glTexCoord2d(0, 0.2); glVertex3f(1, begin, end);
    glTexCoord2d(0.2, 0.2); glVertex3f(1, -begin, end);
    glTexCoord2d(0, 0); glVertex3f(0, 3, 5);
    glTexCoord2d(0.2, 0); glVertex3f(0, 3, 5);
    glEnd();

    //4eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, -1);
    glTexCoord2d(0, 0.7); glVertex3f(1, -begin, end);
    glTexCoord2d(0.2, 0.2); glVertex3f(1, -1, 0);
    glTexCoord2d(0, 0); glVertex3f(0, -1, 0);
    glTexCoord2d(0.2, 0); glVertex3f(0, -begin, end);
    glEnd();
}
