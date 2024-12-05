#include "../headers/Smarga.hpp"

#include <iostream>

void Smarga::ImplUpdate(Map &map, SacMan &ig_SacMan)
{
    std::cout <<"Smarga::ImplUpdate(Map &map, SacMan &ig_SacMan)\n";
}

void Smarga::ImplChase(Map &map)
{
    std::cout<<"Smarga::ImplChase"<<std::endl;
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
}

Smarga& Smarga::operator=(const Smarga& other)
{
    SetPosition(other.GetPosition().x, other.GetPosition().y);
    SetTarget(other.GetTarget().x, other.GetTarget().y);
    SetSpeed(other.GetSpeed());
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Smarga::Smarga(const Smarga &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime)
{

}