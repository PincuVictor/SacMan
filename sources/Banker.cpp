#include "../headers/Banker.hpp"

#include <iostream>

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

void Banker::SetSpeed(const int s)
{
    speed = s;
}

void Banker::SetBody(const float radius, const sf::Color color, const float x, const float y)
{
    body.setRadius(radius);
    body.setFillColor(color);
    body.setPosition(sf::Vector2f(x, y));
}

void Banker::SetBodyPosition(const float x, const float y)
{
    body.setPosition(sf::Vector2f(x, y));
}

sf::CircleShape Banker::GetBody()
{
    return body;
}


int Banker::GetSpeed() const
{
    return speed;
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
    body.setRadius(static_cast<float>(CELL_SIZE) / 2);
    body.setFillColor(sf::Color::White);
    body.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

Banker::Banker(const Banker& other) : speed(other.speed), x(other.x), y(other.y), targetx(other.targetx), targety(other.targety), useDoor(other.useDoor), body(other.body){}

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
    body = other.body;
    return *this;
}

Banker::~Banker() = default;