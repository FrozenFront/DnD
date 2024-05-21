#ifndef PL_ct
#define PL_ct
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.hpp"
#include "function.hpp"
#include "character.hpp"



class Player: public Character
{
private:
    sf::Texture playerTexture;
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    sf::Vector2f temperare = sf::Vector2f(32, 32);
    sf::Vector2i size_bound;
    sf::Vector2i size;
    sf::RectangleShape boundingRectangle;
    float bulletSpeed;
    float speed;
    float fireRate;
    float fireRateTimer;
    int damage;

public:
    sf::Sprite playerSprite;


public:
    void Initialize(int hp, int mana, int level);
    void Load();
    void Update(Enemy &enemy, float deltaTime);
    void Draw(sf::RenderWindow *window);
};

#endif