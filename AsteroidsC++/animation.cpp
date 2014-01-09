#include "animation.h"

Animation::Animation()
{
	speed = 0;
	currentFrame = 0;
	loops = true;
	paused = false;
	animationTimer.restartClock();
}

Animation::Animation(std::vector<std::string> const& passedFrames)
{
	frames = passedFrames;
	speed = 0;
	currentFrame = 0;
	loops = true;
	paused = false;
	animationTimer.restartClock();
}

Animation::Animation(std::vector<std::string> const& passedFrames, Quad const& animationPositions, int animationSpeed)
{
	positions = animationPositions;
	frames = passedFrames;
	speed = animationSpeed;
	currentFrame = 0;
	loops = true;
	paused = false;
	animationTimer.restartClock();
}