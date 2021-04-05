#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void DrawPolygon();

};



