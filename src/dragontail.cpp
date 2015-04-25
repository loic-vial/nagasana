#include <dragontail.h>
#include <iostream>

using namespace std;
using qglviewer::Vec;

DragonTail::DragonTail()
{

}

void DragonTail::init(Viewer&)
{
    particles.push_back(new Sphere(2, Vec(20, 0, 10), Vec(0, 0, 0), 0));

    for (int i = 1 ; i < 9 ; i++)
    {
        particles.push_back(new Sphere(2-(0.2*i), particles[i - 1]->getPosition() + Vec(0, -6, 0), Vec(0, -1, (i%2==0)?(i):(-i)), 1));
        springs.push_back(new Spring(particles[i],  particles[i-1], 30, 6, 1));
    }
}

void DragonTail::draw()
{
    glPushMatrix();

    glColor3f(1,0,0);
    vector<Sphere*>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        (*itP)->draw();
    }

    glPopMatrix();
/*
    glColor3f(1.0, 0.28, 0.0);
    glLineWidth(5.0);
    vector<Spring*>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS)
    {
        (*itS)->draw();
    }
*/

    for (int i = 1 ; i < 9 ; i++)
    {
        glPushMatrix();

        glTranslatef(particles[i-1]->getPosition().x,
                     particles[i-1]->getPosition().y,
                     particles[i-1]->getPosition().z);
        glRotatef(90, 1, 0, 0);

        glColor3f(1, 1, 1); // uniform white -> to be change to texture

        GLUquadric* params = gluNewQuadric();
        gluQuadricDrawStyle(params,GLU_FILL);
        gluQuadricTexture(params, GL_FALSE);
        gluCylinder(params, particles[i-1]->radius, particles[i]->radius, 10, 10, 10);
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
