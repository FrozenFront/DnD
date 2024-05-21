#include "player.hpp"

void Player::Initialize(int hp, int mana, int level)
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
    size_bound = sf::Vector2i(16, 16);

    playerSprite.scale(sf::Vector2f(1, 1));
    speed = 0.5f;
    bulletSpeed = 0.1f;
    fireRate = 100.0f;
    fireRateTimer = 0.0f;
    damage = 10;
    this->set_level(level);
    this->set_health(hp);
    this->set_mana(mana);

    boundingRectangle.setSize(sf::Vector2f(size_bound.x * playerSprite.getScale().x, size_bound.y * playerSprite.getScale().y));
};

void Player::Load()
{
    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")){
        playerSprite.setTexture(playerTexture);

        int XIndex = 0;
        int YIndex = 2;

        playerSprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        playerSprite.setPosition(1000, 400);
        std::cout << "Player loaded" << std::endl;
    } else {
        std::cout << "Player not loaded" << std::endl;
    }
};

void Player::Update(Enemy &enemy, float deltaTime)
{
    sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1)*speed*deltaTime);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0)*speed*deltaTime);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1)*speed*deltaTime);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0)*speed*deltaTime);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, -1)*speed*deltaTime);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, -1)*speed*deltaTime);
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 1)*speed*deltaTime);
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 1)*speed*deltaTime);
        
        //---------------------------------BULLET-----------------------------
        fireRateTimer += deltaTime;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= fireRate){
            fireRateTimer = 0.0f;
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
            bullets[bullets.size()-1].setPosition(playerSprite.getPosition()+temperare);
            bullets[bullets.size()-1].setFillColor(sf::Color::Red);
        }

        for(size_t i = 0; i < bullets.size(); i++){
            bulletDirection = enemy.enemySprite.getPosition() - bullets[i].getPosition()+temperare;
            bulletDirection = Function::normalizedVector2f(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection*bulletSpeed*deltaTime);

            if(enemy.get_health() > 0)
            {
            if(Function::CheckCollision(bullets[i].getGlobalBounds(), enemy.enemySprite.getGlobalBounds())){
                bullets.erase(bullets.begin() + i);
                std::cout << "Heat, Enemy Health = " << enemy.get_health() - damage*this->get_level() << std::endl;
                enemy.set_health(- damage*this->get_level());
            };
            }
        }
        //---------------------------------BULLET-----------------------------

        boundingRectangle.setPosition(playerSprite.getPosition());
};

void Player::Draw(sf::RenderWindow *window)
{
    window->draw(playerSprite);
    for (size_t i = 0; i < bullets.size(); i++){
        window->draw(bullets[i]);
    }
    window->draw(boundingRectangle);
};