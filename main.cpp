#include <iostream>
#include <array>
#include <Helper.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/SacMan.hpp"
#include "headers/Level.hpp"
#include "headers/Banker.hpp"
#include "headers/MapCollisions.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 840), "SacMan", sf::Style::Close | sf::Style::Titlebar);
  window.setFramerateLimit(FRAME_RATE);
  SacMan ig_SacMan{};
  Banker Banker{};
  bool dir[4];
  int oppDir = 1;
  array<array<unsigned char, MAP1_HEIGHT>, MAP1_WIDTH> ig_map = Level::ConvertSketch(1, ig_SacMan, Banker);
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
    MapCollisions::CheckCollision(true, false, ig_map, ig_SacMan, ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y);
    dir[0] = MapCollisions::CheckCollision(false, false, ig_map, ig_SacMan, ig_SacMan.GetPosition().x + 2, ig_SacMan.GetPosition().y);
    dir[1] = MapCollisions::CheckCollision(false, false, ig_map, ig_SacMan, ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y + 2);
    dir[2] = MapCollisions::CheckCollision(false, false, ig_map, ig_SacMan, ig_SacMan.GetPosition().x - 2, ig_SacMan.GetPosition().y);
    dir[3] = MapCollisions::CheckCollision(false, false, ig_map, ig_SacMan, ig_SacMan.GetPosition().x, ig_SacMan.GetPosition().y - 2);
    cout << endl;
    ig_SacMan.Update(dir);
    Banker.UpdateG(ig_map, ig_SacMan, oppDir);
    Level::DrawMap(ig_map, window, ig_SacMan, Banker);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
