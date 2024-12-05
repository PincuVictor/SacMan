#pragma once
#include "ErrorHandling.hpp"

class EHMap final : public ErrorHandling
{
    public:
    explicit EHMap(const std::string& error) : ErrorHandling("Eroare Map: " + error){}

};