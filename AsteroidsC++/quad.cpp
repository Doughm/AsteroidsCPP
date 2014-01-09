#include "quad.h"

Quad::Quad()
{
	vertex[0].color = sf::Color::Transparent;
	vertex[1].color = sf::Color::Transparent;
	vertex[2].color = sf::Color::Transparent;
	vertex[3].color = sf::Color::Transparent;
	vertex[0].position.x = 0;
	vertex[1].position.x = 0;
	vertex[2].position.x = 0;
	vertex[3].position.x = 0;
	vertex[0].position.y = 0;
	vertex[1].position.y = 0;
	vertex[2].position.y = 0;
	vertex[3].position.y = 0;
	vertex[0].texCoords.x = 0;
	vertex[1].texCoords.x = 0;
	vertex[2].texCoords.x = 0;
	vertex[3].texCoords.x = 0;
	vertex[0].texCoords.y = 0;
	vertex[1].texCoords.y = 0;
	vertex[2].texCoords.y = 0;
	vertex[3].texCoords.y = 0;
}

Quad::Quad(sf::Vertex const& vert1, sf::Vertex const& vert2, sf::Vertex const& vert3, sf::Vertex const& vert4)
{
	vertex[0] = vert1;
    vertex[1] = vert2;
    vertex[2] = vert3;
    vertex[3] = vert4;
    rotation = 0;
	scale.x = 0;
	scale.y = 0;
	color[0] = vert1.color;
    color[1] = vert2.color;
    color[2] = vert3.color;
    color[4] = vert4.color;
}