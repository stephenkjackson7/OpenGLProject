#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	DrawPolygon();
	glFlush(); //flushes scene drawn to graphics card
}

void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.1, 0.1);
		glVertex2f(0.1, 0.1);
		glVertex2f(0.3, -0.1);
		glVertex2f(0.3, -0.3);
		glVertex2f(0.1, -0.5);
		glVertex2f(-0.1, -0.5);
		glVertex2f(-0.3, -0.3);
		glVertex2f(-0.3, -0.1);
	}
	glEnd();

	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //colours polygon
		glVertex2f(-0.9, -0.5); //define the first point of the polygon, bottom left
		glVertex2f(-0.72, -0.4); //next point, middle
		glVertex2f(-0.6, -0.5); //bottom right
	}
	glEnd(); //defines end of drawing polygon

	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f); //colours polygon
		glVertex2f(0.70, 0.5); //define the first point of the polygon, bottom left
		glVertex2f(0.80, 0.8); //next point, top right
		glVertex2f(0.90, 0.5); //bottom right
	}
	glEnd(); //defines end of drawing polygon

	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f); //colours polygon
		glVertex2f(0.2, 0.3); //define the first point of the polygon, top left
		glVertex2f(0.3, 0.4); //next point, top right
		glVertex2f(0.4, 0.3); //bottom right
	}
	glEnd(); //defines end of drawing polygon
	
}

HelloGL::~HelloGL(void)
{

}

