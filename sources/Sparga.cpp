#include "../headers/Sparga.hpp"

#include <iostream>

#include "../headers/BankerError.hpp"

void Sparga::ImplUpdate(Map &map, SacMan &ig_SacMan)
{
    SetSpeed(1);
    bool ways[4];
    int availableWays = 0;
    if (GetPosition().x <= 2 * -CELL_SIZE || GetPosition().x >= (CELL_SIZE + 10) * MAP1_WIDTH
        || GetPosition().y <= 2 * -CELL_SIZE || GetPosition().y >= (CELL_SIZE + 10) * MAP1_HEIGHT)
        throw BankerError("Banker Out of Bounds!");
    ways[0] = map.CheckCollision(false, true, GetPosition().x - 1, GetPosition().y);
    ways[1] = map.CheckCollision(false, true, GetPosition().x + 1, GetPosition().y);
    ways[2] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y - 1);
    ways[3] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y + 1);
    if(GetPosition().x - 1 <= 0)
        ways[0] = true;
    if(GetPosition().x + 1 >= (MAP1_WIDTH - 1) * CELL_SIZE)
        ways[1] = true;
    if(GetPosition().y - 1 <= 0)
        ways[2] = true;
    if(GetPosition().y + 1 >= (MAP1_HEIGHT - 1) * CELL_SIZE)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    if (availableWays == 0)
        throw BankerError("Banker blocat! Nicio cale posibila detectata");
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<short> dirR(0, 3);
    GetOut();
    if(sqrt(pow(GetPosition().x - ig_SacMan.GetPosition().x, 2) + pow(GetPosition().y - ig_SacMan.GetPosition().y, 2)) <= 9 * CELL_SIZE
        && timerClock.getElapsedTime().asSeconds() > 10)
    {
        SetTarget(ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y);
        if(elapsedTime == 0)
            elapsedTime = timerClock.getElapsedTime().asSeconds();
    }

    if(GetTarget().x == -1 && GetTarget().y == -1)
    {
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
            SetPosition(GetPosition().x - 1, GetPosition().y);
            SetBodyPosition(static_cast<float>(GetPosition().x - 1), static_cast<float>(GetPosition().y));
            break;
        case 1:
            SetPosition(GetPosition().x + 1, GetPosition().y);
            SetBodyPosition(static_cast<float>(GetPosition().x + 1), static_cast<float>(GetPosition().y));

            break;
        case 2:
            SetPosition(GetPosition().x, GetPosition().y - 1);
            SetBodyPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y - 1));
            break;
        case 3:
            SetPosition(GetPosition().x, GetPosition().y + 1);
            SetBodyPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y + 1));
            break;
        default: ;
        }
        if (dir < 0 || dir > 3)
            throw BankerError("Banker | directia selectata nu exista!");
    }
    else
    {
        if(GetTarget().x != GetPosition().x || GetTarget().y != GetPosition().y)
            if(timerClock.getElapsedTime().asSeconds() - elapsedTime < 2.0f)
            {
                SetPosition(GetPosition().x % 4 + GetPosition().x, GetPosition().y % 4 + GetPosition().y);
                Chase(map);
            }
            else
            {
                timerClock.restart();
                elapsedTime = 0;
                SetTarget(-1, -1);
            }
        else
        {
            SetTarget(-1, -1);
        }
    }
}

void Sparga::ImplChase(Map &map)
{
    SetSpeed(4);
    bool ways[4];
    int selected = 0, availableWays = 0;
    double dist = 20000000;
    if (GetPosition().x <= 2 * -CELL_SIZE || GetPosition().x >= (CELL_SIZE + 10) * MAP1_WIDTH
    || GetPosition().y <= 2 * -CELL_SIZE || GetPosition().y >= (CELL_SIZE + 10) * MAP1_HEIGHT)
        throw BankerError("Banker Out of Bounds!");
    ways[0] = map.CheckCollision(false, true, GetPosition().x - 4, GetPosition().y);
    ways[1] = map.CheckCollision(false, true, GetPosition().x + 4, GetPosition().y);
    ways[2] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y - 4);
    ways[3] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y + 4);
    if(GetPosition().x - 4 <= 0)
        ways[0] = true;
    if(GetPosition().x + 4 >= (MAP1_WIDTH - 1) * CELL_SIZE)
        ways[1] = true;
    if(GetPosition().y - 4 <= 0)
        ways[2] = true;
    if(GetPosition().y + 4 >= (MAP1_HEIGHT - 1) * CELL_SIZE)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    if (availableWays == 0)
        throw BankerError("Banker blocat! Nicio cale posibila detectata");
    if(ways[0] == false)
    {
        if(sqrt(pow(GetPosition().x - 4 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 1)
        {
            dist = sqrt(pow(GetPosition().x - 4 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
            selected = 0;
        }
    }
    if(ways[1] == false)
    {
        if(sqrt(pow(GetPosition().x + 4 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 0)
        {
            dist = sqrt(pow(GetPosition().x + 4 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
            selected = 1;
        }
    }
    if(ways[2] == false)
    {
        if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 4 - GetTarget().y, 2)) < dist && dir != 3)
        {
            dist = sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 4 - GetTarget().y, 2));
            selected = 2;
        }
    }
    if(ways[3] == false)
    {
        if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y + 4 - GetTarget().y, 2)) < dist && dir != 2)
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
        SetPosition(GetPosition().x - 4, GetPosition().y);
        SetBodyPosition(static_cast<float>(GetPosition().x - 4), static_cast<float>(GetPosition().y));
        break;
    case 1:
        SetPosition(GetPosition().x + 4, GetPosition().y);
        SetBodyPosition(static_cast<float>(GetPosition().x + 4), static_cast<float>(GetPosition().y));

        break;
    case 2:
        SetPosition(GetPosition().x, GetPosition().y - 4);
        SetBodyPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y - 4));
        break;
    case 3:
        SetPosition(GetPosition().x, GetPosition().y + 4);
        SetBodyPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y + 4));
        break;
    default: ;
    }
    if (dir < 0 || dir > 3)
        throw BankerError("Banker | directia selectata nu exista!");
}

std::shared_ptr<Banker> Sparga::ImplClone() const
{
    return std::make_shared<Sparga>(*this);
}

Sparga::Sparga() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
    SetSpeed(1);
    SetBody(static_cast<float>(CELL_SIZE) / 2, sf::Color::Cyan, static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
}

Sparga& Sparga::operator=(const Sparga& other)
{
    SetPosition(other.GetPosition().x, other.GetPosition().y);
    SetTarget(other.GetTarget().x, other.GetTarget().y);
    SetSpeed(other.GetSpeed());
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Sparga::Sparga(const Sparga &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime){}