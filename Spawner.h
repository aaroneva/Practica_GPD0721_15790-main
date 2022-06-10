#pragma once
#include "GameObject.h"
#include <vector>
#include "Enemy.h"

class Spawner
{
private:
	int widthScreen, heightScreen;
	double time;

public:

	std::vector <Enemy*> enemies;
	Spawner(int widthScreen, int heightScreen);
	void EnemySpawner(double deltaTime);
	void CreateEnemy();

};

