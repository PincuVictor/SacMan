#pragma once
#include <array>
#include <string>

using namespace std;

class SacMan
{
    int speed, maxSpeed, points, x, y;
public:
    SacMan(const int _speed, const int _maxSpeed, const int _points)
    {
        speed = _speed;
        maxSpeed = _maxSpeed;
        points = _points;
    }
    void SetPosition(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
    static sf::Vector2<int> GetPosition(SacMan& ig_SacMan)
    {
        return {ig_SacMan.x, ig_SacMan.y};
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
