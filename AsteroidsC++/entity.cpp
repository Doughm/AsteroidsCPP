#include "entity.h"

Entity::Entity()
{
	position.x = 0;
	position.y = 0;
	vector.x = 0;
	vector.y = 0;
	angle = 0;
	speed = 0;
	isVisible = false;
}


Entity::Entity(sf::Vector2f startingPos)
{
	position = startingPos;
	vector.x = 0;
	vector.y = 0;
    angle = 0;
    speed = 0;
    isVisible = false;
}