#include <glew.h>
#include <utils.h>
#include <foot.h>
#include <glut.h>
#include <glcheck.h>

void Foot::init(Viewer &)
{
    foot_id = loadTexture("res/scale.jpg");
    black = false;
}

void Foot::draw()
{
    if(black) glDisable(GL_TEXTURE_2D);
    else glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, foot_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glPushMatrix();
    glTranslatef(0, 13.5, 17);
    glRotatef(120, -1, 0, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(10, 0, -1, 0);
    glEnable(GL_NORMALIZE);

    //face du bas
    glBegin(GL_POLYGON);
    glNormal3f(-1, 0, 0);
    glTexCoord2d(2, 0); glVertex3f(0, -1, 0);
    glTexCoord2d(4, 0); glVertex3f(0, 1, 0);
    glTexCoord2d(6, 5); glVertex3f(0, 3, 5);
    glTexCoord2d(3, 8); glVertex3f(0, 0, 8);
    glTexCoord2d(0, 5); glVertex3f(0, -3, 5);
    glTexCoord2d(2, 0); glVertex3f(0, -1, 0);
    glEnd();

    //face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(0.2, 0); glVertex3f(1, -1, 0);
    glTexCoord2d(0.7, 0); glVertex3f(1, 1, 0);
    glTexCoord2d(1, 0.6); glVertex3f(1, 3, 5);
    glTexCoord2d(0.5, 1); glVertex3f(1, 0, 8);
    glTexCoord2d(0, 0.6); glVertex3f(1, -3, 5);
    glTexCoord2d(0.2, 0); glVertex3f(1, -1, 0);
    glEnd();

    //face de la jointure
    glBegin(GL_POLYGON);
    glNormal3f(0,-1,0.0);
    glTexCoord2d(0,2); glVertex3f(1, -1, 0);
    glTexCoord2d(0,4); glVertex3f(1, 1, 0);
    glTexCoord2d(4,0); glVertex3f(0, 1, 0);
    glTexCoord2d(2,0); glVertex3f(0, -1, 0);
    glEnd();

    //1ere face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1,-1);
    glTexCoord2d(0, 2); glVertex3f(1, 1, 0);
    glTexCoord2d(0, 4); glVertex3f(1, 3, 5);
    glTexCoord2d(4, 0); glVertex3f(0, 3, 5);
    glTexCoord2d(2, 0); glVertex3f(0, 1, 0);
    glEnd();

    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 1);
    glTexCoord2d(0, 2); glVertex3f(1, 3, 5);
    glTexCoord2d(0, 4); glVertex3f(1, 0, 8);
    glTexCoord2d(4, 0); glVertex3f(0, 0, 8);
    glTexCoord2d(2, 0); glVertex3f(0, 3, 5);
    glEnd();

    //3eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 1);
    glTexCoord2d(0, 2); glVertex3f(1, 0, 8);
    glTexCoord2d(0, 4); glVertex3f(1, -3, 5);
    glTexCoord2d(4, 0); glVertex3f(0, -3, 5);
    glTexCoord2d(2, 0); glVertex3f(0, 0, 8);
    glEnd();

    //4eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, -1);
    glTexCoord2d(0, 2); glVertex3f(1, -3, 5);
    glTexCoord2d(0, 4); glVertex3f(1, -1, 0);
    glTexCoord2d(2, 0); glVertex3f(0, -1, 0);
    glTexCoord2d(4, 0); glVertex3f(0, -3, 5);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}



