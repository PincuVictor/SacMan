#pragma once
#include <stdexcept>

class ErrorHandling : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};