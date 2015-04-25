#include <glew.h>
#include <utils.h>
#include <castle.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;

Castle::Castle(GLfloat l,GLfloat h, GLfloat r)
{
    lenght = l;
    hight = h;
    radius = r;
}

void Castle::init(Viewer& v)
{

    wall_id = loadTexture("res/mur.jpg");
    door_id = loadTexture("res/door.jpg");
}


void Castle::draw()
{

    glEnable(GL_TEXTURE_2D);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //first tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(lenght/2.0, lenght/2.0,0);
    tower();
    glPopMatrix();


    //second tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-lenght/2.0, lenght/2.0,0);
    tower();
    glPopMatrix();


    //third tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-lenght/2.0, -lenght/2.0,0);
    tower();
    glPopMatrix();

    //fourth tower
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(lenght/2.0, -lenght/2.0,0);
    tower();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(0,-lenght/2.0f,0);
    wall(door_id);
    glTranslatef(0,lenght,0);
    wall(wall_id);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,-lenght/2.0f,0);
    wall(wall_id);
    glTranslatef(0,lenght,0);
    wall(wall_id);
    glPopMatrix();



    //floor
    glPushMatrix();
    glTranslatef(0,0,hight);
    GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    GLfloat s0[] = {+lenght/2.0f, -lenght/2.0f, 0};
    GLfloat s1[] = {+lenght/2.0f, +lenght/2.0f, 0};
    GLfloat s2[] = {-lenght/2.0f, +lenght/2.0f, 0};
    GLfloat s3[] = {-lenght/2.0f, -lenght/2.0f, 0};

    glBegin(GL_QUADS);

    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2d(1, 1);  glVertex3fv(s0);
    glTexCoord2d(0, 1);   glVertex3fv(s1);
    glTexCoord2d(0, 0); glVertex3fv(s2);
    glTexCoord2d(1, 0);  glVertex3fv(s3);
    glPopMatrix();

    glEnd();


}


void Castle::animate()
{
}

void Castle::tower()
{
    GLUquadric* tower = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D,wall_id);
    gluQuadricDrawStyle(tower,GLU_FILL);
    gluQuadricTexture(tower,GL_TRUE);
    gluCylinder(tower,radius+3,radius,hight,20,20);
    glTranslatef(0, 0,hight);

    GLUquadric* top = gluNewQuadric();
    gluQuadricDrawStyle(top,GLU_FILL);
    gluQuadricTexture(top,GL_TRUE);
    gluDisk(top,0,radius,20,1);
    gluDeleteQuadric(tower);
    gluDeleteQuadric(top);

}

void Castle::wall(GLuint id)
{
    //wall
    GLCHECK(glBindTexture(GL_TEXTURE_2D, id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    GLfloat s0[] = {+lenght/2.0f, 0, 0};
    GLfloat s1[] = {+lenght/2.0f, 5, 0};
    GLfloat s2[] = {-lenght/2.0f, 5, 0};
    GLfloat s3[] = {-lenght/2.0f, 0, 0};
    GLfloat s4[] = {+lenght/2.0f, 0, hight};
    GLfloat s5[] = {+lenght/2.0f, 5, hight};
    GLfloat s6[] = {-lenght/2.0f, 5, hight};
    GLfloat s7[] = {-lenght/2.0f, 0, hight};


    glBegin(GL_QUADS);

    glNormal3f(0.0, 0.0, -1.0);
    glVertex3fv(s0);
    glVertex3fv(s1);
    glVertex3fv(s2);
    glVertex3fv(s3);


    // 0 4 7 3
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2d(1, 0); glVertex3fv(s0);
    glTexCoord2d(1, 1); glVertex3fv(s4);
    glTexCoord2d(0, 1); glVertex3fv(s7);
    glTexCoord2d(0, 0); glVertex3fv(s3);
    glDisable(GL_TEXTURE_2D);
    glEnd();

    GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glBegin(GL_QUADS);
    // 1 5 4 0
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3fv(s1);
    glVertex3fv(s5);
    glVertex3fv(s4);
    glVertex3fv(s0);
    // 2 6 5 1
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2d(1, 1); glVertex3fv(s2);
    glTexCoord2d(0, 1);glVertex3fv(s6);
    glTexCoord2d(0, 0); glVertex3fv(s5);
    glTexCoord2d(1, 0);glVertex3fv(s1);

    // 3 7 6 2
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3fv(s3);
    glVertex3fv(s7);
    glVertex3fv(s6);
    glVertex3fv(s2);

    // 4 5 6 7
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2d(1, 1); glVertex3fv(s4);
    glTexCoord2d(0, 1);glVertex3fv(s5);
    glTexCoord2d(0, 0);glVertex3fv(s6);
    glTexCoord2d(1, 0);glVertex3fv(s7);

    glEnd();


}
