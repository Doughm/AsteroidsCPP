#include "game.h"
#include <ctime>
#include <cmath>
#include "convert.h"

Game::Game(Window* passedWindow, Audio* passedAudio, AssetLoader* passedAsset) :bulletTime(40), PI(3.141592653589793)
{
	window = passedWindow;
	audio = passedAudio;
	assetLoader = passedAsset;

	loadINI.setFile("engine.ini");
	updateFromFile();
	gameSpeed = 0;
	updateSpeed = 0;
	level = 0;
	score = 0;
	lives = 2;
	bulletCounter = 0;
	asteroidsLeft = 4;
	mediumAsteroidsCounter = 0;
	smallAsteroidsCounter = 0;
	explosionCounter = 0;
	ship.position.x = 320;
	ship.position.y = 240;
	bulletsCounter[0] = 0;
	bulletsCounter[1] = 0;
	bulletsCounter[2] = 0;
	bulletsCounter[3] = 0;
	ufo.position.x = -500;
	ufo.position.y = -500;
	isPaused = false;
    ship.isVisible = true;
    ufo.speed = 3;
	isMenu = true;
	
    for (int i = 0; i < 48; ++i)
    {
		smallAsteroids[i].position.x = -500;
		smallAsteroids[i].position.y = -500;
        smallAsteroids[i].speed = 6;
		smallAsteroids[i].vector.x = 0;
		smallAsteroids[i].vector.y = 0;
		smallAsteroids[i].angle = 0;
		smallAsteroids[i].isVisible = false;
        if (i < 24)
        {
			mediumAsteroids[i].position.x = -500;
			mediumAsteroids[i].position.y = -500;
            mediumAsteroids[i].speed = 2;
			mediumAsteroids[i].vector.x = 0;
			mediumAsteroids[i].vector.y = 0;
			mediumAsteroids[i].angle = 0;
			mediumAsteroids[i].isVisible = false;
        }
        if (i < 12)
        {
			largeAsteroids[i].position.x = -500;
			largeAsteroids[i].position.y = -500;
            largeAsteroids[i].speed = .5f;
			largeAsteroids[i].vector.x = 0;
			largeAsteroids[i].vector.y = 0;
			largeAsteroids[i].angle = 0;
			largeAsteroids[i].isVisible = false;
        }
        if (i < 4)
        {
			explosions[i].x = -500;
			explosions[i].y = -500;
			bullets[i].position.x = -500;
			bullets[i].position.y = -500;
			bullets[i].vector.x = 0;
			bullets[i].vector.y = 0;
			bullets[i].angle = 0;
			bullets[i].isVisible = false;
            bullets[i].speed = 10;
        }
    }
    randomiseAsteroids();
}

Game::~Game()
{
	window = NULL;
	audio = NULL;
	assetLoader = NULL;
}

//updates the settings from the INI
void Game::updateFromFile()
{
	gameSpeed = Convert::stringToInt(loadINI.getValue("GameSpeed"));
	updateSpeed = 1000000 / gameSpeed;
    fireKey = loadINI.getValue("FireButton");
    pauseKey = loadINI.getValue("Pause");
    leftKey = loadINI.getValue("LeftButton");
    rightKey = loadINI.getValue("RightButton");
    accelerateKey = loadINI.getValue("Accelerate");
    hyperspaceKey = loadINI.getValue("HyperSpace");
	soundOn = Convert::stringToBool(loadINI.getValue("Sound"));
    highScoreNames[0] = loadINI.getValue("HighScoreName1");
    highScoreNames[1] = loadINI.getValue("HighScoreName2");
    highScoreNames[2] = loadINI.getValue("HighScoreName3");
    highScoreNames[3] = loadINI.getValue("HighScoreName4");
    highScores[0] = Convert::stringToInt(loadINI.getValue("HighScore1"));
    highScores[1] = Convert::stringToInt(loadINI.getValue("HighScore2"));
    highScores[2] = Convert::stringToInt(loadINI.getValue("HighScore3"));
    highScores[3] = Convert::stringToInt(loadINI.getValue("HighScore4"));
}

//updates the INI from the current settings
void Game::updateToFile()
{
	loadINI.updateFile("GameSpeed", Convert::doubleToString(gameSpeed));
    loadINI.updateFile("FireButton", fireKey);
    loadINI.updateFile("Pause", pauseKey);
    loadINI.updateFile("LeftButton", leftKey);
    loadINI.updateFile("RightButton", rightKey);
    loadINI.updateFile("Accelerate", accelerateKey);
    loadINI.updateFile("HyperSpace", hyperspaceKey);
	loadINI.updateFile("Sound", Convert::boolToString(soundOn));
    loadINI.updateFile("HighScoreName1", highScoreNames[0]);
    loadINI.updateFile("HighScoreName2", highScoreNames[1]);
    loadINI.updateFile("HighScoreName3", highScoreNames[2]);
    loadINI.updateFile("HighScoreName4", highScoreNames[3]);
	loadINI.updateFile("HighScore1", Convert::intToString(highScores[0]));
    loadINI.updateFile("HighScore2", Convert::intToString(highScores[1]));
    loadINI.updateFile("HighScore3", Convert::intToString(highScores[2]));
    loadINI.updateFile("HighScore4", Convert::intToString(highScores[3]));
}

