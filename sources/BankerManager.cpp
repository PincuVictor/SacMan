#include "../headers/BankerManager.hpp"
#include <thread>

BankerManager::BankerManager()
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
        ig_Bankers[i] = InitBankers::Initialize(i);
}

BankerManager::BankerManager(const BankerManager& BM)
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
        ig_Bankers[i] = InitBankers::Copy(BM.ig_Bankers[i]);
}

BankerManager& BankerManager::operator=(const BankerManager& BM)
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
        *ig_Bankers[i] = *BM.ig_Bankers[i];
    return *this;
}

void BankerManager::CallUpdate(Map &map, SacMan &ig_SacMan) const
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
    {
        ig_Bankers[i]->Update(map, ig_SacMan);
    }
}

void BankerManager::CallSetPosition(const int x, const int y) const
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
        ig_Bankers[i]->SetPosition(x, y);
}

[[nodiscard]] std::shared_ptr<Banker> BankerManager::GetBanker(const int c) const
{
    if(c >= 0 && c < BANKERS_NUMBER)
        return ig_Bankers[c];
    return nullptr;
}

std::ostream& operator<<(std::ostream& stream, const BankerManager& B)
{
    for(int i = 0; i < BANKERS_NUMBER; ++i)
        stream << *B.ig_Bankers[i];
    return stream;
}