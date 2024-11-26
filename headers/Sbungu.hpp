#pragma once
#include "Map.hpp"
#include "Global.hpp"
#include "Banker.hpp"
#include <random>

class Sbungu : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    public:
    void Update(Map &map, SacMan &ig_SacMan) override
    {
        bool chasingSac = false;
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<short> dirR(0, 3);
        GetOut();
        if(sqrt(pow(GetPosition().x - ig_SacMan.GetPosition().x, 2) + pow(GetPosition().y - ig_SacMan.GetPosition().y, 2)) <= 4 * CELL_SIZE
            && timerClock.getElapsedTime().asSeconds() > 7)
        {
            chasingSac = true;
            SetTarget(ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y);
            if(elapsedTime == 0)
                elapsedTime = timerClock.getElapsedTime().asSeconds();
        }
        if(GetTarget().x == -1 && GetTarget().y == -1)
        {
            const int R = dirR(mt);
            if(R == 0)
                SetTarget(80, 40);
            if(R == 1)
                SetTarget(720, 40);
            if(R == 2)
                SetTarget(80, 760);
            if(R == 3)
                SetTarget(720, 760);
        }
        else
        {
            if(GetTarget().x != GetPosition().x || GetTarget().y != GetPosition().y)
            {
                if(timerClock.getElapsedTime().asSeconds() - elapsedTime >= 6.0f && chasingSac)
                {
                    timerClock.restart();
                    elapsedTime = 0;
                    SetTarget(-1, -1);
                }
                Chase(map);
            }
            else
                SetTarget(-1, -1);
        }
    }

    void Chase(Map &map) override
    {
        bool ways[4];
        int selected = 0;
        double dist = 20000000;
        ways[0] = map.CheckCollision(false, true, GetPosition().x - 2, GetPosition().y);
        ways[1] = map.CheckCollision(false, true, GetPosition().x + 2, GetPosition().y);
        ways[2] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y - 2);
        ways[3] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y + 2);
        if(ways[0] == false)
        {
            if(sqrt(pow(GetPosition().x - 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 1)
            {
                dist = sqrt(pow(GetPosition().x - 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
                selected = 0;
            }
        }
        if(ways[1] == false)
        {
            if(sqrt(pow(GetPosition().x + 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 0)
            {
                dist = sqrt(pow(GetPosition().x + 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
                selected = 1;
            }
        }
        if(ways[2] == false)
        {
            if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 2 - GetTarget().y, 2)) < dist && dir != 3)
            {
                dist = sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 2 - GetTarget().y, 2));
                selected = 2;
            }
        }
        if(ways[3] == false)
        {
            if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y + 2 - GetTarget().y, 2)) < dist && dir != 2)
            {
                selected = 3;
            }
        }
        dir = selected;
        switch (dir)
        {
        case 0:
            SetPosition(GetPosition().x - 2, GetPosition().y);
            break;
        case 1:
            SetPosition(GetPosition().x + 2, GetPosition().y);
            break;
        case 2:
            SetPosition(GetPosition().x, GetPosition().y - 2);
            break;
        case 3:
            SetPosition(GetPosition().x, GetPosition().y + 2);
            break;
        default: ;
        }
    }
};