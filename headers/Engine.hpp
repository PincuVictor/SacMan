#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "SacMan.hpp"
#include "Banker.hpp"
#include "Level.hpp"
#include "Smungu.hpp"

class Engine
{
    Map map{};
    SacMan ig_SacMan{};
    Smungu ig_Smungu{};
    sf::RenderWindow& window;
    std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_map{};
    public:
        explicit Engine(sf::RenderWindow &gameWindow) : window(gameWindow)
        {
            ig_map = this->map.GetMap(1);
            for(int i = 0; i < MAP1_HEIGHT; i++)
            {
                for(int j = 0; j < MAP1_WIDTH; j++)
                {
                    if(ig_map[j][i] == '4')
                        ig_SacMan.SetPosition(i * CELL_SIZE, j * CELL_SIZE);
                    if(ig_map[j][i] == '5')
                        ig_Smungu.SetPosition(i * CELL_SIZE, j * CELL_SIZE);
                }
            }
        }
        void Update()
        {
            ig_SacMan.Update(map);
            ig_Smungu.Update(map);
            Level::DrawMap(this->map.GetMap(1), window, ig_SacMan, ig_Smungu);
        }
};