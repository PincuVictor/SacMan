#pragma once
#include "SacMan.hpp"
#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sys/stat.h>
#include "Global.hpp"

using namespace std;

class Level
{
public:
    static array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ConvertSketch(int lvl, SacMan& ig_SacMan)
    {
        array<string, MAP1_HEIGHT> sketch{};
        if(lvl == 1)
        {
            sketch = {
                " ################### ",
                " #........#........# ",
                " #.##.###.#.###.##.# ",
                " #.................# ",
                " #.##.#.#####.#.##.# ",
                " #....#...#...#....# ",
                " ####.###.#.###.#### ",
                "    #.#.......#.#    ",
                "#####.#.#####.#.#####",
                "........#   #........",
                "#####.#.#####.#.#####",
                "    #.#.......#.#    ",
                " ####.#.#####.#.#### ",
                " #........#........# ",
                " #.##.###.#.###.##.# ",
                " #..#.....P.....#..# ",
                " ##.#.#.#####.#.#.## ",
                " #....#...#...#....# ",
                " #.######.#.######.# ",
                " #.................# ",
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
                if(sketch[i][j] == '.')
                {
                    ig_level[i][j] = '2';
                }
                if(sketch[i][j] == 'P')
                {
                    ig_level[i][j] = '0';
                    ig_SacMan.SetPosition(static_cast<float>(j) * CELL_SIZE, static_cast<float>(i) * CELL_SIZE);
                }
            }
        }
        return ig_level;
    }

    static void DrawMap(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> &ig_level, sf::RenderWindow& window, SacMan& ig_SacMan)
    {
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        sf::CircleShape character(static_cast<float>(CELL_SIZE) / 2);
        sf::CircleShape coin(static_cast<float>(CELL_SIZE) / 5);
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
                if (ig_level[j][i] == '2')
                {
                    coin.setPosition(static_cast<float>(i) * CELL_SIZE + 3 * CELL_SIZE / 10, static_cast<float>(j) * CELL_SIZE + 3 * CELL_SIZE / 10);
                    coin.setFillColor(sf::Color::Yellow);
                    window.draw(coin);
                }
                character.setPosition(ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y);
                character.setFillColor(sf::Color::Yellow);
                window.draw(character);
            }
        }
    }
    static bool CheckCollision(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> &ig_level, SacMan &ig_SacMan, int x, int y)
    {
        bool output = false;
        const float cell_x = x / static_cast<float>(CELL_SIZE);
        const float cell_y = y / static_cast<float>(CELL_SIZE);

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
            if(ig_level[y][x] == '1')
                output = true;
            if(ig_level[y][x] == '2')
            {
                ig_level[y][x] = '0';
                ig_SacMan.IncrementPoints();
            }
        }
        return output;
    }




};