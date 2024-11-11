#pragma once

using namespace std;

class SacMan
{
    int speed, maxSpeed;
    int points;
    int x, y;
public:
    void Update(const bool dir[])
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir[2] == false)
            SetPosition(x - speed, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir[0] == false)
            SetPosition(x + speed, y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir[3] == false)
            SetPosition(x, y - speed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir[1] == false)
            SetPosition(x, y + speed);
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
    void IncrementPoints()
    {
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
    SacMan& operator=(const SacMan& Sac)
      = default;
    ~SacMan() = default;



};
