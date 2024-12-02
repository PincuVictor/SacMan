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
    void ImplUpdate(Map &map, SacMan &ig_SacMan) override;
    void ImplChase(Map &map) override;
    [[nodiscard]] std::shared_ptr<Banker> ImplClone() const override;

public:
    Sbungu();
    Sbungu& operator=(const Sbungu& other);
    Sbungu(const Sbungu &other);
};