//updates the highscore table
void Game::updateHighScoreTable(std::string const& newName, int newScore)
{
    if (newScore >= highScores[0])
    {
        highScores[3] = highScores[2];
        highScores[2] = highScores[1];
        highScores[1] = highScores[0];
        highScores[0] = newScore;
        highScoreNames[3] = highScoreNames[2];
        highScoreNames[2] = highScoreNames[1];
        highScoreNames[1] = highScoreNames[0];
        highScoreNames[0] = newName;
    }
    else if (newScore >= highScores[1])
    {
        highScores[3] = highScores[2];
        highScores[2] = highScores[1];
        highScores[1] = newScore;
        highScoreNames[3] = highScoreNames[2];
        highScoreNames[2] = highScoreNames[1];
        highScoreNames[1] = newName;
    }
    else if (newScore >= highScores[2])
    {
        highScores[2] = highScores[1];
        highScores[2] = newScore;
        highScoreNames[2] = highScoreNames[1];
        highScoreNames[2] = newName;
    }
    else if (newScore >= highScores[3])
    {
        highScores[3] = newScore;
        highScoreNames[3] = newName;
    }
}

//randomly set up the asteroids
void Game::randomiseAsteroids()
{
    for(int i = 0 ; i < level + 4; ++i)
    {
        if (i == 12)
        {
            break;
        }

		largeAsteroids[i].position.x = (float)random.getRandomNumber(0, 640);
		largeAsteroids[i].position.y = (float)random.getRandomNumber(0, 480);
		largeAsteroids[i].angle = random.getRandomNumber(0, 359);
        largeAsteroids[i].isVisible = true;
        while (true)
        {
            if ((largeAsteroids[i].position.x > 160 && largeAsteroids[i].position.x < 400))
            {
				largeAsteroids[i].position.x = (float)random.getRandomNumber(0, 640);
				largeAsteroids[i].position.y = (float)random.getRandomNumber(0, 480);
            }
            else
                break;
        }
        largeAsteroids[i].vector = calculateVector(largeAsteroids[i].position, largeAsteroids[i].speed, largeAsteroids[i].angle);
    }
}

//starts a new game at given level
void Game::reset(int newLevel)
{
    asteroidsLeft = level + 4;
    mediumAsteroidsCounter = 0;
    smallAsteroidsCounter = 0;
    lives = 2;
    level = newLevel;
	if(newLevel = 0)
	{
		score = 0;
	}
	ship.position.x = 302;
	ship.position.y = 228;
    ship.angle = 0;
    ship.vector.x = 0;
    ship.vector.y = 0;
    bulletCounter = 0;
    ufo.isVisible = false;
    for (int i = 0; i < 48; ++i)
    {
        smallAsteroids[i].angle = 0;
        smallAsteroids[i].position.x = -500;
        smallAsteroids[i].position.y = -500;
        smallAsteroids[i].isVisible = false;
        if (i < 24)
        {
            mediumAsteroids[i].angle = 0;
            mediumAsteroids[i].position.x = -500;
            mediumAsteroids[i].position.y = -500;
            mediumAsteroids[i].isVisible = false;
        }
        if (i < 12)
        {
            largeAsteroids[i].angle = 0;
            largeAsteroids[i].position.x = -500;
            largeAsteroids[i].position.y = -500;
            largeAsteroids[i].isVisible = false;
        }
        if (i < 4)
        {
            largeAsteroids[i].isVisible = true;
            bullets[i].position.x = -500;
            bullets[i].position.y = -500;
            bullets[i].vector.x = 0;
            bullets[i].vector.y = 0;
            bullets[i].isVisible = false;
        }
    }
    randomiseAsteroids();
}

//calculates a vector from speed, angle, and position
sf::Vector2f Game::calculateVector(sf::Vector2f const& position, float speed, int angle)
{
    angle *= -1;
	tempVector.x = position.x + (float)std::cos(PI * (angle) / 180.0) * speed;
	tempVector.y = position.y - (float)std::sin(PI * (angle) / 180.0) * speed;
	tempVector.x -= position.x;
	tempVector.y -= position.y;
    return tempVector;
}

//updates the position of all entities
void Game::updatePositions()
{
    //ship
    if (ship.isVisible == true)
    {
        ship.position.x += ship.vector.x;
        ship.position.y += ship.vector.y;
    }
    //bullet
    for (int i = 0; i < 4; ++i)
    {
        if (bullets[i].isVisible == true)
        {
            bulletsCounter[i]++;
            bullets[i].position.x += bullets[i].vector.x;
            bullets[i].position.y += bullets[i].vector.y;
        }
        if (bulletsCounter[i] == bulletTime)
        {
			bullets[i].position.y = -500;
			bullets[i].position.x = -500;
            bulletsCounter[i] = 0;
            bullets[i].isVisible = false;
        }
    }
    //large asteroids
    for (int i = 0; i < 12; ++i)
    {
        if (largeAsteroids[i].isVisible == true)
        {
			largeAsteroids[i].position.x += largeAsteroids[i].vector.x;
			largeAsteroids[i].position.y += largeAsteroids[i].vector.y;
        }
    }
    //medium asteroids
    for (int i = 0; i < 24; ++i)
    {
        if (mediumAsteroids[i].isVisible == true)
        {
			mediumAsteroids[i].position.x += mediumAsteroids[i].vector.x;
			mediumAsteroids[i].position.y += mediumAsteroids[i].vector.y;
        }
    }
    //small asteroids
    for (int i = 0; i < 48; ++i)
    {
        if (smallAsteroids[i].isVisible == true)
        {
			smallAsteroids[i].position.x += smallAsteroids[i].vector.x;
			smallAsteroids[i].position.y += smallAsteroids[i].vector.y;
        }
    }
    //ufo
	if (ufo.isVisible == true && ufo.position.x > -34)
    {
        ufo.position.x -= ufo.speed;
    }
    else
    {
		ufo.position.x = -500;
		ufo.position.y = -500;
    }
}

