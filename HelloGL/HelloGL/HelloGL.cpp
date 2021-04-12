#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	{
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	}

	rotation = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Set viewport to be entire window
	glViewport(0, 0, 800, 800);
	//Set correct perspective
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	DrawPolygon();
	glFlush(); //flushes scene drawn to graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	if (rotation >= 360.0f)
		rotation = 0.0f;

	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	// Move Up/Down
	if (key == 'w')
		camera->center.y -= 0.1f;
	if (key == 's')
		camera->center.y += 0.1f;

	//Rotate Left/Right
	if (key == 'a')
		rotation += 2.0f;
	if (key == 'd')
		rotation -= 2.0f;

	//Zoom In/Out
	if (key == 'q')
		camera->eye.z -= 0.1f;
	if (key == 'e')
		camera->eye.z += 0.1f;
	
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
		glutWireTeapot(0.2);
	glPopMatrix();

	/*
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
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
	glPopMatrix();
	*/
	

	/*glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //colours polygon
		glVertex2f(-0.9, -0.5); //define the first point of the polygon, bottom left
		glVertex2f(-0.72, -0.4); //next point, middle
		glVertex2f(-0.6, -0.5); //bottom right
	}
	glEnd(); //defines end of drawing polygon
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f); //colours polygon
		glVertex2f(0.70, 0.5); //define the first point of the polygon, bottom left
		glVertex2f(0.80, 0.8); //next point, top right
		glVertex2f(0.90, 0.5); //bottom right
	}
	glEnd(); //defines end of drawing polygon
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, -1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON); //starts to draw polygon
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f); //colours polygon
		glVertex2f(0.2, 0.3); //define the first point of the polygon, top left
		glVertex2f(0.3, 0.4); //next point, top right
		glVertex2f(0.4, 0.3); //bottom right
	}
	glEnd(); //defines end of drawing polygon
	glPopMatrix();
	*/
	
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}


