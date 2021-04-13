#pragma once
#ifndef _CUBE_H
#define _CUBE_H
#include "SceneObject.h"

class Cube : public SceneObject
{
public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();

private:
	Vector3 _position;
	GLfloat _rotation;
	
};

#endif
