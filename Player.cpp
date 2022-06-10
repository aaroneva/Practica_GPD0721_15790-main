#include "Player.h"
#include "Window.h"
#include <iostream>
#include <math.h>


void Player::Init()
{
	position.x = 0;
	position.y = 0;
	player.Load("Jugador.png");
	forward.x = 0.0;
	forward.y = -1.0;
}

void Player::Draw(int mouseX,int mouseY)
{
	Vector2 mousePosition(mouseX, mouseY);
	mousePosition = mousePosition - position;
	mousePosition.Norm();
	forward.Norm();
	float angle = atan2(mousePosition.y - forward.y, mousePosition.x - forward.x)*180/3.1416;
	angle += 90;
	/*float direction;
	float denominador;
	direction = forward * mousePosition;
	denominador = forward.Norm() * mousePosition.Norm();
	float angle = SDL_acos(direction/denominador)*180; // arcos(A.B/|A||B|)
	std::cout << angle;*/
	Window* window = Window::GetPtr();
	window->RenderTexture(&player, position.x, position.y, angle);
}