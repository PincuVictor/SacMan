#pragma once
#include "GameError.hpp"

class MapError : public GameError
{
    public:
    explicit MapError(const std::string& error) : GameError("Eroare Map: " + error){}

};