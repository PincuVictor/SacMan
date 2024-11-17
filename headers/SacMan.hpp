#pragma once
#include "Global.hpp"
#include "Map.hpp"

using namespace std;

class SacMan
{
    int speed, maxSpeed;
    int points;
    int x, y;
public:
    void Update(Map &map)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && map.CheckCollision(false, false, x - speed, y) == false)
            SetPosition(x - speed, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && map.CheckCollision(false, false, x + speed, y) == false)
            SetPosition(x + speed, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && map.CheckCollision(false, false, x, y - speed) == false)
            SetPosition(x, y - speed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && map.CheckCollision(false, false, x, y + speed) == false)
            SetPosition(x, y + speed);
        IncrementPoints(map);
        if (-CELL_SIZE >= x)
        {
            x = CELL_SIZE * MAP1_WIDTH - 2;
        }
        else if (CELL_SIZE * MAP1_WIDTH <= x)
        {
            x = 2 - CELL_SIZE;
        }
    }
    explicit SacMan()
    {
        speed = 2;
        maxSpeed = speed * 2;
        points = 0;
        x = y = 0;
    }
    void SetPosition(const int _x, const int _y)
    {
        x = _x;
        y = _y;
    }
    void IncrementPoints(Map &map)
    {
        if(map.CheckCollision(true, false, x, y) == true)
            points += 50;
    }
    [[nodiscard]] sf::Vector2<int> GetPosition() const
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
    SacMan& operator=(const SacMan& other)
    {
        speed = other.speed;
        maxSpeed = other.maxSpeed;
        points = other.points;
        x = other.x;
        y = other.y;
        return *this;
    }
    ~SacMan() = default;



};