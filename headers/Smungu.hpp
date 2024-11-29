#pragma once
#include "Banker.hpp"
#include "Map.hpp"
#include <random>

class Smungu : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void Update(Map &map, SacMan &ig_SacMan) override;
    void Chase(Map &map) override;

public:
    Smungu();
    Smungu& operator=(const Smungu& other);
    Smungu(const Smungu &other);
};