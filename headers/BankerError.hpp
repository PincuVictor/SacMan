#pragma once

#include "GameError.hpp"

class BankerError : public GameError
{
    public:
    explicit BankerError(const std::string& error) : GameError("Eroare Banker: " + error){}
};
