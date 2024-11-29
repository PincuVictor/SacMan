#include "../headers/BankerManager.hpp"

BankerManager::BankerManager()
{
    ig_Bankers[0] = InitBankers::Initialize(0);
    ig_Bankers[1] = InitBankers::Initialize(1);
    ig_Bankers[2] = InitBankers::Initialize(2);
    ig_Bankers[3] = InitBankers::Initialize(3);
}

void BankerManager::CallUpdate(Map &map, SacMan &ig_SacMan) const
{
    ig_Bankers[0]->ImplUpdate(map, ig_SacMan);
    ig_Bankers[1]->ImplUpdate(map, ig_SacMan);
    ig_Bankers[2]->ImplUpdate(map, ig_SacMan);
    ig_Bankers[3]->ImplUpdate(map, ig_SacMan);
}

void BankerManager::CallSetPosition(const int x, const int y) const
{
    ig_Bankers[0]->SetPosition(x, y);
    ig_Bankers[1]->SetPosition(x, y);
    ig_Bankers[2]->SetPosition(x, y);
    ig_Bankers[3]->SetPosition(x, y);
}

[[nodiscard]] Banker* BankerManager::GetBanker(const int c) const
{
    if(c >= 0 && c < 4)
        return ig_Bankers[c];
    return nullptr;
}

std::ostream& operator<<(std::ostream& stream, const BankerManager& B)
{
    stream << *B.ig_Bankers[0];
    stream << *B.ig_Bankers[1];
    stream << *B.ig_Bankers[2];
    stream << *B.ig_Bankers[3];
    return stream;
}