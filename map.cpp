#include "map.hpp"

Map::Map():
    tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0)
{
};

Map::~Map(){  
};
void Map::Initialize()
{
};

void Map::Load()
{
    if(mapTexture.loadFromFile("assets/world/dungeon/tilesheet.png")){
        totalTilesX = mapTexture.getSize().x / tileWidth;
        totalTilesY = mapTexture.getSize().y / tileHeight;

        std::cout << "Map loaded" << std::endl;

        for(int i = 0; i < 10; i++){
            mapSprites[i].setTexture(mapTexture);
            mapSprites[i].setTextureRect(sf::IntRect(i * tileWidth, i*tileHeight, tileWidth, tileHeight));
            mapSprites[i].setScale(sf::Vector2f(5, 5));
            mapSprites[i].setPosition(sf::Vector2f(100 + i * tileWidth * 5, 100));
        }
    } else {
        std::cout << "Map not loaded" << std::endl;
    }
};

void Map::Update(float deltaTime)
{
};
void Map::Draw(sf::RenderWindow *window)
{
    for(int i = 0; i < 10; i++){
        window->draw(mapSprites[i]);
    }
};


