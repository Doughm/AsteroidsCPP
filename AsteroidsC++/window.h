#ifndef ENGINE
#define ENGINE

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include "quad.h"
#include "animation.h"
#include "gametimer.h"
#include "loadini.h"
#include "gametimer.h"

class Window
{
public:
	Window();
	bool isOpen();
	void drawAll();
	std::string inputKeyboard();
	std::string inputKeyboardSingle();
	std::string inputMouse();
	std::string inputMouseSingle();
	std::string inputKeyboardDown();
	std::string inputKeyboardDownSingle();
	std::string inputMouseClick();
	std::string inputMouseClickSingle();
	sf::Vector2i mousePosistionRaw();
	sf::Vector2i mousePositionWindow();
	sf::Vector2f mousePositionView();
	void addView(std::string const&, int, int, sf::Vector2f const&);
	void addSpriteSheet(std::string const&);
	void addSpriteMap(std::string const&, sf::Vector2f const&, int, int);
	void addQuad(std::string const&, sf::Vertex const&, sf::Vertex const&, sf::Vertex const&,sf::Vertex const&);
	void addSprite(std::string const&, std::string const&, sf::Vector2f const&);
	void addRectangle(std::string const&, sf::Vector2f const&, int, int, sf::Color const&);
	void addRectangle(std::string const&, sf::Vector2f const&, int, int, sf::Color const&, sf::Color const&,sf::Color const&,sf::Color const&);
	void addText(std::string const&, sf::Vector2f const&, sf::Color const&, int, std::string const&);
	void addCircle(std::string const&, sf::Vector2f const&, sf::Color const&, int);
	void addAnimation(std::string const&, std::vector<std::string> const&, sf::Vector2f const&, float);
	void batchAddQuad(int, std::string const&, sf::Vertex const&, sf::Vertex const&, sf::Vertex const&,sf::Vertex const&);
	void batchAddSprite(int, std::string const&, std::string const&, sf::Vector2f const&);
	void batchAddRectangle(int, std::string const&, sf::Vector2f const&, int, int, sf::Color const&);
	void batchAddRectangle(int, std::string const&, sf::Vector2f const&, int, int, sf::Color const&, sf::Color const&,sf::Color const&,sf::Color const&);
	void batchAddText(int, std::string const&, sf::Vector2f const&, sf::Color const&, int, std::string const&);
	void batchAddCircle(int, std::string const&, sf::Vector2f const&, sf::Color const&, int);
	void batchAddAnimation(int, std::string const&, std::vector<std::string> const&, sf::Vector2f const&, float);
	int batchNumber(std::string const&);
	void deleteEntity(std::string const&);
	void deleteAllEntitys();
	void deleteAll();
	void deleteViews();
	bool entityExists(std::string const&);
	void moveEntity(std::string const&, sf::Vector2f const&);
	void scaleEntity(std::string const&, float);
	void scaleEntity(std::string const&, sf::Vector2f const&);
	void rotateEntity(std::string const&, float);
	void rotateEntityCenter(std::string const&, float);
	bool isWithin(std::string const&, sf::Vector2f const&);
	bool isOverlapping(std::string const&, std::string const&);
	bool isWithinArea(std::string const&, sf::Vector2f const&, int, int);
	bool isWithinWindow(std::string const&);
	bool isWithinWindow(std::string const&, int, int);
	std::string batchIsWithin(std::string const&, sf::Vector2f const&);
	std::string batchIsOverlapping(std::string const&, std::string const&);
	void pauseAnimation(std::string const&);
	void resumeAnimation(std::string const&);
	void goToFrame(std::string const&, int);
	bool boundingBoxPoint(sf::Vector2f const&, sf::Vector2f const&, int, int);
	bool boudingCirclePoint(sf::Vector2f, sf::Vector2f const&, int);
	bool boundingBoxOverlap(sf::Vector2f, int, int, sf::Vector2f, int, int);
	bool boundingCircleOverlap(sf::Vector2f const&, int, sf::Vector2f const&, int);
	void makeVisible(std::string const&);
	void makeInvisible(std::string const&);
	void moveView(std::string, sf::Vector2f);
	void rotateView(std::string, float);
	void zoomView(std::string, float);

	//sets and gets
	void setBackgroundColor(sf::Color const&);
	void setFont(std::string const&);
	void setAnimationSpeed(std::string const&, float);
	void setColor(std::string const&, sf::Color const&);
	void setColor(std::string const&, sf::Color const&, sf::Color const&, sf::Color const&, sf::Color const&);
	void setCircleOutline(std::string const&, sf::Color const&, int);
	void setText(std::string const&, std::string const&);
	void setView(std::string const&);
	sf::Vector2f getPointOfOrigin(std::string const&);
	double getRotation(std::string const&);
	std::string getText(std::string const&);
	bool getAnimationPaused(std::string const&);
	bool getAnimationLoops(std::string const&);
	int getAnimationFrame(std::string const&);
	Quad getQuad(std::string const&);
	int getVertexArrayCount();
	int getEntitysCount();
	int getCirclesCount();
	int getTextCount();
	int getAnimationCount();
	std::string getAllEntities();
	sf::Vector2f getResolution();

private:
	const double PI;
	sf::RenderWindow gameWindow;
	sf::Event event;
	std::string programName;
	int resolutionX;
	int resolutionY;
	int fps;
	double updateSpeed;
	bool FPSLimit;
	sf::Color background;
	sf::Font font;
	std::string mouseClick;
	std::string keyboardDown;
	std::string tempStr;
	sf::Vector2f tempVector;
	sf::Vector2f middle;
	double currentAngle;
	double distance;
	GameTimer gameTimer;
	LoadINI loadINI;
	sf::Vertex *vertexArray;
	unsigned int vertexCount;
	sf::RenderStates state;
	std::unordered_map<std::string, sf::View> views;
	std::unordered_map<std::string, Quad> entitys;
	std::unordered_map<std::string, sf::FloatRect> spriteMaps;
	std::unordered_map<std::string, sf::CircleShape> circles;
	std::unordered_map<std::string, sf::Text> text;
	std::unordered_map<std::string, sf::Color> colorMap;
	std::unordered_map<std::string, Animation> animations;
	std::unordered_map<std::string, Quad>::iterator entityIterator;
	std::unordered_map<std::string, sf::CircleShape>::iterator circleIterator;
	std::unordered_map<std::string, sf::Text>::iterator textIterator;
	std::unordered_map<std::string, Animation>::iterator animationIterator;

	void copyQuad(Quad const&);
	void copyQuad(Quad const&, int);
	void playAnimation(std::string const&);
};

#endif