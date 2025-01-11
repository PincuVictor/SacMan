#include "../headers/Smarga.hpp"
#include "../headers/BankerError.hpp"

#include <iostream>

void Smarga::ImplUpdate(Map &map, SacMan &ig_SacMan)
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
    if(GetTarget().x == -1 && GetTarget().y == -1 && !patrolling)
    {
        patrolClock.restart();
        patrolling = true;
        const int R = dirR(mt);
        if(R == 0)
        {
            SetTarget(80, 40);
            boundarylx = -20;
            boundaryrx = 400;
            boundaryly = 0;
            boundaryry = 400;
        }
        if(R == 1)
        {
            SetTarget(720, 40);
            boundarylx = 400;
            boundaryrx = 1000;
            boundaryly = 0;
            boundaryry = 400;
        }
        if(R == 2)
        {
            SetTarget(80, 760);
            boundarylx = -20;
            boundaryrx = 400;
            boundaryly = 400;
            boundaryry = 1000;
        }
        if(R == 3)
        {
            SetTarget(720, 760);
            boundarylx = 400;
            boundaryrx = 1000;
            boundaryly = 400;
            boundaryry = 1000;
        }
    }
    if(GetTarget().x == -1 && GetTarget().y == -1 && patrolling)
    {
        if(patrolClock.getElapsedTime().asSeconds() > 20.0f)
            patrolling = false;
        dir = RandomDirSelect(dir, map, boundarylx, boundaryrx, boundaryly, boundaryry);
    }
    if(GetTarget().x != -1 && GetTarget().y != -1)
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

std::shared_ptr<Banker> Smarga::ImplClone() const
{
    return std::make_shared<Smarga>(*this);
}

Smarga::Smarga() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
    SetBody(static_cast<float>(CELL_SIZE) / 2, sf::Color::Magenta, static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
    patrolling = false;
    boundarylx = boundaryly = boundaryrx = boundaryry = 0;
}

Smarga& Smarga::operator=(const Smarga& other)
{
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    patrolling = other.patrolling;
    boundarylx = other.boundarylx;
    boundaryly = other.boundaryly;
    boundaryrx = other.boundaryrx;
    boundaryry = other.boundaryry;
    return *this;
}

Smarga::Smarga(const Smarga &other) : Banker(other), dir(other.dir), patrolling(other.patrolling), timerClock(other.timerClock),
elapsedTime(other.elapsedTime), boundarylx(other.boundarylx), boundaryly(other.boundaryly), boundaryrx(other.boundaryrx), boundaryry(other.boundaryry)
{

}