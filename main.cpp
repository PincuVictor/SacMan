#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>

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




  Helper helper;
  helper.help();
  return 0;
}
