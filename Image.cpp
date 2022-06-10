#include "Image.h"
#include "Window.h"


void Image::Load(std::string path)
{
	Window* window = Window::GetPtr();
	SDL_Surface* img = IMG_Load(path.c_str());
	image = SDL_CreateTextureFromSurface(window->GetCanvas(), img);
	SDL_free(img);
	SDL_QueryTexture(image, NULL, NULL, &width, &height);
}

int Image::GetWidth()
{
	return width;
}

int Image::GetHeight()
{
	return height;
}

int Image::GetX()
{
	return x;
}

int Image::GetY()
{
	return y;
}

void Image::SetX(int x)
{
	this->x = x;
}

void Image::SetY(int _y)
{
	y = _y;
}

SDL_Texture* Image::GetTexture()
{
	return image;
}
