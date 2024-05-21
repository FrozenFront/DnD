#include "main.hpp"

int main()
{
    //-------------------------------- initialization --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DnD", sf::Style::Default);
    window.setFramerateLimit(240);

    Player player;
    Enemy enemy;
    FrameRate frameRate;
    sf::Clock clock;

    //-------------------------------- initialization --------------------------------

    player.Initialize();
    enemy.Initialize();
    frameRate.Initialize();

    //-------------------------------- initialization --------------------------------

    //-------------------------------- Load --------------------------------
    player.Load();
    enemy.Load();
    frameRate.Load();
    //-------------------------------- Load --------------------------------


    //main loop
    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();

        //-------------------------------- Update --------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        enemy.Update(deltaTime);
        player.Update(enemy, deltaTime);
        frameRate.Update(deltaTime);
        //-------------------------------- Update --------------------------------

        //-------------------------------- Draw --------------------------------
        window.clear(sf::Color::Black);
        player.Draw(&window);
        enemy.Draw(&window);
        frameRate.Draw(&window);
        window.display();
        //-------------------------------- Draw --------------------------------

    }

    return 0;
}