#include <cmath>
#include <iostream>
#include <map>
#include <viewer.h>
#include <fire.h>


Fire::Fire()
    :
      defaultGravity(0.0, 0.0, -10.0),
      defaultMediumViscosity(1.0),
      dt(0.1)
{
    // default values reset in init()
}

Fire::~Fire()
{
    clear();
}


void Fire::clear()
{
    std::vector<FireParticle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        delete(*itP);
    }
    particles.clear();
}


void Fire::setGravity(bool onOff)
{
    gravity = (onOff ? defaultGravity : qglviewer::Vec());
}

void Fire::setViscosity(bool onOff)
{
    mediumViscosity = (onOff ? defaultMediumViscosity : 0.0);
}


///////////////////////////////////////////////////////////////////////////////
void Fire::init(Viewer&)
{
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


///////////////////////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////////////////////////////
void Fire::draw()
{
    // FireParticles
    glEnable(GL_LIGHT1);
    /*   GLfloat direction[]={1.0, -1.0, 1.0};
    GLfloat blanc[4] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, blanc);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);

    glLightfv(GL_LIGHT1,GL_POSITION,direction);
 glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,90);*/


    glColor3f(1,0,0);
    std::vector<FireParticle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        (*itP)->draw();
    }
}


///////////////////////////////////////////////////////////////////////////////
void Fire::animate()
{

    //======== 1. Compute all forces
    // map to accumulate the forces to apply on each particle
    std::map<const FireParticle *, qglviewer::Vec> forces;

    // weights and viscosity
    std::vector<FireParticle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        FireParticle *p = *itP;
        forces[p] = gravity * p->getMass() - mediumViscosity * p->getVelocity();
    }


    //======== 2. Integration scheme
    // update particles velocity (qu. 1)
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        FireParticle *p = *itP;
        // x' = x' + dt * x''
        if(p->getMass() != 0.0)
            p->incrVelocity(dt * forces[p] / p->getMass());
    }

    // update life
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        FireParticle *p = *itP;
        // q = q + dt * v
        p->incrLife(-1);
    }

    // update particles positions
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        FireParticle *p = *itP;
        // q = q + dt * v
        if(p->life > 0){
            p->incrPosition(dt * p->getVelocity());
        } else{
            float theta = M_PI * myRand(0,2);
            float phi = M_PI * myRand(0,1);
            qglviewer::Vec pos = initPos + qglviewer::Vec(r*cos(theta)*cos(phi), r*sin(theta)*cos(phi), r*sin(phi));
            p->setPosition(pos);
            p->setLife(myRand(20,50));
            p->red = 1; p->green = myRand(0,0.01); p->blue = 0;
        }
    }
}


void Fire::keyPressEvent(QKeyEvent* e, Viewer& viewer)
{
    // Get event modifiers key
    const Qt::KeyboardModifiers modifiers = e->modifiers();

    /* Controls added for Lab Session 6 "Physicall Modeling" */
    if ((e->key()==Qt::Key_G) && (modifiers==Qt::NoButton)) {
        toggleGravity = !toggleGravity;
        setGravity(toggleGravity);
        viewer.displayMessage("Set gravity to "
                              + (toggleGravity ? QString("true") : QString("false")));

    } else if ((e->key()==Qt::Key_V) && (modifiers==Qt::NoButton)) {
        toggleViscosity = !toggleViscosity;
        setViscosity(toggleViscosity);
        viewer.displayMessage("Set viscosity to "
                              + (toggleViscosity ? QString("true") : QString("false")));

    } else if ((e->key()==Qt::Key_Home) && (modifiers==Qt::NoButton)) {
        // stop the animation, and reinit the scene
        viewer.stopAnimation();
        init(viewer);
        toggleGravity = true;
        toggleViscosity = true;
    }
}	

double Fire::myRand(double min, double max)
{   return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}
