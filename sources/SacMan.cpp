#include "../headers/SacMan.hpp"

#include "../headers/EHSacMan.hpp"

void SacMan::Update(Map &map)
{
    if (map.CheckCollision(false, false, x - speed, y) && map.CheckCollision(false, false, x + speed, y)
        && map.CheckCollision(false, false, x, y - speed) && map.CheckCollision(false, false, x, y + speed))
        throw EHSacMan("SacMan blocat! Nicio cale de miscare posibila detectata!");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && map.CheckCollision(false, false, x - speed, y) == false)
        SetPosition(x - speed, y);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && map.CheckCollision(false, false, x + speed, y) == false)
        SetPosition(x + speed, y);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && map.CheckCollision(false, false, x, y - speed) == false)
        SetPosition(x, y - speed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && map.CheckCollision(false, false, x, y + speed) == false)
        SetPosition(x, y + speed);
    IncrementPoints(map);
    if (2 * -CELL_SIZE >= x || (CELL_SIZE + 10) * MAP1_WIDTH <= x)
        throw EHSacMan("SacMan Out of Bounds!");
    if (-CELL_SIZE >= x)
    {
        x = CELL_SIZE * MAP1_WIDTH - 2;
    }
    else if (CELL_SIZE * MAP1_WIDTH <= x)
    {
        x = 2 - CELL_SIZE;
    }
}

SacMan::SacMan()
{
    speed = 2;
    maxSpeed = speed * 2;
    points = 0;
    x = y = 0;
}

SacMan::SacMan(const SacMan &other) : speed(other.speed), maxSpeed(other.maxSpeed), points(other.points), x(other.x), y(other.y){}

void SacMan::SetPosition(const int _x, const int _y)
{
    x = _x;
    y = _y;
}

void SacMan::IncrementPoints(Map &map)
{
    if(map.CheckCollision(true, false, x, y) == true)
        points += 50;
}

[[nodiscard]] sf::Vector2<int> SacMan::GetPosition() const
{
    return {x, y};
}

std::ostream& operator<<(std::ostream& stream, const SacMan& Sac)
{
    stream << "Speed: " << Sac.speed << '\n';
    stream << "Max Speed: " << Sac.maxSpeed << '\n';
    stream << "Points: " << Sac.points << '\n';
    stream << "X: " << Sac.x << '\n';
    stream << "Y: " << Sac.y << '\n';
    return stream;
}

SacMan& SacMan::operator=(const SacMan& other)
{
    speed = other.speed;
    maxSpeed = other.maxSpeed;
    points = other.points;
    x = other.x;
    y = other.y;
    return *this;
}

SacMan::~SacMan() = default;

