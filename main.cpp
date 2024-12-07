#include <iostream>
#include <Helper.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "headers/BankerError.hpp"
#include "headers/MapError.hpp"
#include "headers/SacManError.hpp"
#include "headers/Engine.hpp"

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 840), "SacMan", sf::Style::Close | sf::Style::Titlebar);
  window.setFramerateLimit(FRAME_RATE);
  try
  {
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
  }
  catch (BankerError &e)
  {
    std::cout << "Banker error: " << e.what() << '\n';
  } catch(MapError &e)
  {
    std::cout << "Map error: " << e.what() << '\n';
  } catch(SacManError &e)
  {
    std::cout << "SacMan error: " << e.what() << '\n';
  }

  Helper helper;
  helper.help();
  return 0;
}