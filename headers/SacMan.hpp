#pragma once
#include <array>
#include <string>

using namespace std;

class SacMan
{
    int speed, maxSpeed, points;
    float x, y;
public:
    void Update(const sf::Time alpha, bool dir[])
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir[0] == false)
            SetPosition(x - alpha.asMilliseconds() / 1000.0f * 2, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir[1] == false)
            SetPosition(x + alpha.asMilliseconds() / 1000.0f * 2, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir[2] == false)
            SetPosition(x, y - alpha.asMilliseconds() / 1000.0f * 2);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir[3] == false)
            SetPosition(x, y + alpha.asMilliseconds() / 1000.0f * 2);
    }
    SacMan(const int _speed, const int _maxSpeed, const int _points)
    {
        speed = _speed;
        maxSpeed = _maxSpeed;
        points = _points;
    }
    void SetPosition(const float _x, const float _y)
    {
        x = _x;
        y = _y;
    }
    [[nodiscard]] sf::Vector2<float> GetPosition() const
    {
        return {x, y};
    }
    friend std::ostream& operator<<(std::ostream& stream, const SacMan& Sac)
    {
        stream << "Speed: " << Sac.speed << '\n';
        stream << "Max Speed: " << Sac.maxSpeed << '\n';
        stream << "Points: " << Sac.points << '\n';
        return stream;
    }
    SacMan& operator=(const SacMan& Sac)
      = default;
    ~SacMan() = default;



};
