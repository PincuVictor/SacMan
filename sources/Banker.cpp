#include "../headers/Banker.hpp"

void Banker::ImplUpdate(Map &map, SacMan &ig_SacMan)
{
    Update(map, ig_SacMan);
}

void Banker::ImplChase(Map &map)
{
    Chase(map);
}

[[nodiscard]] std::shared_ptr<Banker> Banker::ImplClone() const
{
    return Clone();
}

void Banker::SetTarget(const int _x, const int _y)
{
    targetx = _x;
    targety = _y;
}

void Banker::GetOut()
{
    if(useDoor == true)
    {
        targetx = x;
        targety = y - 2 * CELL_SIZE;
        useDoor = false;
    }
}

void Banker::SetPosition(const int _x, const int _y)
{
    x = _x;
    y = _y;
}

[[nodiscard]] sf::Vector2<int> Banker::GetPosition() const
{
    return {x, y};
}

[[nodiscard]] sf::Vector2<int> Banker::GetTarget() const
{
    return {targetx, targety};
}

Banker::Banker()
{
    speed = 2;
    x = y = 0;
    targetx = targety = -1;
}

Banker::Banker(const Banker& other) : speed(other.speed), x(other.x), y(other.y), targetx(other.x), targety(other.y), useDoor(other.useDoor){}

std::ostream& operator<<(std::ostream& stream, const Banker& B)
{
    stream << "Speed: " << B.speed << '\n';
    stream << "X: " << B.x << '\n';
    stream << "Y: " << B.y << '\n';
    stream << "Target X: " << B.targetx << '\n';
    stream << "Target Y: " << B.targety << '\n';
    stream << "UseDoor: " << B.useDoor << '\n';
    return stream;
}

Banker& Banker::operator=(const Banker& other)
{
    targetx = other.targetx;
    targety = other.targety;
    speed = other.speed;
    x = other.x;
    y = other.y;
    return *this;
}

Banker::~Banker() = default;