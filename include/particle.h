#ifndef _PARTICLE_
#define _PARTICLE_

#include <QGLViewer/vec.h>
#include <iostream>

class Particle
{
private:
	qglviewer::Vec position;
	qglviewer::Vec velocity;
	double mass; 
	double invMass; // the inverse of the mass is also stored
	double radius;
	
public:
	Particle(qglviewer::Vec pos, qglviewer::Vec vel, double m, double r);
	virtual ~Particle();
	
	const qglviewer::Vec & getPosition() const;
	const qglviewer::Vec & getVelocity() const;
	double getMass() const;
	double getInvMass() const;
	double getRadius() const;

	void setPosition(const qglviewer::Vec &pos);
	void setVelocity(const qglviewer::Vec &vel);
	void incrPosition(const qglviewer::Vec &pos);	// position += pos
	void incrVelocity(const qglviewer::Vec &vel);	// velocity += vel
	
	void draw() const;
};

// output stream operator, as non-member
std::ostream& operator<<(std::ostream& os, const Particle& p);

#endif

