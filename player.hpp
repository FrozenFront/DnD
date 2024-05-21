#ifndef PL_ct
#define PL_ct
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.hpp"
#include "function.hpp"


class Player
{
private:
    sf::Texture playerTexture;
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    sf::Vector2f temperare = sf::Vector2f(32, 32);
    float bulletSpeed = 0.1f;


public:
    sf::Sprite playerSprite;


public:
    void Initialize();
    void Load();
    void Update(Enemy &enemy);
    void Draw(sf::RenderWindow *window);
};

#endif