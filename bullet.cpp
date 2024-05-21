#include "bullet.hpp"


Bullet::Bullet()
{
    sf::Vector2f temperare = sf::Vector2f(32, 32);
    speed = 0.0f;
};

Bullet::~Bullet()
{
};

void Bullet::Initialize(const sf::Vector2f position, sf::Vector2f direction, float speed)
{
    this->speed = speed;
    bulletShape.setSize(sf::Vector2f(10, 10));
    bulletShape.setFillColor(sf::Color::Red);
    bulletShape.setPosition(position);
    bulletDirection = Function::normalizedVector2f(direction - position);
};

void Bullet::Update(float deltaTime)
{
    bulletShape.setPosition(bulletShape.getPosition() + bulletDirection * speed * deltaTime);
};

void Bullet::Draw(sf::RenderWindow *window)
{
    window->draw(bulletShape);
};