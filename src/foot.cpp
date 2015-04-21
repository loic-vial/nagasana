#include <glew.h>
#include <utils.h>
#include <foot.h>
#include <glut.h>
#include <glcheck.h>

void Foot::init(Viewer &)
{
    foot_id = loadTexture("res/metal.jpg");
}

void Foot::draw()
{

    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, foot_id));
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
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glTexCoord2d(3, 4); glVertex3f(0, 1, 0);
    glTexCoord2d(3, 6); glVertex3f(0, 3, 5);
    glTexCoord2d(3, 3); glVertex3f(0, 0, 8);
    glTexCoord2d(3, 0); glVertex3f(0, -3, 5);
    glTexCoord2d(3, 2); glVertex3f(0, -1, 0);
    glEnd();

    //face du haut
    glBegin(GL_POLYGON);
    glNormal3f(1, 0, 0);
    glTexCoord2d(4, 2); glVertex3f(1, -1, 0);
    glTexCoord2d(2, 2); glVertex3f(1, 1, 0);
    glTexCoord2d(4, 6); glVertex3f(1, 3, 5);
    glTexCoord2d(4, 3); glVertex3f(1, 0, 8);
    glTexCoord2d(4, 0); glVertex3f(1, -3, 5);
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
    glTexCoord2d(1, 0); glVertex3f(1, 3, 5);
    glTexCoord2d(1, 0); glVertex3f(0, 3, 5);
    glTexCoord2d(1, 0); glVertex3f(0, 1, 0);
    glEnd();

    //2eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 1);
    glTexCoord2d(1, 0); glVertex3f(1, 3, 5);
    glTexCoord2d(1, 0); glVertex3f(1, 0, 8);
    glTexCoord2d(1, 0); glVertex3f(0, 0, 8);
    glTexCoord2d(1, 0); glVertex3f(0, 3, 5);
    glEnd();

    //3eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 1);
    glTexCoord2d(1, 0); glVertex3f(1, 0, 8);
    glTexCoord2d(1, 0); glVertex3f(1, -3, 5);
    glTexCoord2d(1, 0); glVertex3f(0, -3, 5);
    glTexCoord2d(1, 0); glVertex3f(0, 0, 8);
    glEnd();

    //4eme face
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, -1);
    glTexCoord2d(1, 0); glVertex3f(1, -3, 5);
    glTexCoord2d(1, 0); glVertex3f(1, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -1, 0);
    glTexCoord2d(1, 0); glVertex3f(0, -3, 5);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}



