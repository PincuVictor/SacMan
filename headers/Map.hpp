#pragma once
#include <array>
#include <fstream>
#include <cmath>

#include "Global.hpp"

class Map
{
    std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> map1{};
    public:
    Map();
    [[nodiscard]] std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> GetMap(int lvl) const;
    bool CheckCollision(bool checkCollectables, bool useDoor, int x, int y);
};