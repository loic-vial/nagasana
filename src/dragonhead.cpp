#include <glew.h>
#include <utils.h>
#include <dragonhead.h>
#include <glut.h>
#include <glcheck.h>
DragonHead::DragonHead():
    face(9,0,5.5,3.5)
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

   //oeil
   glPushMatrix();
   glColor3ub(255,255,255);
   glTranslatef(-2.2, 4.3,7.5);
   glRotatef(240, -1, 0, 0);
   glBindTexture(GL_TEXTURE_2D,eye_id);
   GLUquadric* params2 = gluNewQuadric();
   gluQuadricDrawStyle(params2,GLU_FILL);
   gluQuadricTexture(params2,GL_TRUE);
   gluSphere(params2,1.5,10,20);
   gluDeleteQuadric(params2);
   glPopMatrix();

   glPushMatrix();
   glColor3ub(255,255,255);
   glTranslatef(2.2, 4.3,7.5);
   glRotatef(240 ,-1, 0, 0);
   glBindTexture(GL_TEXTURE_2D,eye_id);
   GLUquadric* params = gluNewQuadric();
   gluQuadricDrawStyle(params,GLU_FILL);
   gluQuadricTexture(params,GL_TRUE);
   gluSphere(params,1.5,10,20);
   gluDeleteQuadric(params);
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();




    glPushMatrix();

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



    glEnable(GL_TEXTURE_2D);
    //GLCHECK(glBindTexture(GL_TEXTURE_2D, foot_id));
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glPushMatrix();

    glTranslatef(0, -5.5, 0);
    glRotatef(5, -1, 0, 0);
    glRotatef(90, 0, 0, 1);
    glEnable(GL_NORMALIZE);

    GLfloat begin = 4;
    GLfloat end = 8;

    glBegin(GL_POLYGON);
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glTexCoord2d(3, 4); glVertex3f(0, 1, 0);
    glTexCoord2d(3, 6); glVertex3f(0, begin, end);
    glTexCoord2d(3, 0); glVertex3f(0, -begin, end);
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(4, 2); glVertex3f(1, -1, 0);
    glTexCoord2d(2, 2); glVertex3f(1, 1, 0);
    glTexCoord2d(4, 6); glVertex3f(1, begin, end);
    glTexCoord2d(4, 0); glVertex3f(1, -begin, end);
    glTexCoord2d(4, 2); glVertex3f(1, -1, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3f(0,-1,0.0);
    glTexCoord2d(1, 0); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, 1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -1, 0);
    glEnd();

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

    glDisable(GL_TEXTURE_2D);

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

    glPopMatrix();
}

