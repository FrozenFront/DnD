#ifndef ti_ct
#define ti_ct

#include <iostream>
#include <SFML/Graphics.hpp>

struct Tile{
    int id = -1;
    sf::Texture* texture = nullptr;
    sf::Vector2f position;
};

#endif