//moves the ships position or direction
void Game::moveShip(std::string const& key)
{
    if (ship.isVisible == true)
    {
        if (key.find(leftKey) != std::string::npos)
        {
            ship.angle -= 5;
        }
		if (key.find(rightKey) != std::string::npos)
        {
            ship.angle += 5;
        }
		if (key.find(accelerateKey) != std::string::npos)
        {
            if (ship.speed < 5)
            {
                ship.speed += .002f;
            }

            tempVector = calculateVector(ship.position, ship.speed, ship.angle);

            if (ship.vector.x + tempVector.x < 5.1f && ship.vector.x + tempVector.x > -5.1f)
            {
                ship.vector.x += tempVector.x;
            }
            if (ship.vector.y + tempVector.y < 5.1f && ship.vector.y + tempVector.y > -5.1f)
            {
                ship.vector.y += tempVector.y;
            }
        }
        else
        {
            ship.speed = 0;
        }
    }
}

//randomly creates a UFO
void Game::makeUFO()
{
	if (random.getRandomNumber(0, 1000) < 2 && ufo.isVisible == false)
    {
        ufo.isVisible = true;
		ufo.position.x = 640;
		ufo.position.y = (float)random.getRandomNumber(0, 460);
    }
}

//fires a bullet
void Game::fireBullet(std::string const& key)
{
	if (key.find(fireKey) != std::string::npos)
    {
        if (bulletCounter < 3)
        {
            bulletCounter++;
        }
        else
        {
            bulletCounter = 0;
        }
		audio->samplePlay("shotSnd");
        bullets[bulletCounter].isVisible = true;
        bullets[bulletCounter].position.x = ship.position.x + 10;
        bullets[bulletCounter].position.y = ship.position.y + 10;
        bullets[bulletCounter].vector = calculateVector(bullets[bulletCounter].position, bullets[bulletCounter].speed, ship.angle);
        bullets[bulletCounter].angle = ship.angle;
    }
}

//jumps the ship to a random spot
void Game::hyperspaceJump(std::string const& key)
{
	if (key.find(hyperspaceKey) != std::string::npos)
    {
		ship.position.x = (float)random.getRandomNumber(0, 640);
		ship.position.y = (float)random.getRandomNumber(0, 480);
    }
}

//respawns the ship after you die
void Game::shipRespawn()
{
	if (respawnTimer.getElapsedTimeMilliseconds() > 500)
    {
        ship.isVisible = true;
		ship.position.x = 302;
		ship.position.y = 228;
        ship.angle = 0;
		ship.vector.x = 0;
		ship.vector.y = 0;
        lives--;
    }
}

//creates and explosion at given point
void Game::createExplosion(sf::Vector2f const& position)
{
    if (explosionCounter > 3)
    {
        explosionCounter = 0;
    }
    explosions[explosionCounter] = position;
    explosionCounter++;
}

//destroys a bullet
void Game::destroyBullet(int index)
{
	bullets[index].position.x = -500;
    bullets[index].position.y = -500;
    bullets[index].isVisible = false;
    bulletsCounter[index] = 0;
}

//destroys a large asteroid
void Game::destroyLargeAsteroid(int index)
{
	if (largeAsteroids[index].isVisible == true)
	{
		asteroidsLeft += 1;
		score += 20;
		if (mediumAsteroidsCounter >= 24)
		{
			mediumAsteroidsCounter = 0;
		}
		mediumAsteroids[mediumAsteroidsCounter].angle = random.getRandomNumber(0, 359);
		mediumAsteroids[mediumAsteroidsCounter].position.x = largeAsteroids[index].position.x;
		mediumAsteroids[mediumAsteroidsCounter].position.y = largeAsteroids[index].position.y;
		mediumAsteroids[mediumAsteroidsCounter].isVisible = true;
		mediumAsteroids[mediumAsteroidsCounter].vector = calculateVector(mediumAsteroids[mediumAsteroidsCounter].position, mediumAsteroids[mediumAsteroidsCounter].speed, mediumAsteroids[mediumAsteroidsCounter].angle);
		mediumAsteroidsCounter++;
		mediumAsteroids[mediumAsteroidsCounter].angle = random.getRandomNumber(0, 359);
		mediumAsteroids[mediumAsteroidsCounter].position.x = largeAsteroids[index].position.x;
		mediumAsteroids[mediumAsteroidsCounter].position.y = largeAsteroids[index].position.y;
		mediumAsteroids[mediumAsteroidsCounter].isVisible = true;
		mediumAsteroids[mediumAsteroidsCounter].vector = calculateVector(mediumAsteroids[mediumAsteroidsCounter].position, mediumAsteroids[mediumAsteroidsCounter].speed, mediumAsteroids[mediumAsteroidsCounter].angle);
		mediumAsteroidsCounter++;
		largeAsteroids[index].position.x = -500;
		largeAsteroids[index].position.y = -500;
		largeAsteroids[index].isVisible = false;
	}
}

