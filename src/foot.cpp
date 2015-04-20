#include <foot.h>
#include <glut.h>



void Foot::draw()
{
    glPushMatrix();
      glTranslatef(0,13.5,17);
      glRotatef(120,-1,0,0);
      glRotatef(90,0,0,1);
      glRotatef(10,0,-1,0);
      glEnable(GL_NORMALIZE);

      //face du bas
      glBegin(GL_POLYGON);
      glNormal3f(-1, 0,0.0);
      glVertex3f(0,-1,0);
      glVertex3f(0,1,0);
      glVertex3f(0,3,5);
      glVertex3f(0,0,8);
      glVertex3f(0,-3,5);
      glVertex3f(0,-1,0);
      glEnd();
      //face du haut
      glBegin(GL_POLYGON);
      glNormal3f(1, 0,0.0);
      glVertex3f(1,-1,0);
      glVertex3f(1,1,0);
      glVertex3f(1,3,5);
      glVertex3f(1,0,8);
      glVertex3f(1,-3,5);
      glVertex3f(1,-1,0);
      glEnd();
      //face de la jointure
      glBegin(GL_POLYGON);
      glNormal3f(0, -1,0.0);
      glVertex3f(1,-1,0);
      glVertex3f(1,1,0);
      glVertex3f(0,1,0);
      glVertex3f(0,-1,0);
      glEnd();
      //1ere face
      glBegin(GL_POLYGON);
      glNormal3f(0, 1,-1);
      glVertex3f(1,1,0);
      glVertex3f(1,3,5);
      glVertex3f(0,3,5);
      glVertex3f(0,1,0);
      glEnd();
      //2eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, 1,1);
      glVertex3f(1,3,5);
      glVertex3f(1,0,8);
      glVertex3f(0,0,8);
      glVertex3f(0,3,5);
      glEnd();

      //3eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, -1,1.0);
      glVertex3f(1,0,8);
      glVertex3f(1,-3,5);
      glVertex3f(0,-3,5);
      glVertex3f(0,0,8);
      glEnd();

      //4eme face
      glBegin(GL_POLYGON);
      glNormal3f(0, -1,-1.0);
      glVertex3f(1,-3,5);
      glVertex3f(1,-1,0);
      glVertex3f(0,-1,0);
      glVertex3f(0,-3,5);
      glEnd();
      glPopMatrix();
}



