#include "../headers/Banker.hpp"
#include "../headers/BankerError.hpp"

#include <iostream>

void Banker::Update(Map &map, SacMan &ig_SacMan)
{
    ImplUpdate(map, ig_SacMan);
}

int Banker::Chase(Map &map, int dir)
{
    bool ways[4];
    int selected = 0, availableWays = 0;
    double dist = 20000000;
    if (x <= 2 * -CELL_SIZE || x >= (CELL_SIZE + 10) * MAP1_WIDTH
    || y <= 2 * -CELL_SIZE || y >= (CELL_SIZE + 10) * MAP1_HEIGHT)
        throw BankerError("Banker Out of Bounds!");
    ways[0] = map.CheckCollision(false, true, x - speed, y);
    ways[1] = map.CheckCollision(false, true, x + speed, y);
    ways[2] = map.CheckCollision(false, true, x, y - speed);
    ways[3] = map.CheckCollision(false, true, x, y + speed);
    if(x - speed <= 0)
        ways[0] = true;
    if(x + speed >= (MAP1_WIDTH - 1) * CELL_SIZE)
        ways[1] = true;
    if(y - speed <= 0)
        ways[2] = true;
    if(y + speed >= (MAP1_HEIGHT - 1) * CELL_SIZE)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    if (availableWays == 0)
        throw BankerError("Banker blocat! Nicio cale posibila detectata");
    if(ways[0] == false)
    {
        if(sqrt(pow(x - speed - targetx, 2) + pow(y - targety, 2)) < dist && dir != 1)
        {
            dist = sqrt(pow(x - speed - targetx, 2) + pow(y - targety, 2));
            selected = 0;
        }
    }
    if(ways[1] == false)
    {
        if(sqrt(pow(x + speed - targetx, 2) + pow(y - targety, 2)) < dist && dir != 0)
        {
            dist = sqrt(pow(x + speed - targetx, 2) + pow(y - targety, 2));
            selected = 1;
        }
    }
    if(ways[2] == false)
    {
        if(sqrt(pow(x - targetx, 2) + pow(y - speed - targety, 2)) < dist && dir != 3)
        {
            dist = sqrt(pow(x - targetx, 2) + pow(y - speed - targety, 2));
            selected = 2;
        }
    }
    if(ways[3] == false)
    {
        if(sqrt(pow(x - targetx, 2) + pow(y + speed - targety, 2)) < dist && dir != 2)
        {
            selected = 3;
        }
    }
    if(availableWays == 1)
        switch (dir)
        {
        case 0:
            selected = 1;
            break;
        case 1:
            selected = 0;
            break;
        case 2:
            selected = 3;
            break;
        case 3:
            selected = 2;
            break;
        default: ;
        }
    dir = selected;
    switch (dir)
    {
    case 0:
        x = x - speed;
        body.setPosition(static_cast<float>(GetPosition().x - speed), static_cast<float>(GetPosition().y));
        break;
    case 1:
        x = x + speed;
        body.setPosition(static_cast<float>(GetPosition().x + speed), static_cast<float>(GetPosition().y));
        break;
    case 2:
        y = y - speed;
        body.setPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y - speed));
        break;
    case 3:
        y = y + speed;
        body.setPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y + speed));
        break;
    default: ;
    }
    return dir;
}

[[nodiscard]] std::shared_ptr<Banker> Banker::Clone() const
{
    return ImplClone();
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

int Banker::RandomDirSelect(int dir, Map &map, int boundarylx, int boundaryrx, int boundaryly, int boundaryry)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<short> dirR(0, 3);
    bool ways[4];
    int availableWays = 0;
    if (x <= 2 * -CELL_SIZE || x >= (CELL_SIZE + 10) * MAP1_WIDTH
        || y <= 2 * -CELL_SIZE || y >= (CELL_SIZE + 10) * MAP1_HEIGHT)
        throw BankerError("Banker Out of Bounds!");
    ways[0] = map.CheckCollision(false, true, x - speed, y);
    ways[1] = map.CheckCollision(false, true, x + speed, y);
    ways[2] = map.CheckCollision(false, true, x, y - speed);
    ways[3] = map.CheckCollision(false, true, x, y + speed);
    if(x - speed <= 0 || x - speed < boundarylx)
        ways[0] = true;
    if(x + speed >= (MAP1_WIDTH - 1) * CELL_SIZE || x > boundaryrx)
        ways[1] = true;
    if(y - speed <= 0 || y - speed < boundaryly)
        ways[2] = true;
    if(y + speed >= (MAP1_HEIGHT - 1) * CELL_SIZE || y > boundaryry)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    if (availableWays == 0)
        throw BankerError("Banker blocat! Nicio cale posibila detectata");
    bool selected = false;
    if(availableWays == 1)
    {
        if(ways[0] == false)
            dir = 0;
        if(ways[1] == false)
            dir = 1;
        if(ways[2] == false)
            dir = 2;
        if(ways[3] == false)
            dir = 3;
    }
    if(availableWays == 2)
    {
        if(dir == 0 && ways[0] == true)
        {
            dir = dirR(mt);
            while(dir == 0 || dir == 1 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 1 && ways[1] == true && selected == false)
        {
            dir = dirR(mt);
            while(dir == 1 || dir == 0 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 2 && ways[2] == true && selected == false)
        {
            dir = dirR(mt);
            while(dir == 2 || dir == 3 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 3 && ways[3] == true && selected == false)
        {
            dir = dirR(mt);
            while(dir == 3 || dir == 2 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
    }
    if(availableWays >= 3)
    {
        if(dir == 0 && selected == false)
        {
            dir = dirR(mt);
            while(dir == 1 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 1 && selected == false)
        {
            dir = dirR(mt);
            while(dir == 0 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 2 && selected == false)
        {
            dir = dirR(mt);
            while(dir == 3 || ways[dir] == true)
                dir = dirR(mt);
            selected = true;
        }
        if(dir == 3 && selected == false)
        {
            dir = dirR(mt);
            while(dir == 2 || ways[dir] == true)
                dir = dirR(mt);
        }
    }
    switch (dir)
    {
    case 0:
        x = x - speed;
        body.setPosition(static_cast<float>(GetPosition().x - speed), static_cast<float>(GetPosition().y));
        break;
    case 1:
        x = x + speed;
        body.setPosition(static_cast<float>(GetPosition().x + speed), static_cast<float>(GetPosition().y));
        break;
    case 2:
        y = y - speed;
        body.setPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y - speed));
        break;
    case 3:
        y = y + speed;
        body.setPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y + speed));
        break;
    default: ;
    }
    if (dir < 0 || dir > 3)
        throw BankerError("Banker | directia selectata nu exista!");
    return dir;
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

void Banker::SetBody(const float radius, const sf::Color color, const float _x, const float _y)
{
    body.setRadius(radius);
    body.setFillColor(color);
    body.setPosition(sf::Vector2f(_x, _y));
}

void Banker::SetBodyPosition(const float _x, const float _y)
{
    body.setPosition(sf::Vector2f(_x, _y));
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