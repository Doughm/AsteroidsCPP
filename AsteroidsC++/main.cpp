//AsteroidsC++ 1.0
//Programer Douglas Harvey-Marose
//
// - Known isues -
//  all collision detection is bounding box, can look odd
//  rarely a level doesn't end, not sure how to fix
//  occasionally an explosion doesn't leave the screen, doesn't effect gameplay
//
//  Assets from:
//  opengameart.org
//  The Games Factory Pro
//

#include "program.h"
#include "game.h"
#include "ticker.h"
#include "convert.h"
#include "gameTimer.h"
#include <vector>
#include <string>
#pragma comment(linker, "/ENTRY:mainCRTStartup")

int main()
{
	Program program;
	program.start();
    return 0;
}

void Program::assetLoader(std::string const& asset)
{
	if(asset == "MainAssets")
	{
        window.setFont("fonts/arial.ttf");
        window.addSpriteSheet("sprites/spritemap.png");
        window.addSpriteMap("backgroundImg", sf::Vector2f(0,0), 640, 480);
        window.addSpriteMap("asteroidLargeImg", sf::Vector2f(801, 0), 122, 149);
        window.addSpriteMap("asteroidMediumImg", sf::Vector2f(801, 333), 66, 81);
        window.addSpriteMap("asteroidSmallImg", sf::Vector2f(801, 151), 34, 35);
        window.addSpriteMap("shipImg", sf::Vector2f(801, 307), 36, 24);
        window.addSpriteMap("UFOImg", sf::Vector2f(870, 307), 35, 29);
        window.addSpriteMap("bulletImg", sf::Vector2f(849, 214), 14, 6);
        window.addSpriteMap("expositionImg1", sf::Vector2f(801, 220), 37, 34);
        window.addSpriteMap("expositionImg2", sf::Vector2f(839, 220), 37, 34);
        window.addSpriteMap("expositionImg3", sf::Vector2f(877, 220), 37, 34);
        window.addSpriteMap("expositionImg4", sf::Vector2f(915, 220), 37, 34);
        window.addSpriteMap("buttonImg", sf::Vector2f(801, 255), 150, 50);
        window.addSpriteMap("smallButtonImg", sf::Vector2f(800, 415), 150, 50);
        audio.addSample("boomSnd", "sound/boom2.wav");
        audio.addSample("shotSnd", "sound/pop1.wav");
	}
	else if(asset == "MainMenu")
	{
        window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0,0));
        window.addSprite("PlayButtonSpr", "buttonImg", sf::Vector2f(245, 240));
        window.addSprite("HighScoreButtonSpr", "buttonImg", sf::Vector2f(245, 300));
        window.addSprite("OptionsButtonSpr", "buttonImg", sf::Vector2f(245, 360));
        window.addText("TitleTxt", sf::Vector2f(175,50), sf::Color::White, 70, "Asteroids");
        window.addText("PlayTxt", sf::Vector2f(290, 245), sf::Color::White, 30, "Play");
        window.addText("HighScoresTxt", sf::Vector2f(251, 310), sf::Color::White, 25, "High Scores");
        window.addText("SettingsTxt", sf::Vector2f(267, 365), sf::Color::White, 30, "Settings");
	}
	else if(asset == "HighScore")
	{
        window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
        window.addSprite("MenuButtonSpr", "buttonImg", sf::Vector2f(245, 360));
        window.addText("TitleTxt", sf::Vector2f(180, 50), sf::Color::White, 50, "High Scores");
        window.addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
        window.addText("ScoreTxt1", sf::Vector2f(200, 150), sf::Color::White, 30, "-");
        window.addText("ScoreTxt2", sf::Vector2f(200, 200), sf::Color::White, 30, "-");
        window.addText("ScoreTxt3", sf::Vector2f(200, 250), sf::Color::White, 30, "-");
        window.addText("ScoreTxt4", sf::Vector2f(200, 300), sf::Color::White, 30, "-");
	}
	else if(asset == "Options")
	{
        window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
        window.addSprite("MenuButtonSpr", "buttonImg", sf::Vector2f(245, 360));
        window.addSprite("KeyboardButtonSpr", "buttonImg", sf::Vector2f(245, 180));
        window.addSprite("SoundButtonSpr", "buttonImg", sf::Vector2f(245, 240));
        window.addSprite("ApplyButtonSpr", "buttonImg", sf::Vector2f(245, 300));
        window.addText("TitleTxt", sf::Vector2f(225, 50), sf::Color::White, 50, "Settings");
        window.addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
        window.addText("ApplyTxt", sf::Vector2f(282, 305), sf::Color::White, 30, "Apply");
        window.addText("SoundTxt", sf::Vector2f(255, 245), sf::Color::White, 29, "Sound On");
        window.addText("KeyboardTxt", sf::Vector2f(257, 186), sf::Color::White, 30, "Keyboard");
	}
	else if(asset == "Game")
	{
		window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window.addSprite("ShipSpr", "shipImg", sf::Vector2f(302, 228));
		window.addSprite("UFOSpr", "UFOImg", sf::Vector2f(-500, -500));
		window.batchAddSprite(4, "BulletSpr", "bulletImg", sf::Vector2f(-500, -500));
		window.batchAddSprite(12, "LargeAsteroidSpr", "asteroidLargeImg", sf::Vector2f(-500, -500));
		window.batchAddSprite(24,"MediumAsteroidSpr", "asteroidMediumImg", sf::Vector2f(-500, -500));
		window.batchAddSprite(48, "SmallAsteroidSpr", "asteroidSmallImg", sf::Vector2f(-500, -500));
		std::vector<std::string> tempVect;
		tempVect.push_back("expositionImg1");
		tempVect.push_back("expositionImg2");
		tempVect.push_back("expositionImg4");
		window.batchAddAnimation(4, "ExpositionAni", tempVect, sf::Vector2f(-500, -500), 1.75);
		window.pauseAnimation("ExpositionAni1");
		window.pauseAnimation("ExpositionAni2");
		window.pauseAnimation("ExpositionAni3");
		window.pauseAnimation("ExpositionAni4");
		window.addText("ScoreBoardTxt", sf::Vector2f(10, 0), sf::Color::White, 25, "Score: 0");
		window.addText("LevelTxt", sf::Vector2f(280, 0), sf::Color::White, 25, "Level: 1");
		window.addText("LivesTxt", sf::Vector2f(540, 0), sf::Color::White, 25, "Lives: 3");
		window.addText("PausedTxt", sf::Vector2f(-500, -500), sf::Color::White, 40, "Pause");
	}
	else if(asset == "KeyboardSetup")
	{
        window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
        window.addSprite("OptionsButtonSpr", "buttonImg", sf::Vector2f(245, 360));
        window.addSprite("ApplyButtonSpr", "buttonImg", sf::Vector2f(245, 300));
        window.addSprite("FireButtonSpr", "buttonImg", sf::Vector2f(50, 30));
        window.addSprite("PauseButtonSpr", "buttonImg", sf::Vector2f(50, 130));
        window.addSprite("HyperspaceButtonSpr", "buttonImg", sf::Vector2f(50, 230));
        window.addSprite("RightButtonSpr", "buttonImg", sf::Vector2f(350, 30));
        window.addSprite("LeftButtonSpr", "buttonImg", sf::Vector2f(350, 130));
        window.addSprite("AccelerateButtonSpr", "buttonImg", sf::Vector2f(350, 230));
        window.addText("FireTxt", sf::Vector2f(95, 30), sf::Color::White, 40, "Fire");
        window.addText("PauseTxt", sf::Vector2f(72, 130), sf::Color::White, 40, "Pause");
        window.addText("HyperspaceTxt", sf::Vector2f(56, 237), sf::Color::White, 26, "Hyperspace");
        window.addText("RightTxt", sf::Vector2f(380, 30), sf::Color::White, 40, "Right");
        window.addText("LeftTxt", sf::Vector2f(390, 130), sf::Color::White, 40, "Left");
        window.addText("AccelerateTxt", sf::Vector2f(356, 235), sf::Color::White, 30, "Accelerate");
        window.addText("FireKeyTxt", sf::Vector2f(220, 30), sf::Color::Green, 40, "-");
        window.addText("PauseKeyTxt", sf::Vector2f(220, 130), sf::Color::Green, 40, "-");
        window.addText("HyperspaceKeyTxt", sf::Vector2f(220, 230), sf::Color::Green, 40, "-");
        window.addText("RightKeyTxt", sf::Vector2f(520, 30), sf::Color::Green, 40, "-");
        window.addText("LeftKeyTxt", sf::Vector2f(520, 130), sf::Color::Green, 40, "-");
        window.addText("AccelerateKeyTxt", sf::Vector2f(520, 230), sf::Color::Green, 40, "-");
        window.addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
        window.addText("ApplyTxt", sf::Vector2f(282, 305), sf::Color::White, 30, "Apply");
        window.addText("PressKeyTxt", sf::Vector2f(-500, -500), sf::Color::Yellow, 40, "Press Any Key");
	}
	else if(asset == "EnterHighScore")
	{
        window.addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
        window.addText("CongratsTxt", sf::Vector2f(75, 50), sf::Color::White, 70, "Congratulations");
        window.addText("MadeScoreTxt", sf::Vector2f(105, 130), sf::Color::White, 40, "You Made A High Score!");
        window.addText("EnterNameTxt", sf::Vector2f(170, 180), sf::Color::Yellow, 40, "Enter Your Name");
        window.addText("NameTxt", sf::Vector2f(170, 250), sf::Color::Red, 40, "");
        window.addSprite("EnterButtonSpr", "buttonImg", sf::Vector2f(245, 360));
        window.addText("BackTxt", sf::Vector2f(285, 365), sf::Color::White, 30, "Done");
	}
	else if(asset == "Clear")
	{
		window.deleteAllEntitys();
	}
}

