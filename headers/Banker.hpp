#pragma once
#include <array>
#include <iostream>
#include <cmath>
#include <random>
#include "Global.hpp"
#include "SacMan.hpp"

using namespace std;

class Banker
{
    int speed, x{}, y{};
public:
    /// șpârga, șmârga, șbungu, șmungu
    /// cand incep sa urmareasca sacu "ai-u" e ca se verifica cat ar fi distanta pana la sac daca ar lua o in fiecare din directiile posibile
    /// șpârga se plimba random mai incet ca ceilalti 0.5, cand e destul de apropiat fugareste cu 1.1 pt cateva secunde
    /// smarga isi alege cate un sfert din harta pe care sa-l patruleze pentru un nr de secunde, fugareste in apropiere
    /// sbungu isi alege un colt al hartii pana in care se duce, cand ajunge acolo isi alege altu, fugareste in apropiere
    /// smungu e cretin se plimba random nu fugareste
    /// clase derivate prin mostenire de la banker

    /*void UpdateG(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, SacMan &ig_SacMan, int &oppDir)
    {
        int r;
        if(sqrt(pow(abs(x + 2 - ig_SacMan.GetPosition().x), 2) + pow(abs(y - ig_SacMan.GetPosition().y), 2)) < 10)
        {
            r = rand() % 4;
            if(r == 0 && oppDir != 0)
            {
                x += 2;
                oppDir = 2;
            }
            if(r == 1 && oppDir != 1)
            {
                y += 2;
                oppDir = 3;
            }
            if(r == 2 && oppDir != 2)
            {
                x -= 2;
                oppDir = 0;
            }
            if(r == 3 && oppDir != 3)
            {
                y -= 2;
                oppDir = 1;
            }
        }
        /*else
        {
            //r = Chase(ig_level, ig_SacMan);
            switch(r)
            {
            case 0:
                x += 2;
                break;
            case 1:
                y += 2;
                break;
            case 2:
                x -= 2;
                break;
            case 3:
                y -= 2;
            default: ;
            }
        }
    }
    /*int Chase(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, SacMan &ig_SacMan) const
    {
        int dir = -1;
        double min = 1000.0;
        if(MapCollisions::CheckCollision(false, true, ig_level, ig_SacMan, x + 2, y) == false)
            if(min > sqrt(pow(abs(x + 2 - ig_SacMan.GetPosition().x), 2) + pow(abs(y - ig_SacMan.GetPosition().y), 2)))
            {
                min = sqrt(pow(abs(x + 2 - ig_SacMan.GetPosition().x), 2) + pow(abs(y - ig_SacMan.GetPosition().y), 2));
                dir = 0;
            }
        if(MapCollisions::CheckCollision(false, true, ig_level, ig_SacMan, x, y + 2) == false)
            if(min > sqrt(pow(abs(x- ig_SacMan.GetPosition().x), 2) + pow(abs(y + 2 - ig_SacMan.GetPosition().y), 2)))
            {
                min = sqrt(pow(abs(x - ig_SacMan.GetPosition().x), 2) + pow(abs(y + 2 - ig_SacMan.GetPosition().y), 2));
                dir = 1;
            }
        if(MapCollisions::CheckCollision(false, true, ig_level, ig_SacMan, x - 2, y) == false)
            if(min > sqrt(pow(abs(x - 2 - ig_SacMan.GetPosition().x), 2) + pow(abs(y - ig_SacMan.GetPosition().y), 2)))
            {
                min = sqrt(pow(abs(x - 2 - ig_SacMan.GetPosition().x), 2) + pow(abs(y - ig_SacMan.GetPosition().y), 2));
                dir = 2;
            }
        if(MapCollisions::CheckCollision(false, true, ig_level, ig_SacMan, x, y - 2) == false)
            if(min > sqrt(pow(abs(x - ig_SacMan.GetPosition().x), 2) + pow(abs(y - 2 - ig_SacMan.GetPosition().y), 2)))
            {
                dir = 3;
            }
        return dir;
    }
    */

    void SetPosition(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
    [[nodiscard]] sf::Vector2<int> GetPosition() const
    {
        return {x, y};
    }
    Banker()
    {
        speed = 2;
    }
    friend std::ostream& operator<<(std::ostream& stream, const Banker& G)
    {
        stream << "Speed: " << G.speed << '\n';
        return stream;
    }
    Banker& operator=(const Banker& G)
    = default;
    ~Banker() = default;
};