#include "../headers/InitBankers.hpp"

#include "../headers/EHBankers.hpp"


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
        Smarga smarga;
        banker = smarga.Clone();
    }
    if (banker == nullptr)
        throw EHBankers("Eroare la initializarea Bankerilor");
    return banker;
}

std::shared_ptr<Banker> InitBankers::Copy(const std::shared_ptr<Banker>& B)
{
    return B->Clone();
}
