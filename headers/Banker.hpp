#pragma once
#include <memory>
#include <random>
#include "Map.hpp"
#include "SacMan.hpp"
#include "SFML/Graphics.hpp"

class Banker
{
    int speed, x, y, targetx, targety;
    bool useDoor = true;
    sf::CircleShape body;
    virtual void ImplUpdate(Map &map, SacMan &ig_SacMan) = 0;
    virtual void ImplChase(Map &map) = 0;
    [[nodiscard]] virtual std::shared_ptr<Banker> ImplClone() const = 0;
public:
    /// șpârga, șmârga, șbungu, șmungu
    /// cand incep sa urmareasca sacu "ai-u" e ca se verifica cat ar fi distanta pana la sac daca ar lua o in fiecare din directiile posibile
    /// șpârga se plimba random mai incet ca ceilalti 0.5, cand e destul de apropiat fugareste cu 1.1 pt cateva secunde
    /// smarga isi alege cate un sfert din harta pe care sa-l patruleze pentru un nr de secunde, fugareste in apropiere
    /// sbungu isi alege un colt al hartii pana in care se duce, cand ajunge acolo isi alege altu, fugareste in apropiere
    /// smungu se plimba random nu fugareste
    /// clase derivate prin mostenire de la banker
    void Update(Map &map, SacMan &ig_SacMan);
    void Chase(Map &map);
    [[nodiscard]] std::shared_ptr<Banker> Clone() const;
    void SetTarget(int _x, int _y);
    void GetOut();
    void SetPosition(int _x, int _y);
    void SetSpeed(int s);
    void SetBody(float radius, sf::Color color, float _x, float _y);
    void SetBodyPosition(float _x, float _y);
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