//destroys a medium asteroid
void Game::destroyMediumAsteroid(int index)
{
    if (mediumAsteroids[index].isVisible == true)
    {
        asteroidsLeft += 1;
        score += 30;
        if (smallAsteroidsCounter >= 48)
        {
            smallAsteroidsCounter = 0;
        }
        smallAsteroids[smallAsteroidsCounter].angle = random.getRandomNumber(0, 359);
		smallAsteroids[smallAsteroidsCounter].position.x = mediumAsteroids[index].position.x;
		smallAsteroids[smallAsteroidsCounter].position.y = mediumAsteroids[index].position.y;
        smallAsteroids[smallAsteroidsCounter].isVisible = true;
        smallAsteroids[smallAsteroidsCounter].vector = calculateVector(smallAsteroids[smallAsteroidsCounter].position, smallAsteroids[smallAsteroidsCounter].speed, smallAsteroids[smallAsteroidsCounter].angle);
        smallAsteroidsCounter++;
        smallAsteroids[smallAsteroidsCounter].angle = random.getRandomNumber(0, 359);
		smallAsteroids[smallAsteroidsCounter].position.x = mediumAsteroids[index].position.x;
		smallAsteroids[smallAsteroidsCounter].position.y = mediumAsteroids[index].position.y;
        smallAsteroids[smallAsteroidsCounter].isVisible = true;
        smallAsteroids[smallAsteroidsCounter].vector = calculateVector(smallAsteroids[smallAsteroidsCounter].position, smallAsteroids[smallAsteroidsCounter].speed, smallAsteroids[smallAsteroidsCounter].angle);
        smallAsteroidsCounter++;
		mediumAsteroids[index].position.x = -500;
		mediumAsteroids[index].position.y = -500;
        mediumAsteroids[index].isVisible = false;
    }
}

//destroys a small asteroid
void Game::destroySmallAsteroid(int index)
{
    if (smallAsteroids[index].isVisible == true)
    {
        asteroidsLeft -= 1;
        score += 40;
        smallAsteroids[index].position.x = -500;
        smallAsteroids[index].position.y = -500;
        smallAsteroids[index].isVisible = false;
    }
}

//destroys the ship
void Game::destroyShip()
{
    ship.position.x = -500;
    ship.position.y = -500;
    ship.isVisible = false;
	respawnTimer.restartClock();
}

//destroys the UFO
void Game::destroyUFO()
{
    ufo.position.x = -500;
    ufo.position.y = -500;
    score += 100;
}

//destroys an exposition
void Game::destroyExplosion(int index)
{
    explosions[index].x = -500;
    explosions[index].y = -500;
}

//wraps an entity around the screen if it is out of bounds
void Game::wrapEntitys()
{
    //ship
    if(ship.position.x >= 640)
    {
        ship.position.x = -30;
    }
    else if (ship.position.x <= -30)
    {
        ship.position.x = 640;
    }
    else if (ship.position.y >= 480)
    {
        ship.position.y = -30;
    }
    else if (ship.position.y <= -30)
    {
        ship.position.y = 480;
    }
    //bullets
    for (int i = 0; i < 4; ++i)
    {
        if (bullets[i].position.x >= 640)
        {
            bullets[i].position.x = -15;
        }
        else if (bullets[i].position.x <= -15)
        {
            bullets[i].position.x = 640;
        }
        else if (bullets[i].position.y >= 480)
        {
            bullets[i].position.y = -15;
        }
        else if (bullets[i].position.y <= -15)
        {
            bullets[i].position.y = 480;
        }
    }
    //large asteroids
    for (int i = 0; i < 12; ++i)
    {
        if (largeAsteroids[i].position.x >= 640)
        {
            largeAsteroids[i].position.x = -125;
        }
        else if (largeAsteroids[i].position.x <= -125)
        {
            largeAsteroids[i].position.x = 640;
        }
        else if (largeAsteroids[i].position.y >= 480)
        {
            largeAsteroids[i].position.y = -125;
        }
        else if (largeAsteroids[i].position.y <= -125)
        {
            largeAsteroids[i].position.y = 480;
        }
    }
    //medium asteroids
    for (int i = 0; i < 24; ++i)
    {
        if (mediumAsteroids[i].position.x >= 640)
        {
            mediumAsteroids[i].position.x = -70;
        }
        else if (mediumAsteroids[i].position.x <= -70)
        {
            mediumAsteroids[i].position.x = 640;
        }
        else if (mediumAsteroids[i].position.y >= 480)
        {
            mediumAsteroids[i].position.y = -70;
        }
        else if (mediumAsteroids[i].position.y <= -70)
        {
            mediumAsteroids[i].position.y = 480;
        }
    }
    //small asteroids
    for (int i = 0; i < 24; ++i)
    {
        if (smallAsteroids[i].position.x >= 640)
        {
            smallAsteroids[i].position.x = -34;
        }
        else if (smallAsteroids[i].position.x <= -34)
        {
            smallAsteroids[i].position.x = 640;
        }
        else if (smallAsteroids[i].position.y >= 480)
        {
            smallAsteroids[i].position.y = -34;
        }
        else if (smallAsteroids[i].position.y <= -34)
        {
            smallAsteroids[i].position.y = 480;
        }
    }
}

