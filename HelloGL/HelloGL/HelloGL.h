#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"

#define REFRESHRATE 16 // 1000ms / 60 (fps) = 16

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
	
private:
	Camera* camera;
	Cube* cube[200] = {};
};



