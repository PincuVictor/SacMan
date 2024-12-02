#pragma once
#include "Banker.hpp"

class Smarga : public Banker
{
    int dir = 0;
    sf::Clock timerClock;
    float elapsedTime = 0;
    void ImplUpdate(Map &map, SacMan &ig_SacMan) override;
    void ImplChase(Map &map) override;
    [[nodiscard]] std::shared_ptr<Banker> ImplClone() const override;

public:
    Smarga();
    Smarga& operator=(const Smarga& other);
    Smarga(const Smarga &other);
};