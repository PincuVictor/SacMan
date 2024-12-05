#include "../headers/Level.hpp"

#include "../headers/EHMap.hpp"

void Level::DrawMap(std::array<std::array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_level, sf::RenderWindow& window, const SacMan& ig_SacMan, const BankerManager& ig_BankerManager)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    sf::CircleShape character(static_cast<float>(CELL_SIZE) / 2);
    sf::CircleShape coin(static_cast<float>(CELL_SIZE) / 5);
    std::array<sf::CircleShape, BANKERS_NUMBER> DrawableBankers;
    for (int i = 0; i < BANKERS_NUMBER; i++)
    {
        DrawableBankers[i] = ig_BankerManager.GetBanker(i)->GetBody();
        if (&DrawableBankers[i] == nullptr)
            throw EHMap("Nu s-au putut obtine toate corpurile Bankerilor pentru Draw!");
    }
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
            for(int k = 0; k < BANKERS_NUMBER; k++)
                window.draw(DrawableBankers[k]);
            character.setPosition(static_cast<float>(ig_SacMan.GetPosition().x), static_cast<float>(ig_SacMan.GetPosition().y));
            character.setFillColor(sf::Color::Yellow);
            window.draw(character);
        }
    }
}
