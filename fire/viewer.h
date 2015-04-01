/*
 * Main GL viewer class, based on the QGLViewer library.
 * 
 * QGLViewer is a Qt-based viewer, which provides an OpenGL rendering
 * context and GUI event management.
 * The documentation of the QGLViewer library can be found at the following 
 * url: http://www.libqglviewer.com
 */

#ifndef _VIEWER_
#define _VIEWER_

#include <QGLViewer/qglviewer.h>
#include <list>

class Renderable;


class Viewer : public QGLViewer
{
	public :
	        
		Viewer();
		virtual ~Viewer();
		void addRenderable(Renderable *r);

	protected :
/* Scene methods */
		// List of the scene objects, to render, animate, ...
		std::list<Renderable *> renderableList;
		
		// Create the scene and initializes rendering parameters
		virtual void init();
		
		// Draw every objects of the scene
		virtual void draw();
		
		// Animate every objects of the scene
		virtual void animate();


/* Viewing parameters */
		bool toogleWireframe;
		bool toogleLight;

		// Handle keyboard events specifically
		virtual void keyPressEvent(QKeyEvent *e);

		// Handle keyboard events specifically
		virtual void mouseMoveEvent(QMouseEvent *e);
		
		// Draw every objects of the scene
		virtual QString helpString() const;
};

#endif

