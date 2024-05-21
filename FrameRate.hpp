#ifndef FR_ct
#define FR_ct
#include <iostream>
#include <SFML/Graphics.hpp>

class FrameRate{
    private:
        sf::Text frameRateText;
        sf::Font font;

        float timer;

    public:
        void Initialize();
        void Load();
        void Update(float deltaTime);
        void Draw(sf::RenderWindow *window);
};

#endif