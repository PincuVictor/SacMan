#pragma once
#include <stdexcept>

class GameError : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};