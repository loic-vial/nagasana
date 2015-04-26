#include <glew.h>
#include <utils.h>
#include <big_castle.h>
#include <glut.h>
#include <glcheck.h>
using qglviewer::Vec;

BigCastle::BigCastle():
    first(140,70,20),
    second(50,50,8)
{
}

void BigCastle::init(Viewer& v)
{

    first.init(v);
    second.init(v);
    first.black = false;
    second.black = false;
}


void BigCastle::draw()
{
   GLfloat sol[3][3] = {{0.0f,0.0f,0.05f},
                         {4.0f,0.0f,0.05f},
                         {0.0f,4.0f,0.05f}};
    GLfloat ombre[4][4];
    GLfloat light_pos[] =  {20.0f, 100.0f, 100.0f, 0.0f};
    glPushMatrix();
    glTranslatef(600,600,0);
    glRotatef(45,0,0,-1);
    first.black = false;
    first.draw();

    second.black = false;
    glTranslatef(0,0,70);
    second.draw();
    glPopMatrix();


    //on initialise la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Calcul de la matrice de projection sur le sol
    MakeShadowMatrix(sol,light_pos,ombre);
    glPushMatrix();
    glMultMatrixf((GLfloat *) ombre);
    //dessin de l'objet

    //on dessine le cube en noir transparent
    glPushMatrix();
    glTranslatef(600,600,0);
    glRotatef(45,0,0,-1);
    glColor4f(0,0,0,10);
    glDisable(GL_LIGHT0);
    first.black = true;
    first.draw();
    glTranslatef(0,0,70);
    second.black = true;
    second.draw();
    glPopMatrix();
    glPopMatrix();

    glDisable(GL_BLEND);



}


void BigCastle::animate()
{
    burned = false;
    if(burned)
    {

        first.burned = burned;
        second.burned = burned;
        first.animate();
        second.animate();
    }
}


