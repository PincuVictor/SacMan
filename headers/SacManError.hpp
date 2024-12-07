#pragma once
#include "GameError.hpp"

class SacManError : public GameError
{
    public:
    explicit SacManError(const std::string& error) : GameError("Eroare SacMan: " + error){}

};