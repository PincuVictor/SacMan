#include <iostream>
#include <array>
#include <Helper.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/Engine.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 840), "SacMan", sf::Style::Close | sf::Style::Titlebar);
  window.setFramerateLimit(FRAME_RATE);
  Engine engine{window};
  while (window.isOpen())
  {
    sf::Event event{};
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::Black);
    engine.Update();
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}