//tests if the level has ended
bool Game::levelEnded()
{
    if (asteroidsLeft == 0)
    {
        return true;
    }
    return false;
}

//changes to the next level
void Game::nextLevel()
{
    level++;
    reset(level);
}

//finds if a bullet is within the level bounds
bool Game::bulletInBounds(int index)
{
	if(bullets[index].position.x >= 0 && bullets[index].position.y >= 0 &&
	   bullets[index].position.x < 640 && bullets[index].position.x < 480)
	{
		return true;
	}
	return false;
}

//finds if a large asteroid is within the level bounds
bool Game::largeAsteroidInBounds(int index)
{
	if(bullets[index].position.x >= 0 && bullets[index].position.y >= 0 &&
	   bullets[index].position.x < 640 && bullets[index].position.x < 480)
	{
		return true;
	}
	return false;
}
//finds if a medium asteroid is within the level bounds
bool Game::mediumAsteroidInBounds(int index)
{
	if(mediumAsteroids[index].position.x >= 0 && mediumAsteroids[index].position.y >= 0 &&
	   mediumAsteroids[index].position.x < 640 && mediumAsteroids[index].position.x < 480)
	{
		return true;
	}
	return false;
}
//finds if a small asteroid is within the level bounds
bool Game::smallAsteroidInBounds(int index)
{
	if(smallAsteroids[index].position.x >= 0 && bullets[index].position.y >= 0 &&
	   smallAsteroids[index].position.x < 640 && bullets[index].position.x < 480)
	{
		return true;
	}
	return false;
}
//finds if an explostion is within the level bounds
bool Game::explosionInbounds(int index)
{
	if(explosions[index].x >= 0 && explosions[index].y >= 0 &&
	   explosions[index].x < 640 && explosions[index].x < 480)
	{
		return true;
	}
	return false;
}

//returns the position of the ship
sf::Vector2f Game::getShipPosition()
{
    return ship.position;
}

//returns the angle of the ship
float Game::getShipAngle()
{
    return (float)ship.angle;
}

//returns if the ship is active
bool Game::getShipIsVisible()
{
    return ship.isVisible;
}

//returns the position of an explosion
sf::Vector2f Game::getExplosionPosition(int index)
{
    return explosions[index];
}

//returns the position of a given large asteroid
sf::Vector2f Game::getLargeAsteroidsPosition(int index)
{
    return largeAsteroids[index].position;
}

//returns if a large asteroid is active
bool Game::getLargeAsteroidsIsVisible(int index)
{
	return largeAsteroids[index].isVisible;
}

//returns the position of a given medium asteroid
sf::Vector2f Game::getMediumAsteroidsPosition(int index)
{
    return mediumAsteroids[index].position;
}

//returns if a medium asteroid is active
bool Game::getMediumAsteroidsIsVisible(int index)
{
	return mediumAsteroids[index].isVisible;
}

//returns the position of a given small asteroid
sf::Vector2f Game::getSmallAsteroidsPosition(int index)
{
    return smallAsteroids[index].position;
}

//returns if a small asteroid is active
bool Game::getSmallAsteroidsIsVisible(int index)
{
	return smallAsteroids[index].isVisible;
}

//returns the position of the UFO
sf::Vector2f Game::getUfoPosition()
{
    return ufo.position;
}

//returns the angle of a bullet
float Game::getBulletAngle(int index)
{
    return (float)bullets[index].angle;
}

//gets the position of a bullet entity
sf::Vector2f Game::getBulletPosition(int index)
{
    return bullets[index].position;
}

//returns if a bullet is active
bool Game::getBulletIsVisible(int index)
{
    return bullets[index].isVisible;
}

//returns if the game is paused
bool Game::getIsPaused()
{
    return isPaused;
}

//returns the current level the player is on
int Game::getLevel()
{
    return level + 1;
}

//returns the speed of the game
double Game::getUpdateSpeed()
{
	return updateSpeed;
}

void Game::inputUpdate()
{
	mouseClick.clear();
	keyboard.clear();
	keyboardDown.clear();
	keyboardSingle.clear();
	mouseClick.append(window->inputMouseClick());
	keyboard.append(window->inputKeyboard());
	keyboardDown.append(window->inputKeyboardDown());
	keyboardSingle.append(window->inputKeyboardSingle());
}

