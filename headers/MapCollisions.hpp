#pragma once
#include <array>
#include <cmath>
#include "Global.hpp"
#include "SacMan.hpp"

using namespace std;


class MapCollisions
{
    public:
    static bool CheckCollision(const bool checkCollectables, const bool useDoor, array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> &ig_level, SacMan &ig_SacMan, int x, int y)
    {
        bool output = false;
        const float cell_x = static_cast<float>(x) / static_cast<float>(CELL_SIZE);
        const float cell_y = static_cast<float>(y) / static_cast<float>(CELL_SIZE);

        for(int i = 0; i < 4; i++)
        {
            switch(i)
            {
            case 0:
                {
                    x = floor(cell_x);
                    y = floor(cell_y);
                    break;
                }
            case 1:
                {
                    x = ceil(cell_x);
                    y = floor(cell_y);
                    break;
                }
            case 2:
                {
                    x = floor(cell_x);
                    y = ceil(cell_y);
                    break;
                }
            case 3:
                {
                    x = ceil(cell_x);
                    y = ceil(cell_y);
                    break;
                }
            default: break;
            }
            if(checkCollectables == 0)
            {
                if(useDoor == false)
                    if(ig_level[y][x] == '3')
                        output = true;
                if(ig_level[y][x] == '1')
                    output = true;
            }
            else
            {
                if(ig_level[y][x] == '2')
                {
                    ig_level[y][x] = '0';
                    ig_SacMan.IncrementPoints();
                }
            }
        }
        return output;
    }
};