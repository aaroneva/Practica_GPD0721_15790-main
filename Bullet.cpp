#include "Bullet.h"
#include "Window.h"


void Bullet::Init(int _x, int _y)
{
	position.x = _x;
	position.y = _y;
	img.Load("Bala.png");
}

void Bullet::Draw()
{
	Window* window = Window::GetPtr();
	window->RenderTexture(&img, position.x, position.y);
}