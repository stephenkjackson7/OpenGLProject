#pragma once
#include "Texture2D.h"
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



