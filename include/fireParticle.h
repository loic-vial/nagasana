#pragma once

#include <QGLViewer/vec.h>
#include <iostream>

class FireParticle
{
private:
	qglviewer::Vec position;
	qglviewer::Vec velocity;
	double mass; 
	double invMass; // the inverse of the mass is also stored
	double size;
	
public:
	FireParticle(qglviewer::Vec pos, qglviewer::Vec vel, double m, double r, double l, double rd, double gr, double bl);
	virtual ~FireParticle();
	
	const qglviewer::Vec & getPosition() const;
	const qglviewer::Vec & getVelocity() const;
	double getMass() const;
	double getInvMass() const;
	double getRadius() const;

	double life;
	double red, green, blue;

	void setPosition(const qglviewer::Vec &pos);
	void setVelocity(const qglviewer::Vec &vel);
	void incrPosition(const qglviewer::Vec &pos);	// position += pos
	void incrVelocity(const qglviewer::Vec &vel);	// velocity += vel
	void incrLife(int cste);                        // life += cste
	void setLife(int cste);                         // life = cste
	
	void draw() const;
};

// output stream operator, as non-member
std::ostream& operator<<(std::ostream& os, const FireParticle& p);

