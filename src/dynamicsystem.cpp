#include <cmath>
#include <iostream>
#include <map>

#include "viewer.h"
#include "dynamicsystem.h"
/*

DynamicSystem::DynamicSystem()
	: 
	defaultGravity(0.0, 0.0, -10.0),
	defaultMediumViscosity(1.0),
	dt(0.1),
	groundPosition(0.0, 0.0, 0.0),
	groundNormal(0.0, 0.0, 1.0),
	rebound(0.5)
{
	// default values reset in init()
}

DynamicSystem::~DynamicSystem()
{
	clear();
}


void DynamicSystem::clear()
{
	std::vector<Particle *>::iterator itP;
	for (itP = particles.begin(); itP != particles.end(); ++itP) {
 		delete(*itP);
	}
	particles.clear();

	std::vector<Spring *>::iterator itS;
	for (itS = springs.begin(); itS != springs.end(); ++itS) {
 		delete(*itS);
	}
	springs.clear();
}

const qglviewer::Vec &DynamicSystem::getFixedParticlePosition() const
{
	return particles[0]->getPosition();	// no check on 0!
}

void DynamicSystem::setFixedParticlePosition(const qglviewer::Vec &pos)
{
	if (particles.size() > 0)
		particles[0]->setPosition(pos);
}

void DynamicSystem::setGravity(bool onOff)
{
	gravity = (onOff ? defaultGravity : qglviewer::Vec());
}

void DynamicSystem::setViscosity(bool onOff)
{
	mediumViscosity = (onOff ? defaultMediumViscosity : 0.0);
}

void DynamicSystem::setCollisionsDetection(bool onOff)
{
	handleCollisions = onOff;
}


///////////////////////////////////////////////////////////////////////////////
void DynamicSystem::init(Viewer &viewer)
{
	toggleGravity = true;
	toggleViscosity = true;
	toggleCollisions = true;
	clear();
	
	// global scene parameters 
	defaultGravity = qglviewer::Vec(0.0, 0.0, -10.0);
	gravity = defaultGravity;
	defaultMediumViscosity = 1.0;
	mediumViscosity = defaultMediumViscosity;
	handleCollisions = true;
	dt = 0.1;
	groundPosition = qglviewer::Vec(0.0, 0.0, 0.0);
	groundNormal = qglviewer::Vec(0.0, 0.0, 1.0);
    rebound = 0.5;
	// parameters shared by all particles
	particleMass = 1.0;
	particleRadius = 0.25;
	distanceBetweenParticles = 4.0 * particleRadius;
	// parameters shared by all springs
    springStiffness = 30.0;
    springInitLength = 0.5;
    springDamping = 1;

	createSystemScene();
	// or another method, e.g. to test collisions on simple cases...
// 	createTestCollisions();

	// add a manipulatedFrame to move particle 0 with the mouse
	viewer.setManipulatedFrame(new qglviewer::ManipulatedFrame());
	viewer.manipulatedFrame()->setPosition(getFixedParticlePosition());
	viewer.setSceneRadius(10.0f);

}


///////////////////////////////////////////////////////////////////////////////
void DynamicSystem::createSystemScene()
{
	// add a fixed particle
	qglviewer::Vec initPos = qglviewer::Vec(0.0, 0.0, 2.0);
	particles.push_back(new Particle(initPos, qglviewer::Vec(), 0.0, particleRadius));

	// add a second particle
	qglviewer::Vec pos1 = initPos + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
	qglviewer::Vec vel1 = qglviewer::Vec(0.0, -1.0, 0.0);	// non null initial velocity
	particles.push_back(new Particle(pos1, vel1, particleMass, particleRadius));
	
	// add a spring between the two particle
    springs.push_back(new Spring(particles[0], particles[1], springStiffness, springInitLength, springDamping));

    // then create a chain of particles
    for (int i = 2 ; i < 9 ; i++)
    {
        qglviewer::Vec pos = particles[i - 1]->getPosition() + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
        qglviewer::Vec vel = qglviewer::Vec(0.0, -1.0, 0.0);	// non null initial velocity
        particles.push_back(new Particle(pos, vel, particleMass, particleRadius));
        springs.push_back(new Spring(particles[i], particles[i-1], springStiffness, springInitLength, springDamping));
    }
}


///////////////////////////////////////////////////////////////////////////////
void DynamicSystem::draw()
{
	// Particles
	glColor3f(1,0,0);
	std::vector<Particle *>::iterator itP;
	for (itP = particles.begin(); itP != particles.end(); ++itP) {
		(*itP)->draw();
	}

	// Springs
	glColor3f(1.0, 0.28, 0.0);
	glLineWidth(5.0);
	std::vector<Spring *>::iterator itS;
	for (itS = springs.begin(); itS != springs.end(); ++itS) {
		(*itS)->draw();
	}

	// Ground :
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, -10.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f,  0.0f);
	glVertex3f( 10.0f, 10.0f,  0.0f);
	glVertex3f( 10.0f, -10.0f, 0.0f);
	glEnd();
}


///////////////////////////////////////////////////////////////////////////////
void DynamicSystem::animate()
{

//======== 1. Compute all forces
	// map to accumulate the forces to apply on each particle
	std::map<const Particle *, qglviewer::Vec> forces;

	// weights
	std::vector<Particle *>::iterator itP;
	for (itP = particles.begin(); itP != particles.end(); ++itP) {
		Particle *p = *itP;
		forces[p] = gravity * p->getMass();
	}

	// damped springs
	std::vector<Spring *>::iterator itS;
	for (itS = springs.begin(); itS != springs.end(); ++itS) {
		Spring *s = *itS;
		qglviewer::Vec f12 = s->getCurrentForce();
		forces[s->getParticle1()] += f12;
		forces[s->getParticle2()] -= f12; // opposite force
	}

    // viscosity of the medium
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        Particle *p = *itP;
        forces[p] += - mediumViscosity * p->getVelocity();
    }


//======== 2. Integration scheme
	// update particles velocity (qu. 1)
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        Particle *p = *itP;
        if (p->getMass() == 0) continue;
        p->incrVelocity(dt * (forces[p] / p->getMass()));
    }

	// update particles positions
	for (itP = particles.begin(); itP != particles.end(); ++itP) {
		Particle *p = *itP;
		// q = q + dt * v
		p->incrPosition(dt * p->getVelocity());
	}


//======== 3. Collisions
	if (handleCollisions) {
		//TO DO: discuss multi-collisions and order!
        for (itP = particles.begin(); itP != particles.end(); ++itP) {
            collisionParticleGround(*itP);
        }
        for(unsigned int i = 1; i < particles.size(); ++i) {
            Particle *p1 = particles[i - 1];
            Particle *p2 = particles[i];
            collisionParticleParticle(p1, p2);
        }
	}
}



void DynamicSystem::collisionParticleGround(Particle *p)
{
	// don't process fixed particles (ground plane is fixed)
	if (p->getInvMass() == 0)
		return;

	// particle-plane distance
	double penetration = (p->getPosition() - groundPosition) * groundNormal;
	penetration -= p->getRadius();
	if (penetration >= 0)
		return;

	// penetration velocity
	double vPen = p->getVelocity() * groundNormal;

	// updates position and velocity of the particle
	p->incrPosition(-penetration * groundNormal);
	p->incrVelocity(-(1 + rebound) * vPen * groundNormal);
}


void DynamicSystem::collisionParticleParticle(Particle *p1, Particle *p2)
{
    if (p1->getInvMass() == 0 || p2->getInvMass() == 0) return;

    double penetration = (p1->getRadius() + p2->getRadius()) - (p1->getPosition() - p2->getPosition()).norm();
    if (penetration <= 0) return;

    double v1Pen = p1->getVelocity() * (p2->getPosition() - p1->getPosition()).unit();
    p1->incrPosition((penetration / 2.0) * (p1->getPosition() - p2->getPosition()).unit());
    p1->incrVelocity((1 + rebound) * v1Pen * (p1->getPosition() - p2->getPosition()).unit());

    double v2Pen = p2->getVelocity() * (p1->getPosition() - p2->getPosition()).unit();
    p2->incrPosition((penetration / 2.0) * (p2->getPosition() - p1->getPosition()).unit());
    p2->incrVelocity((1 + rebound) * v2Pen * (p2->getPosition() - p1->getPosition()).unit());
}

void DynamicSystem::keyPressEvent(QKeyEvent* e, Viewer& viewer)
{
  	// Get event modifiers key
	const Qt::KeyboardModifiers modifiers = e->modifiers();

        // Controls added for Lab Session 6 "Physicall Modeling"
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

	} else if ((e->key()==Qt::Key_C) && (modifiers==Qt::NoButton)) {
		toggleCollisions = !toggleCollisions;
		setCollisionsDetection(toggleCollisions);
		viewer.displayMessage("Detects collisions "
			+ (toggleCollisions ? QString("true") : QString("false")));

	} else if ((e->key()==Qt::Key_Home) && (modifiers==Qt::NoButton)) {
		// stop the animation, and reinit the scene
		viewer.stopAnimation();
		init(viewer);
		viewer.manipulatedFrame()->setPosition(getFixedParticlePosition());
		toggleGravity = true;
		toggleViscosity = true;
		toggleCollisions = true;
	}
}	

void DynamicSystem::mouseMoveEvent(QMouseEvent*, Viewer& v)
{
        setFixedParticlePosition(v.manipulatedFrame()->position());
}
*/
