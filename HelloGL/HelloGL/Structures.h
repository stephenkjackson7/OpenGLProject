#pragma once
#ifndef _STRUCTURES_H
#define _STRUCTURES_H

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Vector4
{
	float x;
	float y;
	float z; 
	float w;
};

struct Lighting
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

struct Material
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
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
	Color* Normals;
	GLushort* Indices;
	int TexCoordCount, VertexCount, NormalCount, IndexCount;
};



#endif