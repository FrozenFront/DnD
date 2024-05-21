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
    Map map;


    //-------------------------------- initialization --------------------------------
    player.Initialize(100, 100, 0);
    enemy.Initialize(100, 100, 0);
    frameRate.Initialize();
    map.Initialize();
    //-------------------------------- initialization --------------------------------

    //-------------------------------- Load --------------------------------
    player.Load();
    enemy.Load();
    frameRate.Load();
    map.Load();
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

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));


        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        enemy.Update(deltaTime);
        player.Update(enemy, deltaTime, mousePosition);
        //-------------------------------- Update --------------------------------

        //-------------------------------- Draw --------------------------------
        window.clear(sf::Color::Black);
        map.Draw(&window);
        player.Draw(&window);
        enemy.Draw(&window);
        frameRate.Draw(&window);
        window.display();
        //-------------------------------- Draw --------------------------------

    }

    return 0;
}