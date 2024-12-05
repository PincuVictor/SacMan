#include "../headers/Engine.hpp"

#include <iostream>

#include "../headers/EHMap.hpp"
#include "../headers/EHSacMan.hpp"

Engine::Engine(sf::RenderWindow &gameWindow) : window(gameWindow)
{
    try
    {
        ig_map = this->map.GetMap(1);
    }
    catch (EHMap &error)
    {
        std::cout << "Eroare Harta: " << error.what() << std::endl;
    }
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
    try
    {
        ig_SacMan.Update(map);
    }
    catch (EHSacMan &error)
    {
        std::cout << "Eroare SacMan: " << error.what() << std::endl;
    }
    ig_BankerManager.CallUpdate(map, ig_SacMan);
    try
    {
        Level::DrawMap(this->map.GetMap(1), window, ig_SacMan, ig_BankerManager);
    }
    catch (EHMap &error)
    {
        std::cout << "Eroare Harta: " << error.what() << std::endl;
    }

}

std::ostream& operator<<(std::ostream& stream, const Engine& engine)
{
    stream << "SacMan: " << engine.ig_SacMan;
    stream << "BankerManager: " << engine.ig_BankerManager;
    return stream;
}