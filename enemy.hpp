#ifndef EN_ct
#define EN_ct

#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture enemyTexture;

public:
    sf::Sprite enemySprite;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow *window);
};

#endif