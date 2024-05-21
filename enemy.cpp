#include "enemy.hpp"

void Enemy::Initialize(int hp, int mana, int level)
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
    size_bound = sf::Vector2i(16, 16);
    enemySprite.scale(sf::Vector2f(1, 1));

    this->set_health(hp);
    this->set_mana(mana);
    this->set_level(level);

    boundingRectangle.setSize(sf::Vector2f(size_bound.x * enemySprite.getScale().x, size_bound.y * enemySprite.getScale().y));
};

void Enemy::Load()
{   
    if (font.loadFromFile("assets/font/Arial/arialmt.ttf")){
        std::cout << "Font loaded" << std::endl;
        healthText.setFont(font);
        healthText.setCharacterSize(14);
        healthText.setFillColor(sf::Color::White);
    } else {
        std::cout << "Font not loaded" << std::endl;
    }
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
    if (get_health() > 0)
    {
    boundingRectangle.setPosition(enemySprite.getPosition());
    healthText.setString("HP: " + std::to_string(get_health()));
    healthText.setPosition(enemySprite.getPosition().x + 10, enemySprite.getPosition().y - 10);
    }
};

void Enemy::Draw(sf::RenderWindow *window)
{
    if(get_health() > 0)
    {
    window->draw(enemySprite);
    window->draw(boundingRectangle);
    window->draw(healthText);
    }
};