void Game::menuUpdate()
{
	if (isMenu == true)
	{
		if (mouseClick == "Leftbutton")
		{
			if (window->isWithin("PlayButtonSpr", window->mousePositionView()))
			{
				isMenu = false;
				updateFromFile();
				reset(0);
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("Game");
			}
			else if (window->isWithin("HighScoreButtonSpr", window->mousePositionView()))
			{
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("HighScore");
				window->setText("ScoreTxt1", highScoreNames[0]);
				window->setText("ScoreTxt2", highScoreNames[1]);
				window->setText("ScoreTxt3", highScoreNames[2]);
				window->setText("ScoreTxt4", highScoreNames[3]);
				window->setText("NameTxt1", Convert::intToString(highScores[0]));
				window->setText("NameTxt2", Convert::intToString(highScores[1]));
				window->setText("NameTxt3", Convert::intToString(highScores[2]));
				window->setText("NameTxt4", Convert::intToString(highScores[3]));
			}
			else if (window->isWithin("OptionsButtonSpr", window->mousePositionView()))
			{
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("Options");
				updateFromFile();
				if (audio->getSoundOn() == true)
				{
					window->setText("SoundTxt", "Sound On");
				}
				else
				{
					window->setText("SoundTxt", "Sound Off");
				}
			}
			else if (window->isWithin("MenuButtonSpr", window->mousePositionView()) && keyPress == false)
			{
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("MainMenu");
			}
			else if (window->isWithin("ApplyButtonSpr", window->mousePositionView()) && keyPress == false)
			{
				updateToFile();
			}
			else if (window->isWithin("SoundButtonSpr", window->mousePositionView()))
			{
				if (audio->getSoundOn() == true)
				{
					audio->setSoundOn(false);
					window->setText("SoundTxt", "Sound Off");
				}
				else
				{
					audio->setSoundOn(true);
					window->setText("SoundTxt", "Sound On");
				}
			}
			else if (window->isWithin("KeyboardButtonSpr", window->mousePositionView()))
			{
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("KeyboardSetup");
				if (fireKey.find("Letr") != std::string::npos)
				{
					tempStr = fireKey[4];
					window->setText("FireKeyTxt", tempStr);
				}
				else
				{
					window->setText("FireKeyTxt", fireKey);
				}
				if (pauseKey.find("Letr") != std::string::npos)
				{
					tempStr = pauseKey[4];
					window->setText("PauseKeyTxt", tempStr);
				}
				else
				{
					window->setText("PauseKeyTxt", pauseKey);
				}
				if (hyperspaceKey.find("Letr") != std::string::npos)
				{
					tempStr = hyperspaceKey[4];
					window->setText("HyperspaceKeyTxt", tempStr);
				}
				else
				{
					window->setText("HyperspaceKeyTxt", hyperspaceKey);
				}
				if (rightKey.find("Letr") != std::string::npos)
				{
					tempStr = rightKey[4];
					window->setText("RightKeyTxt", tempStr);
				}
				else
				{
					window->setText("RightKeyTxt", rightKey);
				}
				if (leftKey.find("Letr") != std::string::npos)
				{
					tempStr = leftKey[4];
					window->setText("LeftKeyTxt", tempStr);
				}
				else
				{
					window->setText("LeftKeyTxt", leftKey);
				}
				if (accelerateKey.find("Letr") != std::string::npos)
				{
					tempStr = accelerateKey[4];
					window->setText("AccelerateKeyTxt", tempStr);
				}
				else
				{
					window->setText("AccelerateKeyTxt", accelerateKey);
				}
			}
			else if (window->isWithin("FireButtonSpr", window->mousePositionView()))
			{
				setKey = "Fire";
				keyPress = true;
			}
			else if (window->isWithin("PauseButtonSpr", window->mousePositionView()))
			{
				setKey = "Pause";
				keyPress = true;
			}
			else if (window->isWithin("HyperspaceButtonSpr", window->mousePositionView()))
			{
				setKey = "HyperSpace";
				keyPress = true;
			}
			else if (window->isWithin("RightButtonSpr", window->mousePositionView()))
			{
				setKey = "Right";
				keyPress = true;
			}
			else if (window->isWithin("LeftButtonSpr", window->mousePositionView()))
			{
				setKey = "Left";
				keyPress = true;
			}
			else if (window->isWithin("AccelerateButtonSpr", window->mousePositionView()))
			{
				setKey = "Accelerate";
				keyPress = true;
			}
			else if (window->isWithin("EnterButtonSpr", window->mousePositionView()))
			{
				typing = false;
				updateHighScoreTable(textEdit.getString(), score);
				updateToFile();
				assetLoader->loadAssets("Clear");
				assetLoader->loadAssets("HighScore");
				window->setText("ScoreTxt1", highScoreNames[0] + "\t\t" + Convert::intToString(highScores[0]));
				window->setText("ScoreTxt2", highScoreNames[1] + "\t\t" + Convert::intToString(highScores[1]));
				window->setText("ScoreTxt3", highScoreNames[2] + "\t\t" + Convert::intToString(highScores[2]));
				window->setText("ScoreTxt4", highScoreNames[3] + "\t\t" + Convert::intToString(highScores[3]));
			}
		}
	}
}

