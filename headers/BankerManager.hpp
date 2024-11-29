#pragma once
#include "InitBankers.hpp"
#include "Global.hpp"
#include "Banker.hpp"
#include "Map.hpp"

class BankerManager
{
    std::array<std::shared_ptr<Banker>, BANKERS_NUMBER> ig_Bankers{};
    public:
    BankerManager();
    void CallUpdate(Map &map, SacMan &ig_SacMan) const;
    void CallSetPosition(int x, int y) const;
    [[nodiscard]] std::shared_ptr<Banker> GetBanker(int c) const;
    friend std::ostream& operator<<(std::ostream& stream, const BankerManager& B);
};
