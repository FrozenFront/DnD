#include "main.hpp"

int main()
{
    //-------------------------------- initialization --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DnD", sf::Style::Default);
    window.setFramerateLimit(240);

    Player player;
    player.Initialize();

    Enemy enemy;
    enemy.Initialize();
    //-------------------------------- initialization --------------------------------
    player.Load();
    enemy.Load();

    sf::Clock clock;

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

        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();


        enemy.Update(deltaTime);
        player.Update(enemy, deltaTime);

        //-------------------------------- Update --------------------------------

        //-------------------------------- Draw --------------------------------
        window.clear(sf::Color::Black);
        player.Draw(&window);
        enemy.Draw(&window);
        window.display();
        //-------------------------------- Draw --------------------------------

    }

    return 0;
}