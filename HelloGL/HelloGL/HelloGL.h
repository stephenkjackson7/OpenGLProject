#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "Defines.h"

class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	
private:
	Camera* camera;
	SceneObject* objects[1000];
};



