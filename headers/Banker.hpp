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
    int speed, x{}, y{}, targetx{}, targety{};
    bool useDoor = true;
public:
    /// șpârga, șmârga, șbungu, șmungu
    /// cand incep sa urmareasca sacu "ai-u" e ca se verifica cat ar fi distanta pana la sac daca ar lua o in fiecare din directiile posibile
    /// șpârga se plimba random mai incet ca ceilalti 0.5, cand e destul de apropiat fugareste cu 1.1 pt cateva secunde
    /// smarga isi alege cate un sfert din harta pe care sa-l patruleze pentru un nr de secunde, fugareste in apropiere
    /// sbungu isi alege un colt al hartii pana in care se duce, cand ajunge acolo isi alege altu, fugareste in apropiere
    /// smungu se plimba random nu fugareste
    /// clase derivate prin mostenire de la banker

    void GetOut()
    {
        if(useDoor == true)
        {
            targetx = x;
            targety = y - 2 * CELL_SIZE;
            useDoor = false;
        }
    }
    void SetPosition(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
    [[nodiscard]] sf::Vector2<int> GetPosition() const
    {
        return {x, y};
    }
    [[nodiscard]] sf::Vector2<int> GetTarget() const
    {
        return {targetx, targety};
    }
    void SetTarget(const int _x, const int _y)
    {
        targetx = _x;
        targety = _y;
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
    Banker& operator=(const Banker& other)
    {
        speed = other.speed;
        x = other.x;
        y = other.y;
        return *this;
    }
    ~Banker() = default;
};