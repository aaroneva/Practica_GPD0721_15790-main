#pragma once
#include "GameObject.h"
#include "Image.h"


class Player :public GameObject
{
private:
	Image player;
	

public:
	void Init();
	void Draw(int mouseX, int mouseY);
};