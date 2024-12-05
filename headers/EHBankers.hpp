#pragma once
#include <stdexcept>

#include "ErrorHandling.hpp"

class EHBankers final : public ErrorHandling
{
    public:
    explicit EHBankers(const std::string& error) : ErrorHandling("Eroare Banker: " + error){}
};
