#include <glew.h>
#include <utils.h>
#include <dragonhead.h>
#include <glut.h>
#include <glcheck.h>
DragonHead::DragonHead():
    face(9,0,5.5,5)
{}

void DragonHead::init(Viewer&)
{
 eye_id = loadTexture("res/oeil.jpg");
}

void DragonHead::draw()
{
    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, eye_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glPushMatrix();



    glPushMatrix();
    glColor3ub(255,255,255);
    face.draw();
    glutSolidSphere(5, 20, 20);
    glPopMatrix();

    glPushMatrix();
      glColor3ub(255,255,255);
    glTranslatef(0, 0,9);
    glutSolidSphere(5.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.2, 4.3,7.5);
    // gluSphere(qObj, 1.5f, 24, 24);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-2.2, 4.3,7.5);
    glutSolidSphere(1.5, 20, 20);
    glPopMatrix();

    //oreille
    GLfloat size = 1.8;
    GLfloat height =5;
    glPushMatrix();

    glTranslatef(2.5, 3.5, 12);
    glRotatef(90, -1, 0, 0);
    glRotatef(110, 0, 0, 1);

    glRotatef(10, 0, 1, 0);
    glEnable(GL_NORMALIZE);

    //face du bas
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glTexCoord2d(3, 2); glVertex3f(0, -size, 0);
    glTexCoord2d(3, 4); glVertex3f(0, size, 0);
    glTexCoord2d(3, 3); glVertex3f(0, 0, height);
    glTexCoord2d(3, 2); glVertex3f(0, -size, 0);
    glEnd();

    //face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);

    glColor3ub(0,0,255);
    glTexCoord2d(4, 2); glVertex3f(1, -size, 0);
    glTexCoord2d(2, 2); glVertex3f(1, size, 0);
    glTexCoord2d(4, 3); glVertex3f(1, 0, height);
    glTexCoord2d(4, 2); glVertex3f(1, -size, 0);
    glEnd();

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,1,0.0);

    glColor3ub(255,255,255);
    glTexCoord2d(1, 0); glVertex3f(1, -size, 0);
    glTexCoord2d(1, 0); glVertex3f(1, size, 0);
    glTexCoord2d(1, 0); glVertex3f(0, size, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -size, 0);
    glEnd();

    //1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,1);
    glTexCoord2d(1, 0); glVertex3f(1, size, 0);
    glTexCoord2d(1, 0); glVertex3f(1, 0, height);
    glTexCoord2d(1, 0); glVertex3f(0, 0, height);
    glTexCoord2d(1, 0); glVertex3f(0, size, 0);
    glEnd();



    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 1);
    glTexCoord2d(1, 0); glVertex3f(1, 0, height);
    glTexCoord2d(1, 0); glVertex3f(1, -size, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -size, 0);
    glTexCoord2d(1, 0); glVertex3f(0, 0, height);
    glEnd();

    glPopMatrix();


    //oreille
        glPushMatrix();

        glTranslatef(-2.5, 3.5, 12);
        glRotatef(90, -1, 0, 0);
        glRotatef(70, 0, 0, 1);

        glRotatef(10, 0, 1, 0);
        glEnable(GL_NORMALIZE);

        //face du bas
        glBegin(GL_POLYGON);
        glNormal3f(-1, 0, 0);
        glTexCoord2d(3, 2); glVertex3f(0, -size, 0);
        glTexCoord2d(3, 4); glVertex3f(0, size, 0);
        glTexCoord2d(3, 3); glVertex3f(0, 0, height);
        glTexCoord2d(3, 2); glVertex3f(0, -size, 0);
        glEnd();

        //face du haut
        glBegin(GL_POLYGON);
        glNormal3f(1, 0, 0);

        glColor3ub(0,0,255);
        glTexCoord2d(4, 2); glVertex3f(1, -size, 0);
        glTexCoord2d(2, 2); glVertex3f(1, size, 0);
        glTexCoord2d(4, 3); glVertex3f(1, 0, height);
        glTexCoord2d(4, 2); glVertex3f(1, -size, 0);
        glEnd();

        //face de la jointure
        glBegin(GL_POLYGON);
        glNormal3f(0,1,0.0);

        glColor3ub(255,255,255);
        glTexCoord2d(1, 0); glVertex3f(1, -size, 0);
        glTexCoord2d(1, 0); glVertex3f(1, size, 0);
        glTexCoord2d(1, 0); glVertex3f(0, size, 0);
        glTexCoord2d(1, 0); glVertex3f(0, -size, 0);
        glEnd();

        //1ere face
        glBegin(GL_POLYGON);
        glNormal3f(0, 1,1);
        glTexCoord2d(1, 0); glVertex3f(1, size, 0);
        glTexCoord2d(1, 0); glVertex3f(1, 0, height);
        glTexCoord2d(1, 0); glVertex3f(0, 0, height);
        glTexCoord2d(1, 0); glVertex3f(0, size, 0);
        glEnd();



        //2eme face
        glBegin(GL_POLYGON);
        glNormal3f(0, -1, 1);
        glTexCoord2d(1, 0); glVertex3f(1, 0, height);
        glTexCoord2d(1, 0); glVertex3f(1, -size, 0);
        glTexCoord2d(1, 0); glVertex3f(0, -size, 0);
        glTexCoord2d(1, 0); glVertex3f(0, 0, height);
        glEnd();

        glPopMatrix();
}

