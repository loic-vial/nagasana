#include <glew.h>
#include <utils.h>
#include <dragonhead.h>
#include <glut.h>
#include <glcheck.h>
DragonHead::DragonHead():
    face(9,5.5,3.5)
{}

void DragonHead::init(Viewer&)
{
    eye_id = loadTexture("res/oeil.jpg");
    scale_id = loadTexture("res/scale.jpg");
}

void DragonHead::draw()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, eye_id);
    //  GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    face.setId(scale_id);
    //oeil
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-2.2, 4.3,7.5);
    eye();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.2, 4.3,7.5);
    eye();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    face.draw();
    GLUquadric* nose = gluNewQuadric();
    gluQuadricDrawStyle(nose,GLU_FILL);
    gluQuadricTexture(nose,GL_TRUE);
    gluSphere(nose,3.5,10,20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0, 0,9);
    GLUquadric* top = gluNewQuadric();
    gluQuadricDrawStyle(top,GLU_FILL);
    gluQuadricTexture(top,GL_TRUE);
    gluSphere(top,5.5,10,20);
    glPopMatrix();

    glPushMatrix();
    mouth();
    glPopMatrix();


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

    glColor3ub(255,255,255);
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

    glColor3ub(0,0,255);
    glTexCoord2d(0, 0); glVertex3f(1, -size, 0);
    glTexCoord2d(0, 1); glVertex3f(1, size, 0);
    glTexCoord2d(0.5, 0.7); glVertex3f(1, 0, height);
    glTexCoord2d(0, 0); glVertex3f(1, -size, 0);
    glEnd();

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,1,0.0);

    glColor3ub(255,255,255);
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
    gluQuadricTexture(params,GL_TRUE);
    gluSphere(params,1.5,10,20);
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(params);
}
void DragonHead::mouth()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, scale_id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glColor3ub(255,255,255);
    glTranslatef(0, -5.5, 0);
    glRotatef(5, -1, 0, 0);
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
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(1, 0.3); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0.8); glVertex3f(1, 1, 0);
    glTexCoord2d(0, 1); glVertex3f(1, begin, end);
    glTexCoord2d(0, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(1, 0.3); glVertex3f(1, -1, 0);
    glEnd();
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
