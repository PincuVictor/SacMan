#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "headers/SacMan.hpp"
#include "headers/Banker.hpp"
#include "headers/Level.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "SacMan");
  window.setFramerateLimit(60);
  SacMan ig_SacMan{5, 10, 0};
  while (window.isOpen())
  {
    sf::Event event{};
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::Black);
    Level::DrawMap(Level::ConvertSketch(1, ig_SacMan), window);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
