#include "function.hpp"

sf::Vector2f Function::normalizedVector2f(sf::Vector2f v){
    float normal = sqrt(v.x*v.x + v.y*v.y);
    sf::Vector2f normalizedV;

    normalizedV.x = v.x/normal;
    normalizedV.y = v.y/normal;

    return normalizedV;
};