#pragma once
#include "ErrorHandling.hpp"

class EHSacMan final : public ErrorHandling
{
    public:
    explicit EHSacMan(const std::string& error) : ErrorHandling("Eroare SacMan: " + error){}

};