#pragma once
#include "SacMan.hpp"
#include "BankerManager.hpp"
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Global.hpp"

class Level
{
public:
    static void DrawMap(std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, sf::RenderWindow& window, const SacMan& ig_SacMan, const BankerManager& ig_BankerManager);
};