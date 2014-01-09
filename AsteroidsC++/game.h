#ifndef GAME
#define GAME

#include "loadini.h"
#include <SFML/Graphics.hpp>
#include <random>
#include "entity.h"
#include "gametimer.h"
#include "random.h"

class Game
{
public:
	Game();
	void updateFromFile();
	void updateToFile();
	void updateHighScoreTable(std::string const&, int);
	void randomiseAsteroids();
	void reset(int);
	void updatePositions();
	void moveShip(std::string const&);
	void makeUFO();
	void fireBullet(std::string const&);
	void hyperspaceJump(std::string const&);
	void shipRespawn();
	void createExplosion(sf::Vector2f const&);
	void moveExplostion(int, sf::Vector2f const&);
	void destroyBullet(int);
	void destroyLargeAsteroid(int);
	void destroyMediumAsteroid(int);
	void destroySmallAsteroid(int);
	void destroyShip();
	void destroyUFO();
	void destroyExposition(int);
	void wrapEntitys();
	bool levelEnded();
	void nextLevel();
	bool bulletInBounds(int);
	bool largeAsteroidInBounds(int);
	bool mediumAsteroidInBounds(int);
	bool smallAsteroidInBounds(int);
	bool explosionInbounds(int);
	
	//sets and gets
	sf::Vector2f getShipPosition();
	float getShipAngle();
	bool getShipIsVisible();
	sf::Vector2f getExplosionPosition(int);
	sf::Vector2f getLargeAsteroidsPosition(int);
	bool getLargeAsteroidsIsVisible(int);
	sf::Vector2f getMediumAsteroidsPosition(int);
	bool getMediumAsteroidsIsVisible(int);
	sf::Vector2f getSmallAsteroidsPosition(int);
	bool getSmallAsteroidsIsVisible(int);
	sf::Vector2f getUfoPosition();
	float getBulletAngle(int);
	sf::Vector2f getBulletPosition(int);
	bool getBulletIsVisible(int);
	bool getIsPaused();
	int getLevel();
	std::string getPauseKey();
	std::string getFireKey();
	std::string getLeftKey();
	std::string getRightKey();
	std::string getAccelerateKey();
	std::string getHyperspaceKey();
	bool getSoundOn();
	std::string getHighScoreName(int);
	int getHighScore(int);
	int getScore();
	int getLives();
	int getExplosionNumber();
	double getUpdateSpeed();
	void setShipIsVisible(bool);
	void setIsPaused(bool);
	void setHighScoreName(int, std::string const&);
	void setHighScore(int, int);
	void setSoundOn(bool);
	void setGameSpeed(int);
	void setFireKey(std::string const&);
	void setPauseKey(std::string const&);
	void setLeftKey(std::string const&);
	void setRightKey(std::string const&);
	void setAccelerateKey(std::string const&);
	void setHyperspaceKey(std::string const&);

private:
	sf::Vector2f calculateVector(sf::Vector2f const&, float, int);

	LoadINI loadINI;
	Random random;
	GameTimer respawnTimer;
	GameTimer gameTimer;
	const double PI;
	const int bulletTime;
	int level;
    int score;
    int lives;
	int bulletCounter;
    int asteroidsLeft;
	int mediumAsteroidsCounter;
	int smallAsteroidsCounter;
	int explosionCounter;
	int highScores[4];
	int bulletsCounter[4];
	double gameSpeed;
	double updateSpeed;
	std::string fireKey;
    std::string pauseKey;
    std::string leftKey;
    std::string rightKey;
    std::string hyperspaceKey;
    std::string accelerateKey;
	std::string highScoreNames[4];
	bool isPaused;
    bool soundOn;
	Entity ship;
	sf::Vector2f explosions[4];
	sf::Vector2f tempVector;
	Entity largeAsteroids[12];
    Entity mediumAsteroids[24];
    Entity smallAsteroids[48];
    Entity bullets[4];
    Entity ufo;
};

#endif