#pragma once
#ifndef _CUBE_H
#define _CUBE_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <fstream>
#include "GL\freeglut.h"
#include "Structures.h"


class Cube
{
public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();

	static bool Load(char* path);

private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;

	Vector3 _position;
	GLfloat _rotation;
	GLfloat _spin;
};

#endif
