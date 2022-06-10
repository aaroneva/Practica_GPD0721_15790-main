#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class Image
{
private:
	SDL_Texture* image;
	int width;
	int height;
	int x;
	int y;

public:
	void Load(std::string path);
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
	void SetX(int _x);
	void SetY(int _y);
	SDL_Texture* GetTexture();
};


