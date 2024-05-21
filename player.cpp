#include "player.hpp"

void Player::Initialize()
{
};

void Player::Load()
{
    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")){
        playerSprite.setTexture(playerTexture);

        int XIndex = 0;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.setPosition(1000, 400);
        std::cout << "Player loaded" << std::endl;
    } else {
        std::cout << "Player not loaded" << std::endl;
    }
};

void Player::Update(Enemy &enemy)
{
    sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(0.1f, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-0.1f, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(0.1f, -0.1f));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-0.1f, -0.1f));
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(0.1f, 0.1f));
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-0.1f, 0.1f));
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
            bullets[bullets.size()-1].setPosition(playerSprite.getPosition()+temperare);
            bullets[bullets.size()-1].setFillColor(sf::Color::Red);

            bulletDirection = enemy.enemySprite.getPosition() - playerSprite.getPosition();
            bulletDirection = Function::normalizedVector2f(bulletDirection);
        }

        for(size_t i = 0; i < bullets.size(); i++){
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection*bulletSpeed);
        }
};

void Player::Draw(sf::RenderWindow *window)
{
    window->draw(playerSprite);
    for (size_t i = 0; i < bullets.size(); i++){
        window->draw(bullets[i]);
    }
};