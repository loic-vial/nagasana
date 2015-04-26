#include <glew.h>
#include <utils.h>
#include <castle.h>
#include <glut.h>
#include <glcheck.h>



#include <iostream>
using qglviewer::Vec;
using namespace std;

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
    wall_burned = loadTexture("res/mur_burned.jpg");
    door_burned = loadTexture("res/door_burned.jpg");
    fire.init(v);
    burned= false;
}


void Castle::draw()
{


    if(burned)
    {
        wall_id = wall_burned;
        door_id =door_burned;
    }
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, wall_id);
    //GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //first tower
    glPushMatrix();
    if(black) glColor3ub(0,0,0);
    else  glColor3ub(255,255,255);
    glTranslatef(lenght/2.0, lenght/2.0,0);
    tower();
    glPopMatrix();


    //second tower
    glPushMatrix();
    //  glColor3ub(255,255,255);
    glTranslatef(-lenght/2.0, lenght/2.0,0);
    tower();
    glPopMatrix();


    //third tower
    glPushMatrix();
    //  glColor3ub(255,255,255);
    glTranslatef(-lenght/2.0, -lenght/2.0,0);
    tower();
    glPopMatrix();

    //fourth tower
    glPushMatrix();
    //  glColor3ub(255,255,255);
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

    glDisable(GL_TEXTURE_2D);

    //floor
    glPushMatrix();
    glTranslatef(0,0,hight);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, wall_id);
    // GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
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
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    if(burned)
    {
        /*   glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(lenght/2,hight,lenght/2);
    fire.draw();
    glPopMatrix();*/

        /*   glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(-lenght/2,hight,lenght/2);
    fire.draw();
    glPopMatrix();
*/
        glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(-lenght/2,hight,-lenght/2);
        fire.draw();
        glPopMatrix();

        glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(lenght/2,hight,-lenght/2);
        fire.draw();
        glPopMatrix();

        glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(lenght/4,0,-lenght/2-2);
        fire.draw();
        glPopMatrix();

        glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(-lenght/4,0,-lenght/2-2);
        fire.draw();
        glPopMatrix();
    }

}


void Castle::animate()
{
    if(burned)
    {
        glPushMatrix();
        fire.animate();
        glPopMatrix();
    }
}

void Castle::tower()
{
    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    GLUquadric* tower = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,wall_id);
    gluQuadricDrawStyle(tower,GLU_FILL);
   if(!black) { gluQuadricTexture(tower,GL_TRUE); }
   else gluQuadricTexture(tower,GL_FALSE);
    gluCylinder(tower,radius+3,radius,hight,10,10);
    glTranslatef(0, 0,hight);

    GLUquadric* top = gluNewQuadric();
    gluQuadricDrawStyle(top,GLU_FILL);
    if(!black) { gluQuadricTexture(top,GL_TRUE); }
    else gluQuadricTexture(top,GL_FALSE);

    gluDisk(top,0,radius,10,1);
    gluDeleteQuadric(tower);
    gluDeleteQuadric(top);
    glDisable(GL_TEXTURE_2D);
    glDisable((GL_BLEND));

}

void Castle::wall(GLuint id)
{
    //wall
    if(!black) { glEnable(GL_TEXTURE_2D);}
    else glDisable(GL_TEXTURE_2D);

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D, id);
    //GLCHECK(glBindTexture(GL_TEXTURE_2D, id));
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


    if(!black) { glEnable(GL_TEXTURE_2D);}
    else glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, wall_id);
    //  GLCHECK(glBindTexture(GL_TEXTURE_2D, wall_id));
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
    glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);

}
