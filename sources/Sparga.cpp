#include "../headers/Sparga.hpp"

#include <iostream>

#include "../headers/BankerError.hpp"

void Sparga::ImplUpdate(Map &map, SacMan &ig_SacMan)
{
    SetSpeed(1);
    GetOut();
    if(sqrt(pow(GetPosition().x - ig_SacMan.GetPosition().x, 2) + pow(GetPosition().y - ig_SacMan.GetPosition().y, 2)) <= 9 * CELL_SIZE
        && timerClock.getElapsedTime().asSeconds() > 10)
    {
        SetTarget(ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y);
        if(elapsedTime == 0)
            elapsedTime = timerClock.getElapsedTime().asSeconds();
    }

    if(GetTarget().x == -1 && GetTarget().y == -1)
    {
        dir = RandomDirSelect(dir, map, 0, (MAP1_WIDTH - 1) * CELL_SIZE, 0, (MAP1_HEIGHT - 1) * CELL_SIZE);
    }
    else
    {
        if(GetTarget().x != GetPosition().x || GetTarget().y != GetPosition().y)
            if(timerClock.getElapsedTime().asSeconds() - elapsedTime < 2.0f)
            {
                SetPosition(GetPosition().x % 4 + GetPosition().x, GetPosition().y % 4 + GetPosition().y);
                SetSpeed(4);
                dir = Chase(map, dir);
            }
            else
            {
                timerClock.restart();
                elapsedTime = 0;
                SetTarget(-1, -1);
            }
        else
        {
            SetTarget(-1, -1);
        }
    }
}

std::shared_ptr<Banker> Sparga::ImplClone() const
{
    return std::make_shared<Sparga>(*this);
}

Sparga::Sparga() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
    SetSpeed(1);
    SetBody(static_cast<float>(CELL_SIZE) / 2, sf::Color::Cyan, static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
}

Sparga& Sparga::operator=(const Sparga& other)
{
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Sparga::Sparga(const Sparga &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime){}