void Game::keyboardBind()
{
	if (keyPress == true)
	{
		window->moveEntity("PressKeyTxt", sf::Vector2f(195, 420));
		if (keyboardSingle != "" && keyboardSingle != "unknownkey")
		{
			if (setKey == "Fire")
			{
				fireKey = keyboardSingle;
				keyPress = false;
				if (fireKey.find("Letr") != std::string::npos)
				{
					tempStr = fireKey[4];
					window->setText("FireKeyTxt", tempStr);
				}
				else
				{
					window->setText("FireKeyTxt", fireKey);
				}
			}
			else if (setKey == "Pause")
			{
				pauseKey = keyboardSingle;
				keyPress = false;
				if (pauseKey.find("Letr") != std::string::npos)
				{
					tempStr = pauseKey[4];
					window->setText("PauseKeyTxt", tempStr);
				}
				else
				{
					window->setText("PauseKeyTxt", pauseKey);
				}
			}
			else if (setKey == "HyperSpace")
			{
				hyperspaceKey = keyboardSingle;
				keyPress = false;
				if (hyperspaceKey.find("Letr") != std::string::npos)
				{
					tempStr = hyperspaceKey[4];
					window->setText("HyperspaceKeyTxt", tempStr);
				}
				else
				{
					window->setText("HyperspaceKeyTxt", hyperspaceKey);
				}
			}
			else if (setKey == "Right")
			{
				rightKey = keyboardSingle;
				keyPress = false;
				if (rightKey.find("Letr") != std::string::npos)
				{
					tempStr = rightKey[4];
					window->setText("RightKeyTxt", tempStr);
				}
				else
				{
					window->setText("RightKeyTxt", rightKey);
				}
			}
			else if (setKey == "Left")
			{
				leftKey = keyboardSingle;
				keyPress = false;
				if (leftKey.find("Letr") != std::string::npos)
				{
					tempStr = leftKey[4];
					window->setText("LeftKeyTxt", tempStr);
				}
				else
				{
					window->setText("LeftKeyTxt", leftKey);
				}
			}
			if (setKey == "Accelerate")
			{
				accelerateKey = keyboardSingle;
				keyPress = false;
				if (accelerateKey.find("Letr") != std::string::npos)
				{
					tempStr = accelerateKey[4];
					window->setText("AccelerateKeyTxt", tempStr);
				}
				else
				{
					window->setText("AccelerateKeyTxt", accelerateKey);
				}
			}
		}
	}
	else
	{
		window->moveEntity("PressKeyTxt", sf::Vector2f(-500, -500));
	}
}

void Game::inputString()
{
	if (typing == true)
	{
		textEdit.takeInput(window->inputKeyboard());
		window->setText("NameTxt", textEdit.getString());
	}
}

void Game::pause()
{
	if (isMenu == false)
	{
		if (keyboardDown.find(pauseKey) != std::string::npos)
		{
			if (isPaused == true)
			{
				window->moveEntity("PausedTxt", sf::Vector2f(-500, -500));
				isPaused = false;
				for (int i = 1; i < 4 + 1; i++)
				{
					window->resumeAnimation("ExplosionAni" + Convert::intToString(i));
				}
			}
			else
			{
				isPaused = true;
				tempVector.x = 270;
				tempVector.y = 210;
				window->moveEntity("PausedTxt", tempVector);
				for (int i = 1; i < 4 + 1; i++)
				{
					window->pauseAnimation("ExplosionAni" + Convert::intToString(i));
				}
			}
		}
	}
}

