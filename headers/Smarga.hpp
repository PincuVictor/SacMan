#pragma once
#include "Banker.hpp"

class Smarga : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void Update(Map &map, SacMan &ig_SacMan) override;
    void Chase(Map &map) override;

public:
    Smarga();
    Smarga& operator=(const Smarga& other);
    Smarga(const Smarga &other);
};