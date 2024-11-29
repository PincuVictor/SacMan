#include "../headers/InitBankers.hpp"

Banker* InitBankers::Initialize(const int id)
{
    Banker* banker = nullptr;
    if(id == 0)
        banker = new Smungu;
    if(id == 1)
        banker = new Sbungu;
    if(id == 2)
        banker = new Sparga;
    if(id == 3)
        banker = new Smarga;
    return banker;
}