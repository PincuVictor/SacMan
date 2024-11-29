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
    explicit Engine(sf::RenderWindow &gameWindow);
    void Update();
    friend std::ostream& operator<<(std::ostream& stream, const Engine& engine);
};