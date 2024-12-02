#include "../headers/InitBankers.hpp"


std::shared_ptr<Banker> InitBankers::Initialize(const int id)
{
    std::shared_ptr<Banker> banker = nullptr;
    if(id == 0)
    {
        Smungu smungu;
        banker = smungu.Clone();
    }
    if(id == 1)
    {
        Sbungu sbungu;
        banker = sbungu.Clone();
    }
    if(id == 2)
    {
        Sparga sparga;
        banker = sparga.Clone();
    }
    if(id == 3)
    {
        Smarga smarga;
        banker = smarga.Clone();
    }
    return banker;
}

std::shared_ptr<Banker> InitBankers::Copy(const std::shared_ptr<Banker>& B)
{
    return B->Clone();
}
