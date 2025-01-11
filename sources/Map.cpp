#include "../headers/Map.hpp"

#include <iostream>

#include "../headers/MapError.hpp"

Map::Map()
{
    std::ifstream in("configs/map1");
    for (int i = 0; i < MAP1_WIDTH; i++)
    {
        for (int j = 0; j < MAP1_HEIGHT; j++)
        {
            const auto c = static_cast<unsigned char>(in.get());
            if(c == ' ' || c == '\n' || c == '|')
                map1[i][j] = '0';
            if(c == '#')
                map1[i][j] = '1';
            if(c == '.')
                map1[i][j] = '2';
            if(c == '=')
                map1[i][j] = '3';
            if(c == 'P')
                map1[i][j] = '4';
            if(c == 'B')
                map1[i][j] = '5';
        }
    }
}

[[nodiscard]] std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> Map::GetMap() const
{
    for (int i = 0; i < MAP1_WIDTH-1; i++)
    {
        for (int j = 0; j < MAP1_HEIGHT-1; j++)
        {
            if (map1[i][j] != '0' && map1[i][j] != '1' && map1[i][j] != '2' && map1[i][j] != '3' && map1[i][j] != '4'
                && map1[i][j] != '5')
                throw MapError("Caractere invalide pentru construirea hartii!");
        }
    }
    return map1;
}

bool Map::CheckCollision(const bool checkCollectables, const bool useDoor, int x, int y)
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
                x = std::floor(cell_x);
                y = std::floor(cell_y);
                break;
            }
        case 1:
            {
                x = std::ceil(cell_x);
                y = std::floor(cell_y);
                break;
            }
        case 2:
            {
                x = std::floor(cell_x);
                y = std::ceil(cell_y);
                break;
            }
        case 3:
            {
                x = std::ceil(cell_x);
                y = std::ceil(cell_y);
                break;
            }
        default: break;
        }
        if (0 <= x && 0 <= y && MAP1_HEIGHT > y && MAP1_WIDTH > x)
        {
            if(checkCollectables == false)
            {
                if(useDoor == false)
                    if(map1[y][x] == '3')
                        output = true;
                if(map1[y][x] == '1')
                    output = true;
            }
            else
            {
                if(map1[y][x] == '2')
                {
                    map1[y][x] = '0';
                    output = true;
                }
            }
        }
    }
    return output;
}
