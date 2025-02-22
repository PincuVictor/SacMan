#include "../headers/Engine.hpp"

#include <iostream>

Engine::Engine(sf::RenderWindow &gameWindow) : window(gameWindow)
{
    ig_map = this->map.GetMap();
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

void Engine::Update()
{
    ig_SacMan.Update(map);
    ig_BankerManager.CallUpdate(map, ig_SacMan);
    Level::DrawMap(this->map.GetMap(), window, ig_SacMan, ig_BankerManager);
}

std::ostream& operator<<(std::ostream& stream, const Engine& engine)
{
    stream << "SacMan: " << engine.ig_SacMan;
    stream << "BankerManager: " << engine.ig_BankerManager;
    return stream;
}