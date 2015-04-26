#include <dragontail.h>
#include <iostream>
#include <utils.h>

using namespace std;
using qglviewer::Vec;

DragonTail::DragonTail()
{

}

void DragonTail::init(Viewer&)
{
    particles.push_back(new Sphere(2, Vec(17, 0, 6), Vec(0, 0, 0), 0));

    for (int i = 1 ; i < 9 ; i++)
    {
        particles.push_back(new Sphere(2-(0.2*i), particles[i - 1]->getPosition() + Vec(0, -6, 0), Vec(i/2, -1, i/3), 1));
        springs.push_back(new Spring(particles[i],  particles[i-1], 30, 6, 1));
    }
    scale_id = loadTexture("res/scale.jpg");
    black=false;
}

void DragonTail::draw()
{
    glPushMatrix();

    if(black) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4ub(0,0,0,200);
    }
        else  glColor3ub(255,255,255);

    vector<Sphere*>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        (*itP)->draw();
    }

    glPopMatrix();

    for (int i = 1 ; i < 9 ; i++)
    {
        glPushMatrix();


        glEnable((GL_TEXTURE_2D));
        glBindTexture(GL_TEXTURE_2D, scale_id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        GLUquadric* params = gluNewQuadric();
        gluQuadricDrawStyle(params,GLU_FILL);
        gluQuadricNormals(params, GLU_SMOOTH);
        if(!black) { gluQuadricTexture(params,GL_TRUE); }
        else gluQuadricTexture(params,GL_FALSE);
        renderCylinder(particles[i-1]->getPosition(), particles[i]->getPosition(),
                       particles[i-1]->radius, particles[i]->radius, 15, params);
        gluDeleteQuadric(params);

        glPopMatrix();
    }
}
void DragonTail::animate()
{
    map<const Particle*, Vec> forces;

    Vec gravity(0, -5, 0);

    vector<Sphere*>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        forces[*itP] = gravity * (*itP)->getMass();
    }

    std::vector<Spring*>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS)
    {
        Spring* s = *itS;
        Vec f12 = s->getCurrentForce();
        forces[s->getParticle1()] += f12;
        forces[s->getParticle2()] -= f12;
    }

    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        if ((*itP)->getMass() == 0) continue;
        (*itP)->incrVelocity(0.1 * (forces[*itP] / (*itP)->getMass()));
    }

    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        (*itP)->incrPosition(0.1 * (*itP)->getVelocity());
    }
}