void Program::start()
{
	Game game;
	GameTimer gameTimer;
	assetLoader("MainAssets");
	assetLoader("MainMenu");
    Ticker ticker;
    bool isMenu = true;
    bool explosion = false;
    std::string mouseClick;
    std::string keyboard;
    std::string keyboardDown;
    std::string keyboardSingle;
    std::string tempStr;
    std::string setKey;
    bool keyPress = false;
    bool typing = false;
    sf::Vector2f tempVector;

	while(window.isOpen())
	{

		//updates the game logic
		if(gameTimer.getElapsedTimeMicroseconds() >= game.getUpdateSpeed())
		{

			//input update
			mouseClick.clear();
			keyboard.clear();
			keyboardDown.clear();
			keyboardSingle.clear();
			mouseClick.append(window.inputMouseClick());
			keyboard.append(window.inputKeyboard());
			keyboardDown.append(window.inputKeyboardDown());
			keyboardSingle.append(window.inputKeyboardSingle());
			
			if (isMenu == true)
            {
                if (mouseClick == "Leftbutton")
                {
                    if (window.isWithin("PlayButtonSpr", window.mousePositionView()))
                    {
                        isMenu = false;
                        game.updateFromFile();
						audio.setSoundOn(game.getSoundOn());
                        game.reset(0);
                        assetLoader("Clear");
                        assetLoader("Game");
                    }
                    else if (window.isWithin("HighScoreButtonSpr", window.mousePositionView()))
                    {
                        assetLoader("Clear");
                        assetLoader("HighScore");
						window.setText("ScoreTxt1", game.getHighScoreName(0) + "\t\t" + Convert::intToString(game.getHighScore(0)));
                        window.setText("ScoreTxt2", game.getHighScoreName(1) + "\t\t" + Convert::intToString(game.getHighScore(1)));
                        window.setText("ScoreTxt3", game.getHighScoreName(2) + "\t\t" + Convert::intToString(game.getHighScore(2)));
                        window.setText("ScoreTxt4", game.getHighScoreName(3) + "\t\t" + Convert::intToString(game.getHighScore(3)));
                    }
                    else if (window.isWithin("OptionsButtonSpr", window.mousePositionView()))
                    {
                        assetLoader("Clear");
                        assetLoader("Options");
                        game.updateFromFile();
						audio.setSoundOn(game.getSoundOn());
						if (game.getSoundOn() == true)
                        {
                            window.setText("SoundTxt", "Sound On");
                        }
                        else
                        {
                            window.setText("SoundTxt", "Sound Off");
                        }
                    }
                    else if (window.isWithin("MenuButtonSpr", window.mousePositionView()) && keyPress == false)
                    {
                        assetLoader("Clear");
                        assetLoader("MainMenu");
                    }
                    else if (window.isWithin("ApplyButtonSpr", window.mousePositionView()) && keyPress == false)
                    {
                        game.updateToFile();
                    }
                    else if (window.isWithin("SoundButtonSpr", window.mousePositionView()))
                    {
						if (game.getSoundOn() == true)
                        {
                            game.setSoundOn(false);
                            window.setText("SoundTxt", "Sound Off");
                        }
                        else
                        {
                            game.setSoundOn(true);
                            window.setText("SoundTxt", "Sound On");
                        }
                    }
                    else if (window.isWithin("KeyboardButtonSpr", window.mousePositionView()))
                    {
                        assetLoader("Clear");
                        assetLoader("KeyboardSetup");
                    }
                    else if (window.isWithin("FireButtonSpr", window.mousePositionView()))
                    {
                        setKey = "Fire";
                        keyPress = true;
                    }
                    else if (window.isWithin("PauseButtonSpr", window.mousePositionView()))
                    {
                        setKey = "Pause";
                        keyPress = true;
                    }
                    else if (window.isWithin("HyperspaceButtonSpr", window.mousePositionView()))
                    {
                        setKey = "HyperSpace";
                        keyPress = true;
                    }
                    else if (window.isWithin("RightButtonSpr", window.mousePositionView()))
                    {
                        setKey = "Right";
                        keyPress = true;
                    }
                    else if (window.isWithin("LeftButtonSpr", window.mousePositionView()))
                    {
                        setKey = "Left";
                        keyPress = true;
                    }
                    else if (window.isWithin("AccelerateButtonSpr", window.mousePositionView()))
                    {
                        setKey = "Accelerate";
                        keyPress = true;
                    }
                    else if (window.isWithin("EnterButtonSpr", window.mousePositionView()))
                    {
                        typing = false;
                        game.updateHighScoreTable(tempStr, game.getScore());
                        game.updateToFile();
                        assetLoader("Clear");
                        assetLoader("HighScore");
                        window.setText("ScoreTxt1", game.getHighScoreName(0) + "\t\t" + Convert::intToString(game.getHighScore(0)));
                        window.setText("ScoreTxt2", game.getHighScoreName(1) + "\t\t" + Convert::intToString(game.getHighScore(1)));
                        window.setText("ScoreTxt3", game.getHighScoreName(2) + "\t\t" + Convert::intToString(game.getHighScore(2)));
                        window.setText("ScoreTxt4", game.getHighScoreName(3) + "\t\t" + Convert::intToString(game.getHighScore(3)));
                    }
                }
                window.setText("FireKeyTxt", game.getFireKey());
                window.setText("PauseKeyTxt", game.getPauseKey());
                window.setText("HyperspaceKeyTxt", game.getHyperspaceKey());
                window.setText("RightKeyTxt", game.getRightKey());
                window.setText("LeftKeyTxt", game.getLeftKey());
                window.setText("AccelerateKeyTxt", game.getAccelerateKey());
            }

			//takes in a single key and adds it to the keyboard bindings
            if (keyPress == true)
            {
				tempVector.x = 195;
				tempVector.y = 420;
                window.moveEntity("PressKeyTxt", tempVector);
                if (keyboardSingle != "")
                {
					if(setKey == "Fire")
					{
						game.setFireKey(keyboardSingle);
                        keyPress = false;
					}
					else if(setKey == "Pause")
					{
                        game.setPauseKey(keyboardSingle);
                        keyPress = false;
					}
					else if(setKey == "HyperSpace")
					{
                        game.setHyperspaceKey(keyboardSingle);
                        keyPress = false;
					}
					else if(setKey == "Right")
					{
                        game.setRightKey(keyboardSingle);
                        keyPress = false;
					}
					else if(setKey == "Left")
					{
                        game.setLeftKey(keyboardSingle);
                        keyPress = false;
					}
					else if(setKey == "Accelerate")
					{
                        game.setAccelerateKey(keyboardSingle);
                        keyPress = false;
					}
                }
            }
            else
            {
				tempVector.x = -500;
				tempVector.y = -500;
                window.moveEntity("PressKeyTxt", tempVector);
            }

			//takes in a string one key at a time for the highscore table
            if (typing == true)
            {
                ticker.increment();
				
            }
            if (typing == true && ticker.atAmount(5) && keyboard != "")
            {
                if (keyboardSingle.find("Backspace") != std::string::npos)
                {
					if (tempStr.length() != 0)
                    {
						std::string newString = "";
						for(int i=0; i < tempStr.size()-1 ; i++)
						{
							newString.push_back(tempStr[i]);
						}
                        tempStr = newString;
                    }
                }
				else if (keyboardSingle.find("Return") != std::string::npos)
                {
                    typing = false;
                    game.updateHighScoreTable(tempStr, game.getScore());
                    game.updateToFile();
                    assetLoader("Clear");
                    assetLoader("HighScore");
					window.setText("ScoreTxt1", game.getHighScoreName(0) + "\t\t" + Convert::intToString(game.getHighScore(0)));
                    window.setText("ScoreTxt2", game.getHighScoreName(1) + "\t\t" + Convert::intToString(game.getHighScore(1)));
                    window.setText("ScoreTxt3", game.getHighScoreName(2) + "\t\t" + Convert::intToString(game.getHighScore(2)));
                    window.setText("ScoreTxt4", game.getHighScoreName(3) + "\t\t" + Convert::intToString(game.getHighScore(3)));
                }
				else if (keyboard == "A" || keyboard == "B" || keyboard == "C" ||
                        keyboard == "D" || keyboard == "E" || keyboard == "F" ||
                        keyboard == "G" || keyboard == "H" || keyboard == "I" ||
                        keyboard == "J" || keyboard == "K" || keyboard == "L" ||
                        keyboard == "M" || keyboard == "N" || keyboard == "O" ||
                        keyboard == "P" || keyboard == "Q" || keyboard == "R" ||
                        keyboard == "S" || keyboard == "T" || keyboard == "U" ||
                        keyboard == "V" || keyboard == "W" || keyboard == "X" ||
                        keyboard == "Y" || keyboard == "Z")
                {
					std::locale loc;
					tempStr.push_back(std::tolower(keyboard[0], loc));
                }
                else if (keyboard == "ALshift" || keyboard == "BLshift" || keyboard == "CLshift" ||
                        keyboard == "DLshift" || keyboard == "ELshift" || keyboard == "FLshift" ||
                        keyboard == "GLshift" || keyboard == "HLshift" || keyboard == "ILshift" ||
                        keyboard == "JLshift" || keyboard == "KLshift" || keyboard == "LLshift" ||
                        keyboard == "MLshift" || keyboard == "NLshift" || keyboard == "OLshift" ||
                        keyboard == "PLshift" || keyboard == "QLshift" || keyboard == "RLshift" ||
                        keyboard == "SLshift" || keyboard == "TLshift" || keyboard == "ULshift" ||
                        keyboard == "VLshift" || keyboard == "WLshift" || keyboard == "XLshift" ||
                        keyboard == "YLshift" || keyboard == "ZLshift" ||
						keyboard == "ARshift" || keyboard == "BRshift" || keyboard == "CRshift" ||
                        keyboard == "DRshift" || keyboard == "ERshift" || keyboard == "FRshift" ||
                        keyboard == "GRshift" || keyboard == "HRshift" || keyboard == "IRshift" ||
                        keyboard == "JRshift" || keyboard == "KRshift" || keyboard == "LRshift" ||
                        keyboard == "MRshift" || keyboard == "NRshift" || keyboard == "ORshift" ||
                        keyboard == "PRshift" || keyboard == "QRshift" || keyboard == "RRshift" ||
                        keyboard == "SRshift" || keyboard == "TRshift" || keyboard == "URshift" ||
                        keyboard == "VRshift" || keyboard == "WRshift" || keyboard == "XRshift" ||
                        keyboard == "YRshift" || keyboard == "ZRshift")
                {
                    tempStr += keyboard[0];
                }
                ticker.resetCounter();
                window.setText("NameTxt", tempStr);
            }

			//exits to the main menu if Esc is pressed during the game
            //exits the program if its pressed in the menus
            if (keyboardDown.find("Escape") != std::string::npos)
            {
				
                if (isMenu == false)
                {
                    assetLoader("Clear");
                    assetLoader("MainMenu");
                    isMenu = true;
                }
                else
                    break;
            }
            //unpauses the game
            if (game.getIsPaused() == true)
            {
                if (keyboardDown.find(game.getPauseKey()) != std::string::npos)
                {
					tempVector.x = -500;
					tempVector.y = -500;
                    window.moveEntity("PausedTxt", tempVector);
                    game.setIsPaused(false);
                }
            }
			//game logic
			else if (game.getIsPaused() == false && isMenu == false)
			{
				//pauses the game
                if (keyboardDown.find(game.getPauseKey()) != std::string::npos)
                {
                    game.setIsPaused(true);
					tempVector.x = 270;
					tempVector.y = 210;
                    window.moveEntity("PausedTxt", tempVector);
                }

				//checks for collisions with bullets
				for (int i = 1; i < 5; ++i)
				{
					if (game.getBulletIsVisible(i - 1))
					{
						tempStr = window.batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "LargeAsteroidSpr");
						for (int ii = 1; ii < 13; ++ii)
						{
							if (tempStr.find("LargeAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
							{
								tempVector.x = game.getLargeAsteroidsPosition(ii - 1).x + 43;
								tempVector.y = game.getLargeAsteroidsPosition(ii - 1).y + 57;
								game.createExplosion(tempVector);
								window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
								game.destroyBullet(i - 1);
								game.destroyLargeAsteroid(ii - 1);
								explosion = true;
								window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
							}
						}
						tempStr = window.batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "MediumAsteroidSpr");
						for (int ii = 1; ii < 25; ++ii)
						{
							if (tempStr.find("MediumAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
							{
								tempVector.x = game.getMediumAsteroidsPosition(ii - 1).x + 15;
								tempVector.y = game.getMediumAsteroidsPosition(ii - 1).y + 23;
								game.createExplosion(tempVector);
								window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
								game.destroyBullet(i - 1);
								game.destroyMediumAsteroid(ii - 1);
								explosion = true;
								window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
							}
						}
						tempStr = window.batchIsOverlapping(("BulletSpr" + Convert::intToString(i)), "SmallAsteroidSpr");
						for (int ii = 1; ii < 25; ++ii)
						{
							if (tempStr.find("SmallAsteroidSpr" + Convert::intToString(ii)) != std::string::npos)
							{
								
								game.createExplosion(game.getSmallAsteroidsPosition(ii - 1));
								window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
								game.destroyBullet(i - 1);
								game.destroySmallAsteroid(ii - 1);
								explosion = true;
								window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
							}
						}
						if (window.isOverlapping("BulletSpr" + Convert::intToString(i), "UFOSpr"))
						{
							game.createExplosion(game.getUfoPosition());
							window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
							game.destroyBullet(i - 1);
							game.destroyUFO();
						}
					}
				}
				//checks for collisions with the ship
                tempStr = window.batchIsOverlapping(("ShipSpr"), "LargeAsteroidSpr");
                if (tempStr.find("LargeAsteroidSpr") != std::string::npos && game.getShipIsVisible() == true)
                {
					tempVector.x = game.getShipPosition().x;
					tempVector.y = game.getShipPosition().y - 8;
                    game.createExplosion(tempVector);
                    window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
                    game.destroyShip();
                    game.destroyBullet(0);
                    game.destroyBullet(1);
                    game.destroyBullet(2);
                    game.destroyBullet(3);
                    explosion = true;
					window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
                }
                tempStr = window.batchIsOverlapping(("ShipSpr"), "MediumAsteroidSpr");
                if (tempStr.find("MediumAsteroidSpr") != std::string::npos && game.getShipIsVisible() == true)
                {
					tempVector.x = game.getShipPosition().x;
					tempVector.y = game.getShipPosition().y - 8;
                    game.createExplosion(tempVector);
                    window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
                    game.destroyShip();
                    game.destroyBullet(0);
                    game.destroyBullet(1);
                    game.destroyBullet(2);
                    game.destroyBullet(3);
                    explosion = true;
					window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
                }
                tempStr = window.batchIsOverlapping(("ShipSpr"), "SmallAsteroidSpr");
                if (tempStr.find("SmallAsteroidSpr") != std::string::npos && game.getShipIsVisible() == true)
                {
					tempVector.x = game.getShipPosition().x;
					tempVector.y = game.getShipPosition().y - 8;
                    game.createExplosion(tempVector);
                    window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
                    game.destroyShip();
                    game.destroyBullet(0);
                    game.destroyBullet(1);
                    game.destroyBullet(2);
                    game.destroyBullet(3);
                    explosion = true;
					window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
                }
                if (window.isOverlapping("ShipSpr", "UFOSpr") && game.getShipIsVisible() == true)
                {
					tempVector.x = game.getShipPosition().x;
					tempVector.y = game.getShipPosition().y - 8;
                    game.createExplosion(tempVector);
                    window.goToFrame("ExpositionAni" + Convert::intToString(game.getExplosionNumber()), 0);
                    game.destroyShip();
                    game.destroyBullet(0);
                    game.destroyBullet(1);
                    game.destroyBullet(2);
                    game.destroyBullet(3);
                    explosion = true;
					window.resumeAnimation("ExpositionAni" + Convert::intToString(game.getExplosionNumber()));
                }
				

				//ends the game if you are out of lives
                if (game.getShipIsVisible() == false && game.getLives() > 0)
                {
                    game.shipRespawn();
                }
                else if (game.getShipIsVisible() == false && game.getLives() == 0)
                {
                    ticker.increment();
                }
                if (ticker.atAmount(70) && game.getShipIsVisible() == false)
                {
                    ticker.resetCounter();
                    isMenu = true;
                    assetLoader("Clear");
                    if (game.getScore() > game.getHighScore(0) ||
                        game.getScore() > game.getHighScore(1) ||
                        game.getScore() > game.getHighScore(2) ||
                        game.getScore() > game.getHighScore(3))
                    {
                        assetLoader("EnterHighScore");
						tempStr.clear();
                        typing = true;
						tempStr.clear();
                    }
                    else
                    {
                        assetLoader("MainMenu");
                    }
                }

				//updates all entitys
				game.makeUFO();
				game.fireBullet(keyboardDown);
				game.moveShip(keyboard);
				game.hyperspaceJump(keyboardDown);
				game.wrapEntitys();
				game.updatePositions();

				//updates the hud
				window.setText("ScoreBoardTxt","Score: " + Convert::intToString(game.getScore()));
				window.setText("LevelTxt", "Level: " + Convert::intToString(game.getLevel()));
				window.setText("LivesTxt", "Lives: " + Convert::intToString(game.getLives()));

				//play sounds
				if (keyboardDown.find(game.getFireKey()) != std::string::npos)
				{
					audio.samplePlay("shotSnd");
				}
				if (explosion == true)
				{
					explosion = false;
					audio.samplePlay("boomSnd");
				}

				//changes the level
				if (game.levelEnded())
				{
					ticker.increment();
				}
				if (game.levelEnded() && ticker.atAmount(30))
				{
					ticker.resetCounter();
					game.nextLevel();
				}

				//sets the position and direction of the ship
				window.rotateEntityCenter("ShipSpr", game.getShipAngle());
				window.moveEntity("ShipSpr", game.getShipPosition());

				//sets the position of the expositions
				window.moveEntity(("ExpositionAni1"), game.getExplosionPosition(0));
				window.moveEntity(("ExpositionAni2"), game.getExplosionPosition(1));
				window.moveEntity(("ExpositionAni3"), game.getExplosionPosition(2));
				window.moveEntity(("ExpositionAni4"), game.getExplosionPosition(3));

				//sets the position of the UFO
				window.moveEntity("UFOSpr", game.getUfoPosition());

				//sets the direction of bullets
				window.rotateEntityCenter("BulletSpr1", game.getBulletAngle(0));
				window.rotateEntityCenter("BulletSpr2", game.getBulletAngle(1));
				window.rotateEntityCenter("BulletSpr3", game.getBulletAngle(2));
				window.rotateEntityCenter("BulletSpr4", game.getBulletAngle(3));

				//sets the position of bullets
				window.moveEntity("BulletSpr1", game.getBulletPosition(0));
				window.moveEntity("BulletSpr2", game.getBulletPosition(1));
				window.moveEntity("BulletSpr3", game.getBulletPosition(2));
				window.moveEntity("BulletSpr4", game.getBulletPosition(3));

				//sets the position of the large asteroids
				window.moveEntity(("LargeAsteroidSpr1"), game.getLargeAsteroidsPosition(0));
				window.moveEntity(("LargeAsteroidSpr2"), game.getLargeAsteroidsPosition(1));
				window.moveEntity(("LargeAsteroidSpr3"), game.getLargeAsteroidsPosition(2));
				window.moveEntity(("LargeAsteroidSpr4"), game.getLargeAsteroidsPosition(3));
				window.moveEntity(("LargeAsteroidSpr5"), game.getLargeAsteroidsPosition(4));
				window.moveEntity(("LargeAsteroidSpr6"), game.getLargeAsteroidsPosition(5));
				window.moveEntity(("LargeAsteroidSpr7"), game.getLargeAsteroidsPosition(6));
				window.moveEntity(("LargeAsteroidSpr8"), game.getLargeAsteroidsPosition(7));
				window.moveEntity(("LargeAsteroidSpr9"), game.getLargeAsteroidsPosition(8));
				window.moveEntity(("LargeAsteroidSpr10"), game.getLargeAsteroidsPosition(9));
				window.moveEntity(("LargeAsteroidSpr11"), game.getLargeAsteroidsPosition(10));
				window.moveEntity(("LargeAsteroidSpr12"), game.getLargeAsteroidsPosition(11));
				//sets the position of the medium asteroids
				window.moveEntity(("MediumAsteroidSpr1"), game.getMediumAsteroidsPosition(0));
				window.moveEntity(("MediumAsteroidSpr2"), game.getMediumAsteroidsPosition(1));
				window.moveEntity(("MediumAsteroidSpr3"), game.getMediumAsteroidsPosition(2));
				window.moveEntity(("MediumAsteroidSpr4"), game.getMediumAsteroidsPosition(3));
				window.moveEntity(("MediumAsteroidSpr5"), game.getMediumAsteroidsPosition(4));
				window.moveEntity(("MediumAsteroidSpr6"), game.getMediumAsteroidsPosition(5));
				window.moveEntity(("MediumAsteroidSpr7"), game.getMediumAsteroidsPosition(6));
				window.moveEntity(("MediumAsteroidSpr8"), game.getMediumAsteroidsPosition(7));
				window.moveEntity(("MediumAsteroidSpr9"), game.getMediumAsteroidsPosition(8));
				window.moveEntity(("MediumAsteroidSpr10"), game.getMediumAsteroidsPosition(9));
				window.moveEntity(("MediumAsteroidSpr11"), game.getMediumAsteroidsPosition(10));
				window.moveEntity(("MediumAsteroidSpr12"), game.getMediumAsteroidsPosition(11));
				window.moveEntity(("MediumAsteroidSpr13"), game.getMediumAsteroidsPosition(12));
				window.moveEntity(("MediumAsteroidSpr14"), game.getMediumAsteroidsPosition(13));
				window.moveEntity(("MediumAsteroidSpr15"), game.getMediumAsteroidsPosition(14));
				window.moveEntity(("MediumAsteroidSpr16"), game.getMediumAsteroidsPosition(15));
				window.moveEntity(("MediumAsteroidSpr17"), game.getMediumAsteroidsPosition(16));
				window.moveEntity(("MediumAsteroidSpr18"), game.getMediumAsteroidsPosition(17));
				window.moveEntity(("MediumAsteroidSpr19"), game.getMediumAsteroidsPosition(18));
				window.moveEntity(("MediumAsteroidSpr20"), game.getMediumAsteroidsPosition(19));
				window.moveEntity(("MediumAsteroidSpr21"), game.getMediumAsteroidsPosition(20));
				window.moveEntity(("MediumAsteroidSpr22"), game.getMediumAsteroidsPosition(21));
				window.moveEntity(("MediumAsteroidSpr23"), game.getMediumAsteroidsPosition(22));
				window.moveEntity(("MediumAsteroidSpr24"), game.getMediumAsteroidsPosition(23));
				//sets the position of the small asteroids
				window.moveEntity(("SmallAsteroidSpr1"), game.getSmallAsteroidsPosition(0));
				window.moveEntity(("SmallAsteroidSpr2"), game.getSmallAsteroidsPosition(1));
				window.moveEntity(("SmallAsteroidSpr3"), game.getSmallAsteroidsPosition(2));
				window.moveEntity(("SmallAsteroidSpr4"), game.getSmallAsteroidsPosition(3));
				window.moveEntity(("SmallAsteroidSpr5"), game.getSmallAsteroidsPosition(4));
				window.moveEntity(("SmallAsteroidSpr6"), game.getSmallAsteroidsPosition(5));
				window.moveEntity(("SmallAsteroidSpr7"), game.getSmallAsteroidsPosition(6));
				window.moveEntity(("SmallAsteroidSpr8"), game.getSmallAsteroidsPosition(7));
				window.moveEntity(("SmallAsteroidSpr9"), game.getSmallAsteroidsPosition(8));
				window.moveEntity(("SmallAsteroidSpr10"), game.getSmallAsteroidsPosition(9));
				window.moveEntity(("SmallAsteroidSpr11"), game.getSmallAsteroidsPosition(10));
				window.moveEntity(("SmallAsteroidSpr12"), game.getSmallAsteroidsPosition(11));
				window.moveEntity(("SmallAsteroidSpr13"), game.getSmallAsteroidsPosition(12));
				window.moveEntity(("SmallAsteroidSpr14"), game.getSmallAsteroidsPosition(13));
				window.moveEntity(("SmallAsteroidSpr15"), game.getSmallAsteroidsPosition(14));
				window.moveEntity(("SmallAsteroidSpr16"), game.getSmallAsteroidsPosition(15));
				window.moveEntity(("SmallAsteroidSpr17"), game.getSmallAsteroidsPosition(16));
				window.moveEntity(("SmallAsteroidSpr18"), game.getSmallAsteroidsPosition(17));
				window.moveEntity(("SmallAsteroidSpr19"), game.getSmallAsteroidsPosition(18));
				window.moveEntity(("SmallAsteroidSpr20"), game.getSmallAsteroidsPosition(19));
				window.moveEntity(("SmallAsteroidSpr21"), game.getSmallAsteroidsPosition(20));
				window.moveEntity(("SmallAsteroidSpr22"), game.getSmallAsteroidsPosition(21));
				window.moveEntity(("SmallAsteroidSpr23"), game.getSmallAsteroidsPosition(22));
				window.moveEntity(("SmallAsteroidSpr24"), game.getSmallAsteroidsPosition(23));
				window.moveEntity(("SmallAsteroidSpr25"), game.getSmallAsteroidsPosition(24));
				window.moveEntity(("SmallAsteroidSpr26"), game.getSmallAsteroidsPosition(25));
				window.moveEntity(("SmallAsteroidSpr27"), game.getSmallAsteroidsPosition(26));
				window.moveEntity(("SmallAsteroidSpr28"), game.getSmallAsteroidsPosition(27));
				window.moveEntity(("SmallAsteroidSpr29"), game.getSmallAsteroidsPosition(28));
				window.moveEntity(("SmallAsteroidSpr30"), game.getSmallAsteroidsPosition(29));
				window.moveEntity(("SmallAsteroidSpr31"), game.getSmallAsteroidsPosition(30));
				window.moveEntity(("SmallAsteroidSpr32"), game.getSmallAsteroidsPosition(31));
				window.moveEntity(("SmallAsteroidSpr33"), game.getSmallAsteroidsPosition(32));
				window.moveEntity(("SmallAsteroidSpr34"), game.getSmallAsteroidsPosition(33));
				window.moveEntity(("SmallAsteroidSpr35"), game.getSmallAsteroidsPosition(34));
				window.moveEntity(("SmallAsteroidSpr36"), game.getSmallAsteroidsPosition(35));
				window.moveEntity(("SmallAsteroidSpr37"), game.getSmallAsteroidsPosition(36));
				window.moveEntity(("SmallAsteroidSpr38"), game.getSmallAsteroidsPosition(37));
				window.moveEntity(("SmallAsteroidSpr39"), game.getSmallAsteroidsPosition(38));
				window.moveEntity(("SmallAsteroidSpr40"), game.getSmallAsteroidsPosition(39));
				window.moveEntity(("SmallAsteroidSpr41"), game.getSmallAsteroidsPosition(40));
				window.moveEntity(("SmallAsteroidSpr42"), game.getSmallAsteroidsPosition(41));
				window.moveEntity(("SmallAsteroidSpr43"), game.getSmallAsteroidsPosition(42));
				window.moveEntity(("SmallAsteroidSpr44"), game.getSmallAsteroidsPosition(43));
				window.moveEntity(("SmallAsteroidSpr45"), game.getSmallAsteroidsPosition(44));
				window.moveEntity(("SmallAsteroidSpr46"), game.getSmallAsteroidsPosition(45));
				window.moveEntity(("SmallAsteroidSpr47"), game.getSmallAsteroidsPosition(46));
				window.moveEntity(("SmallAsteroidSpr48"), game.getSmallAsteroidsPosition(47));
				
				//destroys expositions if its animation is at the last frame
				if (window.getAnimationFrame("ExpositionAni1") == 2)
				{
					game.destroyExposition(0);
					window.goToFrame("ExpositionAni1", 0);
					window.pauseAnimation("ExpositionAni1");
				}
				else if(window.getAnimationFrame("ExpositionAni2") == 2)
				{
					game.destroyExposition(1);
					window.goToFrame("ExpositionAni2", 0);
					window.pauseAnimation("ExpositionAni2");
				}
				else if(window.getAnimationFrame("ExpositionAni3") == 2)
				{
					game.destroyExposition(2);
					window.goToFrame("ExpositionAni3", 0);
					window.pauseAnimation("ExpositionAni3");
				}
				else if(window.getAnimationFrame("ExpositionAni4") == 2)
				{
					game.destroyExposition(3);
					window.goToFrame("ExpositionAni4", 0);
					window.pauseAnimation("ExpositionAni4");
				}
			}

			//restarts the logic timer
			gameTimer.restartClock();
		}

		//updates the window
		window.drawAll();
	}
}