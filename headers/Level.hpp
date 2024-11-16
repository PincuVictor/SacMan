#pragma once
#include "SacMan.hpp"
#include "Banker.hpp"
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Global.hpp"

using namespace std;

class Level
{
public:
    static void DrawMap(array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, sf::RenderWindow& window, const SacMan& ig_SacMan, const Banker& ig_Banker)
    {
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        sf::CircleShape character(static_cast<float>(CELL_SIZE) / 2);
        sf::CircleShape coin(static_cast<float>(CELL_SIZE) / 5);
        sf::CircleShape banker(static_cast<float>(CELL_SIZE) / 2);

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
                    coin.setPosition(static_cast<float>(i) * CELL_SIZE + 3.0f * CELL_SIZE / 10.0f, static_cast<float>(j) * CELL_SIZE + 3.0f * CELL_SIZE / 10.0f);
                    coin.setFillColor(sf::Color::Yellow);
                    window.draw(coin);
                }
                banker.setPosition(static_cast<float>(ig_Banker.GetPosition().x), static_cast<float>(ig_Banker.GetPosition().y));
                banker.setFillColor(sf::Color::Green);
                window.draw(banker);
                character.setPosition(static_cast<float>(ig_SacMan.GetPosition().x), static_cast<float>(ig_SacMan.GetPosition().y));
                character.setFillColor(sf::Color::Yellow);
                window.draw(character);
            }
        }
    }

};