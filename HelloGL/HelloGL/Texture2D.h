#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL utilities
#include "GL\freeglut.h" //freeglut library

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

private:
	GLuint _ID; //Texture ID
	int _width, _height;
};

#endif
