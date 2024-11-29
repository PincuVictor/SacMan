#include "../headers/Level.hpp"

void Level::DrawMap(std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, sf::RenderWindow& window, const SacMan& ig_SacMan, const BankerManager& ig_BankerManager)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    sf::CircleShape character(static_cast<float>(CELL_SIZE) / 2);
    sf::CircleShape coin(static_cast<float>(CELL_SIZE) / 5);
    sf::CircleShape smungu(static_cast<float>(CELL_SIZE) / 2);
    sf::CircleShape sbungu(static_cast<float>(CELL_SIZE) / 2);
    sf::CircleShape sparga(static_cast<float>(CELL_SIZE) / 2);
    sf::CircleShape smarga(static_cast<float>(CELL_SIZE) / 2);

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
            if(ig_level[j][i] == '3')
            {
                cell.setPosition(static_cast<float>(i) * CELL_SIZE, static_cast<float>(j) * CELL_SIZE);
                cell.setFillColor(sf::Color::Red);
                window.draw(cell);
            }
            sbungu.setPosition(static_cast<float>(ig_BankerManager.GetBanker(0)->GetPosition().x), static_cast<float>(ig_BankerManager.GetBanker(0)->GetPosition().y));
            sbungu.setFillColor(sf::Color::Green);
            window.draw(sbungu);
            smungu.setPosition(static_cast<float>(ig_BankerManager.GetBanker(1)->GetPosition().x), static_cast<float>(ig_BankerManager.GetBanker(1)->GetPosition().y));
            smungu.setFillColor(sf::Color::Red);
            window.draw(smungu);
            sparga.setPosition(static_cast<float>(ig_BankerManager.GetBanker(2)->GetPosition().x), static_cast<float>(ig_BankerManager.GetBanker(2)->GetPosition().y));
            sparga.setFillColor(sf::Color::Cyan);
            window.draw(sparga);
            smarga.setPosition(static_cast<float>(ig_BankerManager.GetBanker(3)->GetPosition().x), static_cast<float>(ig_BankerManager.GetBanker(3)->GetPosition().y));
            smarga.setFillColor(sf::Color::Magenta);
            window.draw(smarga);
            character.setPosition(static_cast<float>(ig_SacMan.GetPosition().x), static_cast<float>(ig_SacMan.GetPosition().y));
            character.setFillColor(sf::Color::Yellow);
            window.draw(character);
        }
    }
}