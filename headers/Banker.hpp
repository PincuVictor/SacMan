#pragma once

class Banker
{
    int speed, maxSpeed;
public:
    Banker(const int _speed, const int _maxSpeed)
    {
        speed = _speed;
        maxSpeed = _maxSpeed;
    }
    friend std::ostream& operator<<(std::ostream& stream, const Banker& G)
    {
        stream << "Speed: " << G.speed << '\n';
        stream << "Max Speed: " << G.maxSpeed << '\n';
        return stream;
    }
    Banker& operator=(const Banker& G)
    = default;
    ~Banker() = default;
};
