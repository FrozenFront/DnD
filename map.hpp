#ifndef ma_ct
#define ma_ct

#include <iostream>
#include <SFML/Graphics.hpp>


class Map{
private:
    sf::Texture mapTexture;
    sf::Sprite mapSprites[10];
    
    int tileWidth;
    int tileHeight;

    int totalTilesX;
    int totalTilesY;

public: 
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow *window);
};

#endif