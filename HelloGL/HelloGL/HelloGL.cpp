#include "HelloGL.h"
#include <iostream>

HelloGL::HelloGL(int argc, char* argv[])
{

	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		std::cout << "new cube created at " << cube[i] << std::endl;
	}

	camera = new Camera();
	{
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		//camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	}


	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
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
	gluPerspective(60, 1, 5, 500);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}
	glFlush(); //flushes scene drawn to graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
	}
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	// Move Up/Down
	if (key == 'w')
		camera->center.y -= 0.1f;
	if (key == 's')
		camera->center.y += 0.1f;

	//Zoom In/Out
	if (key == 'q')
		camera->eye.z -= 0.1f;
	if (key == 'e')
		camera->eye.z += 0.1f;
	
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
	for (int i = 0; i < 200; i++)
	{
		delete cube[i];
		cube[i] = nullptr;
		std::cout << "hi";
	}

}
