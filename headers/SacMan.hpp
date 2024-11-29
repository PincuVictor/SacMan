#pragma once
#include "Global.hpp"
#include "Map.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class SacMan
{
    int speed, maxSpeed;
    int points;
    int x, y;
public:
    void Update(Map &map);
    explicit SacMan();
    SacMan(const SacMan &other);
    void SetPosition(int _x, int _y);
    void IncrementPoints(Map &map);
    [[nodiscard]] sf::Vector2<int> GetPosition() const;
    friend std::ostream& operator<<(std::ostream& stream, const SacMan& Sac);
    SacMan& operator=(const SacMan& other);
    ~SacMan();
};