#ifndef FU_ct
#define FU_ct

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

class Function{
    public:
        static sf::Vector2f normalizedVector2f(sf::Vector2f v);
        static bool CheckCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

#endif