#pragma once

#include <glut.h>
#include <qglviewer.h>
#include <list>

class Renderable;

class Viewer : public QGLViewer
{
public :
	        
	Viewer();
	virtual ~Viewer();
	void addRenderable(Renderable *r);

/* Scene methods */
protected :
	/// List of the scene objects, to render, animate, ...
    std::list<Renderable *> renderableList;
		
	/// Create the scene and initializes rendering parameters
	virtual void init();
		
	/// Draw every objects of the scene
	virtual void draw();
		
	/// Animate every objects of the scene
	virtual void animate();


/* Viewing parameters */
protected :
	bool toogleWireframe;
	bool toogleLight;

	/// Handle keyboard events specifically
	virtual void keyPressEvent(QKeyEvent *e);

	/// Handle keyboard events specifically
	virtual void mouseMoveEvent(QMouseEvent *e);
		
	/// Draw every objects of the scene
	virtual QString helpString() const;
};

