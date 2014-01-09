#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	Entity(sf::Vector2f);

	sf::Vector2f position;
    sf::Vector2f vector;
    int angle;
    float speed;
    bool isVisible;
};

#endif