#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/SacMan.hpp"
#include "headers/Level.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(840, 840), "SacMan", sf::Style::Close | sf::Style::Titlebar);
  sf::Clock clock;
  window.setFramerateLimit(FRAME_RATE);
  SacMan ig_SacMan{FRAME_RATE / 1000.0f};
  bool dir[4];
  array<array<unsigned char, MAP1_HEIGHT>, MAP1_WIDTH> ig_map = Level::ConvertSketch(1, ig_SacMan);
  for(int i = 0; i < MAP1_HEIGHT; i++)
  {
    for(int j = 0; j < MAP1_WIDTH; j++)
      cout << ig_map[i][j];
    cout << endl;
  }
  while (window.isOpen())
  {
    sf::Event event{};
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
    dir[0] = Level::CheckCollision(ig_map, ig_SacMan.GetPosition().x + 1, ig_SacMan.GetPosition().y);
    dir[1] = Level::CheckCollision(ig_map, ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y + 1);
    dir[2] = Level::CheckCollision(ig_map, ig_SacMan.GetPosition().x - 1, ig_SacMan.GetPosition().y);
    dir[3] = Level::CheckCollision(ig_map, ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y - 1);
    cout << endl;
    ig_SacMan.Update(dir);
    Level::DrawMap(ig_map, window, ig_SacMan);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
