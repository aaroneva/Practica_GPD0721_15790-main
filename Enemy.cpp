#include "Enemy.h"
#include "Window.h"
#include "Vector2.h"

void Enemy::Init(int x_, int y_)
{
	position.x = x_;
	position.y = y_;
	enemy.Load("Enemigo.png");
}
void Enemy::Draw()
{
	Window* window = Window::GetPtr();
	window->RenderTexture(&enemy, position.x, position.y);
}

void Enemy::Update(Vector2 playerPosition)
{
	Vector2 direction;
	direction = playerPosition - position;
	direction = direction.Unit() * 0.1;
	position = position + direction;
}