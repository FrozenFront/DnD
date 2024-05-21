#include "FrameRate.hpp"

void FrameRate::Initialize(){
    timer = 0;
};

void FrameRate::Load(){
    if (font.loadFromFile("assets/font/Arial/arialmt.ttf")){
        std::cout << "Font loaded" << std::endl;
        frameRateText.setFont(font);
        frameRateText.setCharacterSize(14);
        frameRateText.setFillColor(sf::Color::White);
    } else {
        std::cout << "Font not loaded" << std::endl;
    }
};

void FrameRate::Update(float deltaTime){
    timer += deltaTime;
    if(timer >= 100.0f){
    frameRateText.setString("FPS: " + std::to_string(1000.0f/deltaTime) + 
                            "; FrameRate: " + std::to_string(deltaTime));
    timer = 0;
    }
};

void FrameRate::Draw(sf::RenderWindow *window){
    window->draw(frameRateText);
};
