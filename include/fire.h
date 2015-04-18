#pragma once

#include <QGLViewer/vec.h>
#include <QGLViewer/manipulatedFrame.h>
#include <vector>
#include <fireParticle.h>
#include <renderable.h>

/*
 * This class represents a dynamic system made of particles
 * linked together with damped springs, within a medium with
 * gravity and viscosity.
 * FireParticles a represented by small spheres, with a radius and a mass.
 * The initial scene is composed of a fixed plane, a static particle
 * that can be controlled by the mouse, and a dynamic particle.
 */
class Fire : public Renderable
{

private:
	// particules (+ nombre)
	std::vector<FireParticle *> particles;
	int nbParticules;

	//Sphère d'apparition (centre + rayon)
	qglviewer::Vec initPos;
	float r;
	
	// System parameters (common)
	qglviewer::Vec defaultGravity;
	qglviewer::Vec gravity;		// gravity used in simulation
	double defaultMediumViscosity;
	double mediumViscosity;		// viscosity used in simulation
	double dt;			// time step
	bool handleCollisions;
	
	// Parameters shared by all particles
	double particleMass;
	double particleRadius;

	// viewer related states
	bool toggleGravity;
	bool toggleViscosity;


public:
	Fire();	// TODO add general parameters (viscosity...)
	virtual ~Fire();

	// Activate/desactivate gravity during the simulation
	void setGravity(bool onOff);
	// Activate/desactivate viscosity during the simulation
	void setViscosity(bool onOff);

	// event response
	void keyPressEvent(QKeyEvent*, Viewer&);

	//Utils
	double myRand(double min, double max);
	
private:
	// Reset the scene (remove all particles and springs)
	void clear();
	void createSystemScene();


// Renderable methods
public:
	// Init the particle-spring system
	void init(Viewer &);

	// Draw the particle-spring system
	void draw();

	// Update positions and velocities of dynamic objects
	void animate();
};
