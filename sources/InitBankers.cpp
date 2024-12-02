#include "../headers/InitBankers.hpp"


std::shared_ptr<Banker> InitBankers::Initialize(const int id)
{
    std::shared_ptr<Banker> banker = nullptr;
    if(id == 0)
    {
        Smungu smungu;
        banker = smungu.ImplClone();
    }
    if(id == 1)
    {
        Sbungu sbungu;
        banker = sbungu.ImplClone();
    }
    if(id == 2)
    {
        Sparga sparga;
        banker = sparga.ImplClone();
    }
    if(id == 3)
    {
        Smarga smarga;
        banker = smarga.ImplClone();
    }
    return banker;
}

std::shared_ptr<Banker> InitBankers::Copy(const std::shared_ptr<Banker>& B)
{
    return B->ImplClone();
}
