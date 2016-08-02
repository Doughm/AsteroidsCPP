#ifndef GAME
#define GAME

#include "loadini.h"
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "gametimer.h"
#include "random.h"
#include "window.h"
#include "audio.h"
#include "assetloader.h"
#include "ticker.h"
#include "textedit.h"

class Game
{
public:
	Game(Window*, Audio*, AssetLoader*);
	~Game();
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
	void destroyExplosion(int);
	void wrapEntitys();
	bool levelEnded();
	void nextLevel();
	bool bulletInBounds(int);
	bool largeAsteroidInBounds(int);
	bool mediumAsteroidInBounds(int);
	bool smallAsteroidInBounds(int);
	bool explosionInbounds(int);
	
	//sets and gets

	double getUpdateSpeed();

	void inputUpdate();
	void menuUpdate();
	void keyboardBind();
	void inputString();
	void pause();
	void checkBulletCollisions();
	void checkShipCollisions();
	void checkEndOfGame();
	void entityUpdate();
	void changeLevel();
	void graphicUpdate();
	void explosionLastFrame();
	bool escape();
	bool isPlaying();

private:
	Window* window;
	Audio* audio;
	AssetLoader* assetLoader;
	LoadINI loadINI;
	TextEdit textEdit;
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
	sf::Vector2f calculateVector(sf::Vector2f const&, float, int);
	Ticker ticker;
	bool isMenu;
	std::string mouseClick;
	std::string keyboard;
	std::string keyboardDown;
	std::string keyboardSingle;
	std::string tempStr;
	std::string setKey;
	bool keyPress = false;
	bool typing = false;

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
};

#endif