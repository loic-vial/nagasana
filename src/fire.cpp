#include <cmath>
#include <iostream>
#include <map>
#include <viewer.h>
#include <fire.h>

Fire::~Fire()
{
    clear();
}

void Fire::init(Viewer&)
{
    started = false;
    toggleGravity = true;
    toggleViscosity = true;
    clear();

    //Centre de la sphère de départ du placement des particules
    initPos = qglviewer::Vec(0.0, 0.0, 0.0);
    r = 1.0;

    //Nombre de particules
    nbParticules = 10000;
    particleMass = 1.0;
    particleRadius = 0.1;
    // global scene parameters
    defaultGravity = qglviewer::Vec(0.0, 0.0, -0.001);
    gravity = defaultGravity;
    defaultMediumViscosity = 0.01;
    mediumViscosity = defaultMediumViscosity;
    handleCollisions = true;
    dt = 0.1;


    createSystemScene();
}

void Fire::createSystemScene()
{
    for(int i = 1; i<nbParticules; i++){
        float theta = M_PI * myRand(0,2);
        float phi = M_PI * myRand(0,1);
        qglviewer::Vec pos = initPos + qglviewer::Vec(r*cos(theta)*cos(phi), r*sin(theta)*cos(phi), r*sin(phi));
        qglviewer::Vec vel = qglviewer::Vec(1.5*cos(theta)*cos(phi), myRand(2,5), 1.5*sin(phi));	// non null initial velocity
        particles.push_back(new FireParticle(pos, vel, particleMass, particleRadius, myRand(20,50),1,myRand(0,0.001),0));
    }
}


void Fire::draw()
{

    if (started)
    {
        glPushMatrix();
        glColor3f(1,0,0);
        glRotatef(90,0,1,0);
        std::vector<FireParticle *>::iterator itP;
        for (itP = particles.begin(); itP != particles.end(); ++itP) {

            (*itP)->draw();
        }
        glPopMatrix();
    }
}

void Fire::animate()
{
    if (started)
    {
        std::map<const FireParticle *, qglviewer::Vec> forces;

        std::vector<FireParticle *>::iterator itP;
        for (itP = particles.begin(); itP != particles.end(); ++itP)
        {
            FireParticle *p = *itP;
            forces[p] = gravity * p->getMass() - mediumViscosity * p->getVelocity();
        }

        for (itP = particles.begin(); itP != particles.end(); ++itP)
        {
            FireParticle *p = *itP;
            // x' = x' + dt * x''
            if(p->getMass() != 0.0)
                p->incrVelocity(dt * forces[p] / p->getMass());
        }

        for (itP = particles.begin(); itP != particles.end(); ++itP)
        {
            FireParticle *p = *itP;
            // q = q + dt * v
            p->incrLife(-1);
        }

        for (itP = particles.begin(); itP != particles.end(); ++itP)
        {
            FireParticle *p = *itP;
            // q = q + dt * v
            if(p->life > 0)
            {
                p->incrPosition(dt * p->getVelocity());
            }
            else
            {
                float theta = M_PI * myRand(0,2);
                float phi = M_PI * myRand(0,1);
                qglviewer::Vec pos = initPos + qglviewer::Vec(r*cos(theta)*cos(phi), r*sin(theta)*cos(phi), r*sin(phi));
                p->setPosition(pos);
                p->setLife(myRand(20,50));
                p->red = 1; p->green = myRand(0,0.01); p->blue = 0;
            }
        }
    }
}

void Fire::clear()
{
    std::vector<FireParticle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        delete(*itP);
    }
    particles.clear();
}

void Fire::start()
{
    started = true;
}

void Fire::stop()
{
    started = false;
}

double Fire::myRand(double min, double max)
{
    return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}
