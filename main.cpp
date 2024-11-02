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
  bool dir[4];
  while (window.isOpen())
  {
    sf::Time elapsed = clock.restart();
    sf::Event event{};
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    if(ig_map[static_cast<int>(ig_SacMan.GetPosition().y)][static_cast<int>(ig_SacMan.GetPosition().x) - 1] == '1') // stanga
      dir[0] = true;
    else
      dir[0] = false;
    if(ig_map[static_cast<int>(ig_SacMan.GetPosition().y)][static_cast<int>(ig_SacMan.GetPosition().x + 1)] == '1') // dreapta
      dir[1] = true;
    else
      dir[1] = false;
    if(ig_map[static_cast<int>(ig_SacMan.GetPosition().y) - 1][static_cast<int>(ig_SacMan.GetPosition().x)] == '1') // jos
      dir[2] = true;
    else
      dir[2] = false;
    if(ig_map[static_cast<int>(ig_SacMan.GetPosition().y) + 1][static_cast<int>(ig_SacMan.GetPosition().x)] == '1') // sus
      dir[3] = true;
    else
      dir[3] = false;
    cout << ig_map[static_cast<int>(ig_SacMan.GetPosition().y)][static_cast<int>(ig_SacMan.GetPosition().x)] << " " << static_cast<int>(ig_SacMan.GetPosition().x) << " " << static_cast<int>(ig_SacMan.GetPosition().y) << endl;
    //cout << dir[0] << " " << dir[1] << " " << dir[2] << " " << dir[3] << endl;
    ig_SacMan.Update(elapsed, dir);
    Level::DrawMap(ig_map, window, ig_SacMan);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
