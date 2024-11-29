#pragma once
#include "Banker.hpp"

class Sparga : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void Update(Map &map, SacMan &ig_SacMan) override;
    void Chase(Map &map) override;
    [[nodiscard]] std::shared_ptr<Banker> Clone() const override;

public:
    Sparga();
    Sparga& operator=(const Sparga& other);
    Sparga(const Sparga &other);
};