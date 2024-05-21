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

public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow *window);
};

#endif