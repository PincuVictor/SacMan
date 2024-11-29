#pragma once
#include "Map.hpp"
#include "Global.hpp"
#include "Banker.hpp"
#include <random>

class Sbungu : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void Update(Map &map, SacMan &ig_SacMan) override;
    void Chase(Map &map) override;
public:
    Sbungu();
    Sbungu& operator=(const Sbungu& other);
    Sbungu(const Sbungu &other);
};