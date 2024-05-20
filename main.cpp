#include "main.hpp"

sf::Vector2f normalizedVector2f(sf::Vector2f v){
    float normal = sqrt(v.x*v.x + v.y*v.y);
    sf::Vector2f normalizedV;

    normalizedV.x = v.x/normal;
    normalizedV.y = v.y/normal;

    return normalizedV;
}

int main()
{
    //-------------------------------- initialization --------------------------------
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DnD", sf::Style::Default);

    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    sf::Vector2f temperare = sf::Vector2f(32, 32);
    //-------------------------------- initialization --------------------------------

    //-------------------------------- Load --------------------------------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    if (enemyTexture.loadFromFile("assets/enemy/texture/spritesheet.png")){
        enemySprite.setTexture(enemyTexture);
        int XIndex = 0;
        int YIndex = 0;
        enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        enemySprite.setPosition(sf::Vector2f(400,100));
    }
    
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")){
        playerSprite.setTexture(playerTexture);
        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.setPosition(1000, 400);
    }

    //-------------------------------- calculate direction of bullet --------------------------------
    // sf::Vector2f dir = enemySprite.getPosition() - playerSprite.getPosition();
    // sf::Vector2f bulletDirectioin = normalizedVector2f(dir);
    float bulletSpeed = 0.1f;
    //-------------------------------- calculate direction of bullet --------------------------------

    // bullet.setPosition(playerSprite.getPosition());
    //main loop
    while (window.isOpen())
    {
        //-------------------------------- Update --------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = playerSprite.getPosition();

        // bullet.setPosition(bullet.getPosition()+bulletDirectioin*bulletSpeed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(0.1f, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-0.1f, 0));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
            bullets[bullets.size()-1].setPosition(playerSprite.getPosition()+temperare);

            bulletDirection = enemySprite.getPosition() - playerSprite.getPosition();
            bulletDirection = normalizedVector2f(bulletDirection);
        }

        for(size_t i = 0; i < bullets.size(); i++){
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection*bulletSpeed);
        }
        
        //-------------------------------- Update --------------------------------

        //-------------------------------- Draw --------------------------------
        window.clear(sf::Color::Black);
        window.draw(enemySprite);
        window.draw(playerSprite);
        for (size_t i = 0; i < bullets.size(); i++){
            window.draw(bullets[i]);
        }
        window.display();
        //-------------------------------- Draw --------------------------------
    }

    return 0;
}