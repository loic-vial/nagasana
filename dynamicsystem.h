#ifndef _DYNAMIC_SYSTEM_H_
#define _DYNAMIC_SYSTEM_H_

#include <QGLViewer/vec.h>
#include <QGLViewer/manipulatedFrame.h>

#include <vector>

#include "spring.h"
#include "particle.h"
#include "renderable.h"

/*
 * This class represents a dynamic system made of particles
 * linked together with damped springs, within a medium with
 * gravity and viscosity.
 * Particles a represented by small spheres, with a radius and a mass.
 * The initial scene is composed of a fixed plane, a static particle
 * that can be controlled by the mouse, and a dynamic particle.
 */
class DynamicSystem : public Renderable
{

private:
	// system
	std::vector<Particle *> particles;
	std::vector<Spring *> springs;
	
	// System parameters (common)
	qglviewer::Vec defaultGravity;
	qglviewer::Vec gravity;		// gravity used in simulation
	double defaultMediumViscosity;
	double mediumViscosity;		// viscosity used in simulation
	double dt;			// time step
	bool handleCollisions;
	
	// Collisions parameters
	qglviewer::Vec groundPosition;
	qglviewer::Vec groundNormal;
	double rebound;	// 0 = pure absorption; 1 = pure elastic impact

	// Parameters shared by all particles
	double particleMass;
	double particleRadius;
	double distanceBetweenParticles;

	// Parameters shared by all springs
	double springStiffness;
	double springInitLength;
	double springDamping;

	// viewer related states
	bool toggleGravity;
	bool toggleViscosity;
	bool toggleCollisions;


public:
	DynamicSystem();	// TODO add general parameters (viscosity...)
	virtual ~DynamicSystem();

	// Position of the firt particle can be set through mouse movements
	const qglviewer::Vec &getFixedParticlePosition() const;
	void setFixedParticlePosition(const qglviewer::Vec &pos);

	// Activate/desactivate gravity during the simulation
	void setGravity(bool onOff);
	// Activate/desactivate viscosity during the simulation
	void setViscosity(bool onOff);
	// Activate/desactivate contacts during the simulation
	void setCollisionsDetection(bool onOff);

	// event response
	void keyPressEvent(QKeyEvent*, Viewer&);
	void mouseMoveEvent(QMouseEvent*, Viewer&);
	
private:
	// Reset the scene (remove all particles and springs)
	void clear();
	
	// Compute collision between a sphere and the fixed) ground
	void collisionParticleGround(Particle *p);

	void collisionParticleParticle(Particle *p1, Particle *p2);

	// Compute collision between a sphere and a moving plane
// 	static void collisionParticlePlane(Particle *p,
// 		qglviewer::Vec planePosition, Vec placeNormal, Vec planeVelocity,
// 		qglviewer::Vec planeInvMass, double rebound);

	// Compute collision between a sphere and a sphere
// 	void collisionSphereSphere(qglviewer::Vec& x1, Vec& v1, double r1, double invm1,
// 			qglviewer::Vec& x2, Vec& v2, double r2, double invm2,
// 			double rebound );

	void createSystemScene();
	void createTestCollisions();


// Renderable methods
public:
	// Init the particle-spring system
	void init(Viewer &);

	// Draw the particle-spring system
	void draw();

	// Update positions and velocities of dynamic objects
	void animate();
};

#endif

