#pragma once
#include "Banker.hpp"
#include "Smungu.hpp"
#include "Sbungu.hpp"
#include "Sparga.hpp"
#include "Smarga.hpp"

class InitBankers
{
    public:
    static std::shared_ptr<Banker> Initialize(int id);
    static std::shared_ptr<Banker> Copy(const std::shared_ptr<Banker>& B);
};
