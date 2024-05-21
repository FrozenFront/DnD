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
    if(tileSheetTexture.loadFromFile("assets/world/dungeon/tilesheet.png")){

        std::cout << "Map loaded" << std::endl;

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        tiles = new Tile[totalTilesX*totalTilesY];

        for(int y = 0; y < totalTilesY; y++){
            for(int x = 0; x < totalTilesX; x++){
                int i = x+y*totalTilesX;
                tiles[i].id = i;
                tiles[i].position = sf::Vector2f(x*tileWidth, y*tileHeight);
            }
        }
    } else {
        std::cout << "Map not loaded" << std::endl;
    }

    for (int y = 0; y<2; y++){
        for (int x = 0; x<3;x++){
            int i = x+y*3;
            int index = mapIds[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x,
                tiles[index].position.y,
                tileWidth,
                tileHeight));

            mapSprites[i].setScale(sf::Vector2f(5, 5));
            mapSprites[i].setPosition(sf::Vector2f(x*16*5, y*16*5));
        }
    }
};

void Map::Update(float deltaTime)
{
};
void Map::Draw(sf::RenderWindow *window)
{
    for(int i = 0; i < 6; i++){
        window->draw(mapSprites[i]);
    }
};


