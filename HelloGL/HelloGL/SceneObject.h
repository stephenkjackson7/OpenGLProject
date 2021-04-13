#pragma once
#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{
public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

protected:
	Mesh* _mesh;
	Texture2D* _texture;
};

#endif


