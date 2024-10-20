#include <iostream>
#include <array>
#include <Helper.h>
#include <chrono>

using namespace std;
constexpr unsigned char MAP1_HEIGHT = 21, MAP1_WIDTH = 21, MAP2_HEIGHT = 21, MAP2_WIDTH = 21;

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

  };

class Level
  {
    SacMan SacMan{5, 10, 0};
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
