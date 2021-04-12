#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#define REFRESHRATE 16 // 1000ms / 60 (fps) = 16

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void Update();
	void DrawPolygon();
	void Keyboard(unsigned char key, int x, int y);
	
private:
	float rotation;
	Camera* camera;
};



