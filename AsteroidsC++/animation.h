//holds all information on an animation, including all frames, speed,
//position, if it loops, and if its paused;

#ifndef ANIMATION
#define ANIMATION

#include <string>
#include "quad.h"
#include "gametimer.h"

class Animation
{
public:
	Animation();
	Animation(std::vector<std::string> const&);
	Animation(std::vector<std::string> const&, Quad const&, int);
	Quad positions;
	float speed;
	GameTimer animationTimer;
	int currentFrame;
	bool loops;
	bool paused;
	std::vector<std::string> frames;
};

#endif