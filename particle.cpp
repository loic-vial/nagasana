#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "particle.h"

Particle::Particle(qglviewer::Vec pos, qglviewer::Vec vel, double m, double r)
	: position(pos),
	velocity(vel),
	mass(m),
	radius(r)
{
	invMass = (m > 0 ? 1 / m : 0.0);
}

Particle::~Particle()
{
}


const qglviewer::Vec & Particle::getPosition() const
{
	return position;
}

const qglviewer::Vec & Particle::getVelocity() const
{
	return velocity;
}

double Particle::getMass() const
{
	return mass;
}

double Particle::getInvMass() const
{
	return invMass;
}

double Particle::getRadius() const
{
	return radius;
}

void Particle::setPosition(const qglviewer::Vec &pos)
{
	position = pos;
}

void Particle::setVelocity(const qglviewer::Vec &vel)
{	
	velocity = vel;
}

void Particle::incrPosition(const qglviewer::Vec &pos)
{
	position += pos;
}

void Particle::incrVelocity(const qglviewer::Vec &vel)
{
	velocity += vel;
}



void Particle::draw() const
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(radius, 12, 12);
	glPopMatrix();

}



std::ostream& operator<<(std::ostream& os, const Particle& p)
{
	os << "pos (" << p.getPosition() << "), vel (" << p.getVelocity() << ")";
	return os;
}

