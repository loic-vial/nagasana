#include <dragontail.h>
#include <iostream>

using namespace std;
using qglviewer::Vec;

DragonTail::DragonTail()
{

}

void DragonTail::init(Viewer& viewer)
{
    qglviewer::Vec initPos = qglviewer::Vec(0.0, 0.0, 2.0);
    particles.push_back(new Particle(initPos, qglviewer::Vec(), 0.0, 0.25));

    qglviewer::Vec pos1 = initPos + qglviewer::Vec(0.0, 1, 0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0, -1.0, 0.0);
    particles.push_back(new Particle(pos1, vel1, 1, 0.25));

    springs.push_back(new Spring(particles[0], particles[1], 30, 0.5, 1));

    for (int i = 2 ; i < 9 ; i++)
    {
        qglviewer::Vec pos = particles[i - 1]->getPosition() + qglviewer::Vec(0.0, 1, 0.0);
        qglviewer::Vec vel = qglviewer::Vec(0.0, -1.0, 0.0);
        particles.push_back(new Particle(pos, vel, 1, 0.25));
        springs.push_back(new Spring(particles[i], particles[i-1], 30, 0.5, 1));
    }
}

void DragonTail::draw()
{
    glColor3f(1,0,0);
    std::vector<Particle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        (*itP)->draw();
    }

    glColor3f(1.0, 0.28, 0.0);
    glLineWidth(5.0);
    std::vector<Spring *>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS)
    {
        (*itS)->draw();
    }

}
void DragonTail::animate()
{
    std::map<const Particle*, qglviewer::Vec> forces;

    qglviewer::Vec gravity(0, 5, 0);

    std::vector<Particle*>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        Particle *p = *itP;
        forces[p] = gravity * p->getMass();
    }

    std::vector<Spring*>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS)
    {
        Spring* s = *itS;
        qglviewer::Vec f12 = s->getCurrentForce();
        forces[s->getParticle1()] += f12;
        forces[s->getParticle2()] -= f12;
    }

    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        Particle* p = *itP;
        if (p->getMass() == 0) continue;
        p->incrVelocity(0.1 * (forces[p] / p->getMass()));
    }

    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        Particle *p = *itP;
        p->incrPosition(0.1 * p->getVelocity());
    }
}
