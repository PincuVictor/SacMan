#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "env_fixes.h"

using namespace std;
constexpr unsigned char MAP1_HEIGHT = 21;

class SacMan
  {
    int speed, maxSpeed, points;
    public:
      SacMan(const int _speed, const int _maxSpeed, const int _points)
      {
        points = _points;
        speed = _speed;
        maxSpeed = _maxSpeed;
      }
      friend std::ostream& operator<<(std::ostream& stream, const SacMan& Sac)
      {
          stream << "Speed: " << Sac.speed << endl;
          stream << "Max Speed: " << Sac.maxSpeed << endl;
          stream << "Points: " << Sac.points << endl;
          return stream;
        }
      SacMan& operator=(const SacMan& Sac)
        = default;
      ~SacMan() = default;
  };

class Ghost
  {
    int speed, maxSpeed;
    public:
      Ghost(const int _speed, const int _maxSpeed)
      {
        speed = _speed;
        maxSpeed = _maxSpeed;
      }
      friend std::ostream& operator<<(std::ostream& stream, const Ghost& G)
      {
        stream << "Speed: " << G.speed << endl;
        stream << "Max Speed: " << G.maxSpeed << endl;
        return stream;
      }
      Ghost& operator=(const Ghost& G)
      = default;
      ~Ghost() = default;
  };

class Level
  {
    SacMan Sac{5, 10, 0};
    Ghost B1{5, 10};
    Ghost B2{5, 10};
    Ghost B3{5, 10};
    Ghost B4{5, 10};
    array<string, MAP1_HEIGHT> map1_sketch = {
      "#################",
      "#               #",
      "#               #",
      "#               #",
      "#               #",
      "#               #",
      "#    #     #    #",
      "#               #",
      "#    #     #    #",
      "#     #####     #",
      "#               #",
      "#               #",
      "#               #",
      "#               #",
      "#               #",
      "#               #",
      "#################",
    };

  };

  class Drawer
  {
    Level L1{};
  };

int main()
{
  init_threads();
  sf::Window window(sf::VideoMode(800, 600), "SacMan");
  window.setFramerateLimit(60);
  while(window.isOpen()) {
    bool shouldExit = false;
    sf::Event e{};
    while(window.pollEvent(e)) {
      switch(e.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::Resized:
        std::cout << "New width: " << window.getSize().x << '\n'
                  << "New height: " << window.getSize().y << '\n';
        break;
      case sf::Event::KeyPressed:
        std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
        if(e.key.code == sf::Keyboard::Escape)
          shouldExit = true;
        break;
      default:
        break;
      }
    }
    if(shouldExit) {
      window.close();
      break;
    }
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(300ms);
    window.display();
  }




  Helper helper;
  helper.help();
  return 0;
}
