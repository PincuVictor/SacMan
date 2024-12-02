#pragma once
#include "Banker.hpp"
#include "Map.hpp"
#include <random>

class Smungu : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void ImplUpdate(Map &map, SacMan &ig_SacMan) override;
    void ImplChase(Map &map) override;
    [[nodiscard]] std::shared_ptr<Banker> ImplClone() const override;

public:
    Smungu();
    Smungu& operator=(const Smungu& other);
    Smungu(const Smungu &other);
};