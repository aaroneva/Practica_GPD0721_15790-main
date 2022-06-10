#include <iostream>
#include "Window.h"
#include "Player.h"
#include <vector>
#include "Bullet.h"
#include "SDL.h"
#include "Enemy.h"
#include <chrono>
#include "Spawner.h"

int main(int argc, char* args[])
{
    Window* window = Window::GetPtr();
    window->Init();
    Player p1;
    p1.Init();
    int dirx;
    int diry;
    int mouseX;
    int mouseY;
    bool click = false;
    std::vector<Bullet> bullets;
    std::chrono::steady_clock clock;
    double deltaTime = 0;
    Spawner spawner(1280, 720);
    bool lastClick = false;

    while (true)
    {     
        auto start = clock.now();
        spawner.EnemySpawner(deltaTime);
        window->Clear();
        lastClick = click;
        window->Input(dirx, diry, click, mouseX, mouseY);
        if (diry > 0 && p1.position.y > -10)
        {
            p1.position.y -= 0.3;
        }
        else if (diry < 0 && p1.position.y < 630)
        {
            p1.position.y += 0.3;
        }
        if (dirx > 0 && p1.position.x < 1180)
        {
            p1.position.x += 0.3;
        }
        else if (dirx < 0 && p1.position.x > 0)
        {
            p1.position.x -= 0.3;
        }

        if (click && !lastClick)
        {
            Bullet newBullet;
            newBullet.Init(p1.position.x+45, p1.position.y);
            bullets.push_back(newBullet);
        }     

        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].Draw();
        }

        for (int i = 0; i < spawner.enemies.size(); i++)
        {
            spawner.enemies[i]->Draw();
        }

        for (int i = 0; i < spawner.enemies.size(); i++)
        {
            spawner.enemies[i]->Update(p1.position);
        }
        
        p1.Draw(mouseX, mouseY);
        window->Render();

        auto end = clock.now();  
        auto time_span = static_cast<std::chrono::duration<double>>(end - start);

        deltaTime = time_span.count();

    }

    return 0;
}

