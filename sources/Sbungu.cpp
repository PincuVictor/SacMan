#include "../headers/Sbungu.hpp"

#include <iostream>

#include "../headers/BankerError.hpp"

void Sbungu::ImplUpdate(Map &map, SacMan &ig_SacMan)
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
            dir = Chase(map, dir);
        }
        else
            SetTarget(-1, -1);
    }
}

std::shared_ptr<Banker> Sbungu::ImplClone() const
{
    return std::make_shared<Sbungu>(*this);
}

Sbungu::Sbungu() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
    SetBody(static_cast<float>(CELL_SIZE) / 2, sf::Color::Red, static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
}

Sbungu& Sbungu::operator=(const Sbungu& other)
{
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Sbungu::Sbungu(const Sbungu &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime){}