#include "enemy.hpp"

void Enemy::Initialize()
{
};

void Enemy::Load()
{
    if (enemyTexture.loadFromFile("assets/enemy/texture/spritesheet.png")){
        enemySprite.setTexture(enemyTexture);

        int XIndex = 0;
        int YIndex = 0;

        enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        enemySprite.setPosition(sf::Vector2f(400,100));

        std::cout << "Enemy loaded" << std::endl;
    } else {
        std::cout << "Enemy not loaded" << std::endl;   
    }
};

void Enemy::Update()
{
};

void Enemy::Draw(sf::RenderWindow *window)
{
    window->draw(enemySprite);
};