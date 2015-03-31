#include <dragontail.h>
#include <iostream>

using namespace std;
using qglviewer::Vec;

DragonTail::DragonTail()
{

}

void DragonTail::init(Viewer& viewer)
{
    particles.push_back(new Sphere(3, Vec(10, 0, 10), Vec(0, 0, 0), 0));

    for (int i = 1 ; i < 9 ; i++)
    {
        particles.push_back(new Sphere(3, particles[i - 1]->getPosition() + Vec(0, 6, 0), Vec(0, -1, (i%2==0)?(i):(-i)), 1));
        springs.push_back(new Spring(particles[i],  particles[i-1], 30, 6, 1));
    }
}

void DragonTail::draw()
{
    glColor3f(1,0,0);
    vector<Sphere*>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP)
    {
        (*itP)->draw();
    }

    glColor3f(1.0, 0.28, 0.0);
    glLineWidth(5.0);
    vector<Spring*>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS)
    {
        (*itS)->draw();
    }

}
void DragonTail::animate()
{
    map<const Particle*, Vec> forces;

    Vec gravity(0, 5, 0);

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
