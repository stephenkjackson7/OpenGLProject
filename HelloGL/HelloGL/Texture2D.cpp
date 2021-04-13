#include "Texture2D.h"
#include <iostream>
#include <fstream>
using namespace std;

Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
	
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData; int fileSize; ifstream inFile;
	_width = width; _height = height;
	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		cerr << "Can't open texture file " << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end); //seeks end of file
	fileSize = (int)inFile.tellg(); //gets current position to the end giving us total file size
	tempTextureData = new char [fileSize];
	inFile.seekg(0, ios::beg); //seek back to beggining of file
	inFile.read(tempTextureData, fileSize); //read in all data in one go
	inFile.close();

	cout << path << " loaded." << endl;

	glGenTextures(1, &_ID); //gets next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); //binds texture to the ID
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); //specify details of texture image
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	delete [] tempTextureData;
	return true;
}