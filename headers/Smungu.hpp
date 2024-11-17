#pragma once
#include "Banker.hpp"
#include "Map.hpp"
#include <random>

using namespace std;

class Smungu : public Banker
{
    int dir = 0;
    public:
    void Update(Map &map)
    {
        bool ways[4];
        int availableWays = 0;
        ways[0] = map.CheckCollision(false, false, GetPosition().x - 2, GetPosition().y);
        ways[1] = map.CheckCollision(false, false, GetPosition().x + 2, GetPosition().y);
        ways[2] = map.CheckCollision(false, false, GetPosition().x, GetPosition().y - 2);
        ways[3] = map.CheckCollision(false, false, GetPosition().x, GetPosition().y + 2);
        for(const bool way : ways)
            if(way == false)
                availableWays++;
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int8_t> dirR(0, 3);
        GetOut();
        if(GetTarget().x == -1 && GetTarget().y == -1)
        {
            bool selected = false;
            if(availableWays == 2)
            {
                if(dir == 0 && ways[0] == true && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 0 || dir == 1 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 1 && ways[1] == true && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 1 || dir == 0 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 2 && ways[2] == true && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 2 || dir == 3 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 3 && ways[3] == true && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 3 || dir == 2 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                switch (dir)
                {
                case 0:
                    if(ways[0] == false)
                        SetPosition(GetPosition().x - 2, GetPosition().y);
                    break;
                case 1:
                    if(ways[1] == false)
                        SetPosition(GetPosition().x + 2, GetPosition().y);
                    break;
                case 2:
                    if(ways[2] == false)
                        SetPosition(GetPosition().x, GetPosition().y - 2);
                    break;
                case 3:
                    if(ways[3] == false)
                        SetPosition(GetPosition().x, GetPosition().y + 2);
                    break;
                default: ;
                }
            }
            if(availableWays >= 3)
            {
                bool selected = false;
                if(dir == 0 && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 0 || dir == 1 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 1 && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 1 || dir == 0 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 2 && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 2 || dir == 3 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                if(dir == 3 && selected == false)
                {
                    dir = dirR(mt);
                    while(dir == 3 || dir == 2 || ways[dir] == true)
                        dir = dirR(mt);
                    selected = true;
                    cout << dir << endl;
                }
                switch (dir)
                {
                case 0:
                    if(ways[0] == false)
                        SetPosition(GetPosition().x - 2, GetPosition().y);
                    break;
                case 1:
                    if(ways[1] == false)
                        SetPosition(GetPosition().x + 2, GetPosition().y);
                    break;
                case 2:
                    if(ways[2] == false)
                        SetPosition(GetPosition().x, GetPosition().y - 2);
                    break;
                case 3:
                    if(ways[3] == false)
                        SetPosition(GetPosition().x, GetPosition().y + 2);
                    break;
                default: ;
                }
            }
        }
        else
        {
            if(GetTarget().x != GetPosition().x || GetTarget().y != GetPosition().y)
                SetPosition(GetPosition().x, GetPosition().y - 2);
            else
            {
                SetTarget(-1, -1);
            }
        }
    }
};