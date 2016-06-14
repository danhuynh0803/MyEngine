#include <gl\glew.h>
#include <cassert>
#include "MyGlWindow.h"
#include <Math\Vector2D.h>
#include <Qt\qdebug.h>

using Math::Vector2D;

namespace
{
	// Create triangle information using vector2D struct
	static Vector2D verts[] =
	{
		Vector2D(+0.0f, +0.1f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(+0.1f, -0.1f),
	};

	// Calculates total number of vertices within verts[] using the memory size
	static const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	
	// Ship's final position
	Vector2D shipPosition(0.0f, 0.0f);
}
void MyGlWindow::initializeGL()
{
	GLenum errorCode = glewInit();  // glewInit returns an error code. We expect it to return 0 if there are no errors
	assert(errorCode == 0);

	// Make a buffer on gpu for vertices
	glGenBuffers(1, &vertexBufferID);   
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	// Associate RAM with that buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);

	// Game loop using QTimers
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void MyGlWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);	

	Vector2D translatedVerts[NUM_VERTS];
	for (unsigned int i = 0; i < NUM_VERTS; ++i)
	{
		translatedVerts[i] = verts[i] + shipPosition;
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

int debugInt = 1; 
void MyGlWindow::myUpdate()
{
	if (debugInt++ % 20 == 0)
		for (int i = 0; i < 1000; ++i)
			qDebug() << "";
			
	Vector2D velocity(0.001f, 0.001f);
	shipPosition = shipPosition + velocity;
	repaint();
}

void MyGlWindow::keyPressEvent(QKeyEvent* e)
{

}