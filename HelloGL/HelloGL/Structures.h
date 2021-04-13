#pragma once
#ifndef _STRUCTURES_H
#define _STRUCTURES_H

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

struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

struct Vertex
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct TexCoord
{
	GLfloat u;
	GLfloat v;
};

struct Mesh
{
	TexCoord* TexCoords;
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	int TexCoordCount, VertexCount, ColorCount, IndexCount;
};



#endif