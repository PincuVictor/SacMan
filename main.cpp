#include <iostream>
#include <array>
#include <Helper.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/SacMan.hpp"
#include "headers/Level.hpp"
#include "headers/Banker.hpp"
#include "headers/Map.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 840), "SacMan", sf::Style::Close | sf::Style::Titlebar);
  window.setFramerateLimit(FRAME_RATE);
  Map map{};
  SacMan ig_SacMan{};
  Banker Banker{};
  int oppDir = 1;
  array<array<unsigned char, MAP1_WIDTH>, MAP1_HEIGHT> ig_map{};
  ig_map = map.GetMap(1);
  for(int i = 0; i < MAP1_WIDTH; ++i)
  {
    for(int j = 0; j < MAP1_HEIGHT; ++j)
    {
      if(ig_map[j][i] == '4')
        ig_SacMan.SetPosition(i * CELL_SIZE, j * CELL_SIZE);
      if(ig_map[j][i] == '5')
        Banker.SetPosition(i * CELL_SIZE, j * CELL_SIZE);
    }
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
    ig_SacMan.Update(map);
    //Banker.UpdateG(map.GetMap(1), ig_SacMan, oppDir);
    Level::DrawMap(map.GetMap(1), window, ig_SacMan, Banker);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
