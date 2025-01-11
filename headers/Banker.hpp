#pragma once
#include <memory>
#include <random>
#include "Map.hpp"
#include "SacMan.hpp"
#include <SFML/Graphics.hpp>

class Banker
{
    int speed, x, y, targetx, targety;
    bool useDoor = true;
    sf::CircleShape body;
    virtual void ImplUpdate(Map &map, SacMan &ig_SacMan) = 0;
    [[nodiscard]] virtual std::shared_ptr<Banker> ImplClone() const = 0;
protected:
    void SetSpeed(int s);
    void SetBody(float radius, sf::Color color, float _x, float _y);
    void SetBodyPosition(float _x, float _y);
    void SetTarget(int _x, int _y);
public:
    void Update(Map &map, SacMan &ig_SacMan);
    int Chase(Map &map, int dir);
    [[nodiscard]] std::shared_ptr<Banker> Clone() const;
    int RandomDirSelect(int dir, Map &map, int boundarylx, int boundaryrx, int boundaryly, int boundaryry);
    void SetPosition(int _x, int _y);
    void GetOut();
    sf::CircleShape GetBody();
    int GetSpeed() const;
    [[nodiscard]] sf::Vector2<int> GetPosition() const;
    [[nodiscard]] sf::Vector2<int> GetTarget() const;
    Banker();
    Banker(const Banker& other);
    friend std::ostream& operator<<(std::ostream& stream, const Banker& B);
    Banker& operator=(const Banker& other);
    virtual ~Banker();
};
