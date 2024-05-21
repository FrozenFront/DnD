#ifndef EN_ct
#define EN_ct

#include <iostream>
#include <SFML/Graphics.hpp>
#include "character.hpp"

class Enemy: public Character
{
private:
    sf::Texture enemyTexture;
    sf::Text healthText;
    sf::Font font;

public:
    sf::Sprite enemySprite;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
    sf::Vector2i size_bound;


public:
    void Initialize(int hp, int mana, int level);
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow *window);
};

#endif