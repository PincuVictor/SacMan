#pragma once
#include "SacMan.hpp"
#include "Banker.hpp"
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Level
{
    constexpr static char MAP1_HEIGHT = 21, MAP1_WIDTH = 21;

public:
    static array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ConvertSketch(int lvl, SacMan& ig_SacMan)
    {
        array<string, MAP1_HEIGHT> sketch{};
        if(lvl == 1)
        {
            sketch = {
                " ################### ",
                " #        #        # ",
                " # ## ### # ### ## # ",
                " #                 # ",
                " # ## # ##### # ## # ",
                " #    #   #   #    # ",
                " #### ### # ### #### ",
                "    # #       # #    ",
                "##### # ##### # #####",
                "        #   #        ",
                "##### # ##### # #####",
                "    # #       # #    ",
                " #### # ##### # #### ",
                " #        #        # ",
                " # ## ### # ### ## # ",
                " #  #     P     #  # ",
                " ## # # ##### # # ## ",
                " #    #   #   #    # ",
                " # ###### # ###### # ",
                " #                 # ",
                " ################### "
                };
        }
        array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level{};
        for (int i = 0; i < MAP1_HEIGHT; i++)
        {
            for (int j = 0; j < MAP1_WIDTH; j++)
            {
                if (sketch[i][j] == '#')
                {
                    ig_level[i][j] = '1';
                }
                if(sketch[i][j] == ' ')
                {
                    ig_level[i][j] = '0';
                }
                if(sketch[i][j] == 'P')
                {
                    ig_SacMan.SetPosition(i, j);
                }
            }
        }
        return ig_level;
    }
    static void DrawMap(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, sf::RenderWindow& window)
    {
        unsigned int width = window.getSize().x;
        float CELL_SIZE = static_cast<float>(width) / MAP1_WIDTH;
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        sf::CircleShape character(CELL_SIZE / 2);
        for (int i = 0; i < MAP1_HEIGHT; i++)
        {
            for (int j = 0; j < MAP1_WIDTH; j++)
            {
                if (ig_level[j][i] == '1')
                {
                    cell.setPosition(static_cast<float>(i) * CELL_SIZE, static_cast<float>(j) * CELL_SIZE);
                    cell.setFillColor(sf::Color::Blue);
                    window.draw(cell);
                }

            }
        }
    }

};