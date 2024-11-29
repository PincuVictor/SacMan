#pragma once
#include "InitBankers.hpp"
#include "Banker.hpp"
#include "Map.hpp"

class BankerManager
{
    Banker* ig_Bankers[4]{};
    public:
    BankerManager();
    void CallUpdate(Map &map, SacMan &ig_SacMan) const;
    void CallSetPosition(int x, int y) const;
    [[nodiscard]] Banker* GetBanker(int c) const;
    friend std::ostream& operator<<(std::ostream& stream, const BankerManager& B);
};
