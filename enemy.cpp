#include "enemy.hpp"

void Enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
    enemySprite.scale(sf::Vector2f(1, 1));

    boundingRectangle.setSize(sf::Vector2f(size.x * enemySprite.getScale().x, size.y * enemySprite.getScale().y));
};

void Enemy::Load()
{
    if (enemyTexture.loadFromFile("assets/enemy/texture/spritesheet.png")){
        enemySprite.setTexture(enemyTexture);

        int XIndex = 0;
        int YIndex = 0;

        enemySprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        enemySprite.setPosition(sf::Vector2f(400,100));

        std::cout << "Enemy loaded" << std::endl;
    } else {
        std::cout << "Enemy not loaded" << std::endl;   
    }
};

void Enemy::Update(float deltaTime)
{
    boundingRectangle.setPosition(enemySprite.getPosition());
};

void Enemy::Draw(sf::RenderWindow *window)
{
    window->draw(enemySprite);
    window->draw(boundingRectangle);
};