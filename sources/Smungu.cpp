#include "../headers/Smungu.hpp"

#include <iostream>

#include "../headers/BankerError.hpp"

void Smungu::ImplUpdate(Map &map, SacMan &ig_SacMan)
{
    if (GetPosition().x <= 2 * -CELL_SIZE || GetPosition().x >= (CELL_SIZE + 10) * MAP1_WIDTH
        || GetPosition().y <= 2 * -CELL_SIZE || GetPosition().y >= (CELL_SIZE + 10) * MAP1_HEIGHT)
        throw BankerError("Banker Out of Bounds!");
    GetOut();
    if(sqrt(pow(GetPosition().x - ig_SacMan.GetPosition().x, 2) + pow(GetPosition().y - ig_SacMan.GetPosition().y, 2)) <= 4 * CELL_SIZE
        && timerClock.getElapsedTime().asSeconds() > 7)
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
            if(timerClock.getElapsedTime().asSeconds() - elapsedTime < 6.0f)
            {
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

std::shared_ptr<Banker> Smungu::ImplClone() const
{
    return std::make_shared<Smungu>(*this);
}

Smungu::Smungu() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
    SetBody(static_cast<float>(CELL_SIZE) / 2, sf::Color::Green, static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
}

Smungu& Smungu::operator=(const Smungu& other)
{
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Smungu::Smungu(const Smungu &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime){}