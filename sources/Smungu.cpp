#include "../headers/Smungu.hpp"

void Smungu::Update(Map &map, SacMan &ig_SacMan)
{
    bool ways[4];
    int availableWays = 0;
    ways[0] = map.CheckCollision(false, false, GetPosition().x - 2, GetPosition().y);
    ways[1] = map.CheckCollision(false, false, GetPosition().x + 2, GetPosition().y);
    ways[2] = map.CheckCollision(false, false, GetPosition().x, GetPosition().y - 2);
    ways[3] = map.CheckCollision(false, false, GetPosition().x, GetPosition().y + 2);
    if(GetPosition().x - 2 <= 0)
        ways[0] = true;
    if(GetPosition().x + 2 >= (MAP1_WIDTH - 1) * CELL_SIZE)
        ways[1] = true;
    if(GetPosition().y - 2 <= 0)
        ways[2] = true;
    if(GetPosition().y + 2 >= (MAP1_HEIGHT - 1) * CELL_SIZE)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<short> dirR(0, 3);
    GetOut();
    if(sqrt(pow(GetPosition().x - ig_SacMan.GetPosition().x, 2) + pow(GetPosition().y - ig_SacMan.GetPosition().y, 2)) <= 4 * CELL_SIZE
        && timerClock.getElapsedTime().asSeconds() > 7)
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
            SetPosition(GetPosition().x - 2, GetPosition().y);
            break;
        case 1:
            SetPosition(GetPosition().x + 2, GetPosition().y);
            break;
        case 2:
            SetPosition(GetPosition().x, GetPosition().y - 2);
            break;
        case 3:
            SetPosition(GetPosition().x, GetPosition().y + 2);
            break;
        default: ;
        }
    }
    else
    {
        if(GetTarget().x != GetPosition().x || GetTarget().y != GetPosition().y)
            if(timerClock.getElapsedTime().asSeconds() - elapsedTime < 6.0f)
            {
                ImplChase(map);
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

void Smungu::Chase(Map &map)
{
    bool ways[4];
    int selected = 0, availableWays = 0;
    double dist = 20000000;
    ways[0] = map.CheckCollision(false, true, GetPosition().x - 2, GetPosition().y);
    ways[1] = map.CheckCollision(false, true, GetPosition().x + 2, GetPosition().y);
    ways[2] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y - 2);
    ways[3] = map.CheckCollision(false, true, GetPosition().x, GetPosition().y + 2);
    if(GetPosition().x - 2 <= 0)
        ways[0] = true;
    if(GetPosition().x + 2 >= (MAP1_WIDTH - 1) * CELL_SIZE)
        ways[1] = true;
    if(GetPosition().y - 2 <= 0)
        ways[2] = true;
    if(GetPosition().y + 2 >= (MAP1_HEIGHT - 1) * CELL_SIZE)
        ways[3] = true;
    for(const bool way : ways)
        if(way == false)
            availableWays++;
    if(ways[0] == false)
    {
        if(sqrt(pow(GetPosition().x - 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 1)
        {
            dist = sqrt(pow(GetPosition().x - 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
            selected = 0;
        }
    }
    if(ways[1] == false)
    {
        if(sqrt(pow(GetPosition().x + 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2)) < dist && dir != 0)
        {
            dist = sqrt(pow(GetPosition().x + 2 - GetTarget().x, 2) + pow(GetPosition().y - GetTarget().y, 2));
            selected = 1;
        }
    }
    if(ways[2] == false)
    {
        if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 2 - GetTarget().y, 2)) < dist && dir != 3)
        {
            dist = sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y - 2 - GetTarget().y, 2));
            selected = 2;
        }
    }
    if(ways[3] == false)
    {
        if(sqrt(pow(GetPosition().x - GetTarget().x, 2) + pow(GetPosition().y + 2 - GetTarget().y, 2)) < dist && dir != 2)
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
        SetPosition(GetPosition().x - 2, GetPosition().y);
        break;
    case 1:
        SetPosition(GetPosition().x + 2, GetPosition().y);
        break;
    case 2:
        SetPosition(GetPosition().x, GetPosition().y - 2);
        break;
    case 3:
        SetPosition(GetPosition().x, GetPosition().y + 2);
        break;
    default: ;
    }
}

Smungu::Smungu() : Banker()
{
    dir = 0;
    timerClock.restart();
    elapsedTime = 0;
}

Smungu& Smungu::operator=(const Smungu& other)
{
    dynamic_cast<Banker*>(this)->operator=(other);
    dir = other.dir;
    timerClock = other.timerClock;
    elapsedTime = other.elapsedTime;
    return *this;
}

Smungu::Smungu(const Smungu &other) : Banker(other), dir(other.dir), timerClock(other.timerClock), elapsedTime(other.elapsedTime){}