#include "function.hpp"

sf::Vector2f Function::normalizedVector2f(sf::Vector2f v){
    float normal = sqrt(v.x*v.x + v.y*v.y);
    sf::Vector2f normalizedV;

    normalizedV.x = v.x/normal;
    normalizedV.y = v.y/normal;

    return normalizedV;
};

bool Function::CheckCollision(sf::FloatRect rect1, sf::FloatRect rect2){
    if(
        rect1.left + rect1.width > rect2.left &&
        rect2.left + rect2.width > rect1.left &&
        rect1.top + rect1.height > rect2.top &&
        rect2.top + rect2.height > rect1.top
    ) return true; 
    else return false;
}