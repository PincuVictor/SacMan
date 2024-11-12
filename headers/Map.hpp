#pragma once
#include <array>
#include <fstream>

#include "Global.hpp"
#include "Level.hpp"

using namespace std;


class Map
{
    array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> map1;
    array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> map2;
    array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> map3;
    public:
    Map()
    {
        array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> sketch{};
        char c;
        for (int i = 0; i < MAP1_HEIGHT; i++)
        {
            for (int j = 0; j < MAP1_WIDTH; j++)
            {
                if(c != '\n')
                    sketch[i][j] = c;
            }
        }
        for (int i = 0; i < MAP1_HEIGHT; i++)
        {
            for (int j = 0; j < MAP1_WIDTH; j++)
            {
                if (sketch[i][j] == '#')
                {
                    map1[i][j] = '1';
                }
                if(sketch[i][j] == ' ')
                {
                    map1[i][j] = '0';
                }
                if(sketch[i][j] == '.')
                {
                    map1[i][j] = '2';
                }
                if(sketch[i][j] == 'P')
                {
                    map1[i][j] = '0';
                }
                if(sketch[i][j] == 'F')
                {
                    map1[i][j] = '0';
                }
                if(sketch[i][j] == '=')
                {
                    map1[i][j] = '3';
                }
            }
        }
    }

    array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> GetMap(const int lvl)
    {
        if(lvl == 1)
            return map1;
    }
};
