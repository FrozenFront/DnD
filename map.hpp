#ifndef ma_ct
#define ma_ct

#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.hpp"


class Map{
private:
    sf::Texture tileSheetTexture;
    Tile* tiles;
    
    int tileWidth;
    int tileHeight;

    int totalTilesX;
    int totalTilesY;

    int mapIds[6] = {1,1,1,25,27,30};

    sf::Sprite mapSprites[6];

public: 
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow *window);
};

#endif