void Game::checkBulletCollisions()
{
	for (int i = 1; i < 5; ++i)
	{
		if (getBulletIsVisible(i - 1))
		{
			tempStr = window->batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "LargeAsteroidSpr");
			for (int ii = 1; ii < 13; ++ii)
			{
				if (tempStr.find("LargeAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
				{
					tempVector.x = getLargeAsteroidsPosition(ii - 1).x + 43;
					tempVector.y = getLargeAsteroidsPosition(ii - 1).y + 57;
					createExplosion(tempVector);
					window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
					destroyBullet(i - 1);
					destroyLargeAsteroid(ii - 1);
					audio->samplePlay("boomSnd");
					window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
				}
			}
			tempStr = window->batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "MediumAsteroidSpr");
			for (int ii = 1; ii < 25; ++ii)
			{
				if (tempStr.find("MediumAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
				{
					tempVector.x = getMediumAsteroidsPosition(ii - 1).x + 15;
					tempVector.y = getMediumAsteroidsPosition(ii - 1).y + 23;
					createExplosion(tempVector);
					window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
					destroyBullet(i - 1);
					destroyMediumAsteroid(ii - 1);
					audio->samplePlay("boomSnd");
					window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
				}
			}
			tempStr = window->batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "SmallAsteroidSpr");
			for (int ii = 1; ii < 25; ++ii)
			{
				if (tempStr.find("SmallAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
				{

					createExplosion(getSmallAsteroidsPosition(ii - 1));
					window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
					destroyBullet(i - 1);
					destroySmallAsteroid(ii - 1);
					audio->samplePlay("boomSnd");
					window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
				}
			}
			if (window->isOverlapping("BulletSpr" + Convert::intToString(i), "UFOSpr"))
			{
				createExplosion(getUfoPosition());
				window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
				destroyBullet(i - 1);
				destroyUFO();
				audio->samplePlay("boomSnd");
				window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
			}
		}
	}
}

void Game::checkShipCollisions()
{
	tempStr = window->batchIsOverlapping(("ShipSpr"), "LargeAsteroidSpr");
	if ((tempStr.find("LargeAsteroidSpr") != std::string::npos) && getShipIsVisible() == true)
	{
		tempVector.x = getShipPosition().x;
		tempVector.y = getShipPosition().y - 8;
		createExplosion(tempVector);
		window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
		destroyShip();
		destroyBullet(0);
		destroyBullet(1);
		destroyBullet(2);
		destroyBullet(3);
		audio->samplePlay("boomSnd");
		window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
	}
	tempStr = window->batchIsOverlapping(("ShipSpr"), "MediumAsteroidSpr");
	if ((tempStr.find("MediumAsteroidSpr") != std::string::npos) && getShipIsVisible() == true)
	{
		tempVector.x = getShipPosition().x;
		tempVector.y = getShipPosition().y - 8;
		createExplosion(tempVector);
		window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
		destroyShip();
		destroyBullet(0);
		destroyBullet(1);
		destroyBullet(2);
		destroyBullet(3);
		audio->samplePlay("boomSnd");
		window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
	}
	tempStr = window->batchIsOverlapping(("ShipSpr"), "SmallAsteroidSpr");
	if ((tempStr.find("SmallAsteroidSpr") != std::string::npos) && getShipIsVisible() == true)
	{
		tempVector.x = getShipPosition().x;
		tempVector.y = getShipPosition().y - 8;
		createExplosion(tempVector);
		window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
		destroyShip();
		destroyBullet(0);
		destroyBullet(1);
		destroyBullet(2);
		destroyBullet(3);
		audio->samplePlay("boomSnd");
		window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
	}
	if (window->isOverlapping("ShipSpr", "UFOSpr") && getShipIsVisible() == true)
	{
		tempVector.x = getShipPosition().x;
		tempVector.y = getShipPosition().y - 8;
		createExplosion(tempVector);
		window->goToFrame("ExplosionAni" + Convert::intToString(explosionCounter), 0);
		destroyShip();
		destroyBullet(0);
		destroyBullet(1);
		destroyBullet(2);
		destroyBullet(3);
		audio->samplePlay("boomSnd");
		window->resumeAnimation("ExplosionAni" + Convert::intToString(explosionCounter));
	}
}

void Game::checkEndOfGame()
{
	if (ship.isVisible == false && lives > 0)
	{
		shipRespawn();
	}
	else if (ship.isVisible == false && lives == 0)
	{
		ticker.increment();
	}
	if (ticker.atAmount(70) && ship.isVisible == false)
	{
		ticker.resetCounter();
		isMenu = true;
		assetLoader->loadAssets("Clear");
		if (score > highScores[0] ||
			score > highScores[1] ||
			score > highScores[2] ||
			score > highScores[3])
		{
			assetLoader->loadAssets("EnterHighScore");
			tempStr = "";
			typing = true;
		}
		else
		{
			assetLoader->loadAssets("MainMenu");
		}
	}
}

void Game::entityUpdate()
{
	makeUFO();
	fireBullet(keyboardDown);
	moveShip(keyboard);
	hyperspaceJump(keyboardDown);
	wrapEntitys();
	updatePositions();
	window->setText("ScoreBoardTxt", "Score: " + Convert::intToString(score));
	window->setText("LevelTxt", "Level: " + Convert::intToString(level + 1));
	window->setText("LivesTxt", "Lives: " + Convert::intToString(lives));
}

void Game::changeLevel()
{
	if (levelEnded())
	{
		ticker.increment();
	}
	if (levelEnded() && ticker.atAmount(30))
	{
		ticker.resetCounter();
		nextLevel();
	}
}

void Game::graphicUpdate()
{
	window->rotateEntityCenter("ShipSpr", ship.angle);
	window->moveEntity("ShipSpr", ship.position);
	for (int i = 1; i < 49; i++)
	{
		if (i < 5)
		{
			window->moveEntity(("BulletSpr" + Convert::intToString(i)), bullets[i - 1].position);
			window->moveEntity(("ExplosionAni" + Convert::intToString(i)), explosions[i - 1]);
			window->rotateEntityCenter("BulletSpr" + Convert::intToString(i), bullets[i - 1].angle);
		}
		if (i < 13)
		{
			window->moveEntity(("LargeAsteroidSpr" + Convert::intToString(i)), largeAsteroids[i - 1].position);
		}
		if (i < 25)
		{
			window->moveEntity(("MediumAsteroidSpr" + Convert::intToString(i)), mediumAsteroids[i - 1].position);
		}
		window->moveEntity(("SmallAsteroidSpr" + Convert::intToString(i)), smallAsteroids[i - 1].position);
	}
	window->moveEntity("UFOSpr", ufo.position);
}

void Game::explosionLastFrame()
{
	for (int i = 1; i < 5; i++)
	{
		if (window->getAnimationFrame("ExplosionAni" + Convert::intToString(i)) == 3)
		{
			destroyExplosion(i - 1);
		}
	}
}

bool Game::escape()
{
	if (keyboardDown.find("Escape") != std::string::npos)
	{
		if (isMenu == false)
		{
			assetLoader->loadAssets("Clear");
			assetLoader->loadAssets("MainMenu");
			isMenu = true;
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool Game::isPlaying()
{
	if (isPaused == false && isMenu == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}