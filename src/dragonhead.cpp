#include <dragonhead.h>

DragonHead::DragonHead():
    face(9,0,5.5,3.5)
{}

void DragonHead::init(Viewer&)
{

}

void DragonHead::draw()
{
    glPushMatrix();
    glColor3ub(255,255,255);
    face.draw();
    glutSolidSphere(3.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0, 0,9);
    glutSolidSphere(5.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.2, 4.3,7.5);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-2.2, 4.3,7.5);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();


    glEnable(GL_TEXTURE_2D);
    //GLCHECK(glBindTexture(GL_TEXTURE_2D, foot_id));
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glPushMatrix();

    glTranslatef(0, -5.5, 0);
    glRotatef(5, -1, 0, 0);
    glRotatef(90, 0, 0, 1);
    glEnable(GL_NORMALIZE);

    GLfloat begin = 4;
    GLfloat end = 8;

    //face du bas
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glTexCoord2d(3, 4); glVertex3f(0, 1, 0);
    glTexCoord2d(3, 6); glVertex3f(0, begin, end);
    glTexCoord2d(3, 0); glVertex3f(0, -begin, end);
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glEnd();

    //face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(4, 2); glVertex3f(1, -1, 0);
    glTexCoord2d(2, 2); glVertex3f(1, 1, 0);
    glTexCoord2d(4, 6); glVertex3f(1, begin, end);
    glTexCoord2d(4, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(4, 2); glVertex3f(1, -1, 0);
    glEnd();

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,-1,0.0);
    glTexCoord2d(1, 0); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, 1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -1, 0);
    glEnd();

    //1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
    glTexCoord2d(1, 0); glVertex3f(1, begin, end);
    glTexCoord2d(1, 0); glVertex3f(0, begin, end);
    glTexCoord2d(1, 0); glVertex3f(0, 1, 0);
    glEnd();

    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glTexCoord2d(1, 0); glVertex3f(1, begin, end);
    glTexCoord2d(1, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(1, 0); glVertex3f(0, 3, 5);
    glTexCoord2d(1, 0); glVertex3f(0, 3, 5);
    glEnd();

    //4eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, -1);
    glTexCoord2d(1, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(1, 0); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -begin, end);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

