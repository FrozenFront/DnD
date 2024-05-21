#ifndef bu_ct
#define bu_ct

#include <iostream>
#include <SFML/Graphics.hpp>
#include "function.hpp"

class Bullet{
public:
    float speed;
    sf::Vector2f temperare;


private:
    sf::RectangleShape bulletShape;
    sf::Vector2f bulletDirection;
    

public:
    Bullet();
    ~Bullet();

    void Initialize(const sf::Vector2f position, sf::Vector2f direction, float speed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow *window);

    inline const sf::FloatRect GetGlobalBounds() { return bulletShape.getGlobalBounds(); }
};


#endif