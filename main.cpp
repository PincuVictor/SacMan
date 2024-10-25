#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace std;

class SacMan
  {
    int speed, maxSpeed, points;
    public:
      void characterMovement(sf::CircleShape &character)
      {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          character.move(0, speed);
        }

      }
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

class Banker
  {
    int speed, maxSpeed;
    public:
      Banker(const int _speed, const int _maxSpeed)
      {
        speed = _speed;
        maxSpeed = _maxSpeed;
      }
      friend std::ostream& operator<<(std::ostream& stream, const Banker& G)
      {
        stream << "Speed: " << G.speed << endl;
        stream << "Max Speed: " << G.maxSpeed << endl;
        return stream;
      }
      Banker& operator=(const Banker& G)
      = default;
      ~Banker() = default;
  };

class Level
  {
    constexpr static char MAP1_HEIGHT = 21, MAP1_WIDTH = 21;
    SacMan Sac{5, 10, 0};
    Banker B1{5, 10};
    Banker B2{5, 10};
    Banker B3{5, 10};
    Banker B4{5, 10};
    array<string, MAP1_HEIGHT> map1_sketch = {
      " ################### ",
      " #        #        # ",
      " # ## ### # ### ## # ",
      " #                 # ",
      " # ## # ##### # ## # ",
      " #    #   #   #    # ",
      " #### ### # ### #### ",
      "    # #       # #    ",
      "##### # ##### # #####",
      "        #   #        ",
      "##### # ##### # #####",
      "    # #       # #    ",
      " #### # ##### # #### ",
      " #        #        # ",
      " # ## ### # ### ## # ",
      " #  #     P     #  # ",
      " ## # # ##### # # ## ",
      " #    #   #   #    # ",
      " # ###### # ###### # ",
      " #                 # ",
      " ################### "
      };
  public:
        void convertSketch(sf::RenderWindow& window) const
        {
          unsigned int width = window.getSize().x;
          float CELL_SIZE = static_cast<float>(width) / MAP1_WIDTH;
          sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
          sf::CircleShape character(CELL_SIZE / 2);
          for (int i = 0; i <= MAP1_WIDTH; i++)
          {
            for (int j = 0; j < MAP1_HEIGHT; j++)
            {
              if (map1_sketch[j][i] == '#')
              {
                cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);
                cell.setFillColor(sf::Color::Blue);
                window.draw(cell);
              }
              if(map1_sketch[j][i] == 'P')
              {
                character.setPosition(i * CELL_SIZE, j * CELL_SIZE);
                character.setFillColor(sf::Color::Yellow);
                window.draw(character);
              }

            }
          }

        }

  };

int main()
{
  Level L1{};
  sf::RenderWindow window(sf::VideoMode(800, 800), "SacMan");
  window.setFramerateLimit(60);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::Black);
    L1.convertSketch(window);
    window.display();
  }

  Helper helper;
  helper.help();
  return 0;
}
