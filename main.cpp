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
  sf::Clock clock;
  sf::Time frameTime;
  window.setFramerateLimit(60);
  SacMan ig_SacMan{5, 10, 0};
  array<array<unsigned char, 21>, 21> ig_map = Level::ConvertSketch(1, ig_SacMan);
  while (window.isOpen())
  {
    sf::Time elapsed = clock.restart();
    sf::Event event{};
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
        window.close();
    }


    ig_SacMan.Update(elapsed);cout << ig_SacMan.GetPosition().x << endl;
    window.clear(sf::Color::Black);
    Level::DrawMap(ig_map, window, ig_SacMan);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
