#pragma once
#include "Banker.hpp"
#include "Map.hpp"
#include <random>

class Sparga : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void ImplUpdate(Map &map, SacMan &ig_SacMan) override;
    [[nodiscard]] std::shared_ptr<Banker> ImplClone() const override;

public:
    Sparga();
    Sparga& operator=(const Sparga& other);
    Sparga(const Sparga &other);
};