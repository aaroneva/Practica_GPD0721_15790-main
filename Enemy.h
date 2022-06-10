#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Vector2.h"

class Enemy :
    public GameObject
{
private:
    Image enemy;
    float vel;

public:
    void Init(int x_, int y_);
    void Draw();  
    void Update(Vector2 playerPosition);
};

