//holds four vertexes, the first point in the vertex array
//where the quad is stored, the scale of the entity, and
//the rotation.

#ifndef QUAD
#define QUAD

#include <SFML/Graphics.hpp>

class Quad
{
public:
	Quad();
	Quad(sf::Vertex const&, sf::Vertex const&, sf::Vertex const&, sf::Vertex const&);
	sf::Vertex vertex[4];
	sf::Color color[4];
	int firstPosition;
	sf::Vector2f scale;
	double rotation;
};

#endif