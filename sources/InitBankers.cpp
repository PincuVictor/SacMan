#include "../headers/InitBankers.hpp"

std::shared_ptr<Banker> InitBankers::Initialize(const int id)
{
    std::shared_ptr<Banker> banker = nullptr;
    if(id == 0)
    {
        auto* smungu = new Smungu;
        banker = smungu->ImplClone();
        delete smungu;
    }
    if(id == 1)
    {
        auto* sbungu = new Sbungu;
        banker = sbungu->ImplClone();
        delete sbungu;
    }
    if(id == 2)
    {
        auto* sparga = new Sparga;
        banker = sparga->ImplClone();
        delete sparga;
    }
    if(id == 3)
    {
        auto* smarga = new Smarga;
        banker = smarga->ImplClone();
        delete smarga;
    }
    return banker;
}