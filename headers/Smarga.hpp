#pragma once
#include "Banker.hpp"

class Smarga : public Banker
{
    int dir = 0;
    bool patrolling;
    sf::Clock timerClock, patrolClock;
    float elapsedTime = 0;
    int boundarylx, boundaryly, boundaryrx, boundaryry;
    void ImplUpdate(Map &map, SacMan &ig_SacMan) override;
    void ImplChase(Map &map) override;
    [[nodiscard]] std::shared_ptr<Banker> ImplClone() const override;

public:
    Smarga();
    Smarga& operator=(const Smarga& other);
    Smarga(const Smarga &other);
};