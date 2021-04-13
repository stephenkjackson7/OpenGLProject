#ifndef _PYRAMID_H
#define _PYRAMID_H
#include "SceneObject.h"

class Pyramid : public SceneObject
{
public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();

private:
	Vector3 _position;

};

#endif