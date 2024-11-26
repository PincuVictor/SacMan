#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "SacMan.hpp"
#include "Banker.hpp"
#include "Level.hpp"
#include "Smungu.hpp"
#include "BankerManager.hpp"

class Engine
{
    Map map{};
    SacMan ig_SacMan{};
    BankerManager ig_BankerManager{};
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
                        ig_BankerManager.CallSetPosition(i * CELL_SIZE, j * CELL_SIZE);
                }
            }
        }
        void Update()
        {
            ig_SacMan.Update(map);
            ig_BankerManager.CallUpdate(map, ig_SacMan);
            Level::DrawMap(this->map.GetMap(1), window, ig_SacMan, ig_BankerManager);
        }
    friend std::ostream& operator<<(std::ostream& stream, const Engine& engine)
        {
            stream << "SacMan: " << engine.ig_SacMan;
            stream << "BankerManager: " << engine.ig_BankerManager;
            return stream;
        }
};