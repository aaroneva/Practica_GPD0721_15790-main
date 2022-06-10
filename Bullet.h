#pragma once
#include "GameObject.h"
#include "Image.h"


class Bullet :
	public GameObject
{
private:
	Image img;

public:
	void Init(int _x, int _y);
	void Draw();
};
