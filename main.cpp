#include "main.hpp"

int main()
{
    //-------------------------------- initialization --------------------------------
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DnD", sf::Style::Default);

    Player player;
    player.Initialize();

    Enemy enemy;
    enemy.Initialize();
    //-------------------------------- initialization --------------------------------

    //-------------------------------- Enemy --------------------------------
    player.Load();
    enemy.Load();

    //-------------------------------- Enemy --------------------------------

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

        enemy.Update();
        player.Update(enemy);

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