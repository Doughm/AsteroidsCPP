#include "assetloader.h"

AssetLoader::AssetLoader(Window* passedWindow, Audio* passedAudio)
{
	window = passedWindow;
	audio = passedAudio;
}

AssetLoader::~AssetLoader()
{
	window = NULL;
	audio = NULL;
}

//loads in the staring assests
void AssetLoader::loadAssets(std::string const& asset)
{
	if (asset == "MainAssets")
	{
		window->setFont("fonts/arial.ttf");
		window->addSpriteSheet("sprites/spritemap.png");
		window->addSpriteMap("backgroundImg", sf::Vector2f(0, 0), 640, 480);
		window->addSpriteMap("asteroidLargeImg", sf::Vector2f(801, 0), 122, 149);
		window->addSpriteMap("asteroidMediumImg", sf::Vector2f(801, 333), 66, 81);
		window->addSpriteMap("asteroidSmallImg", sf::Vector2f(801, 151), 34, 35);
		window->addSpriteMap("shipImg", sf::Vector2f(801, 307), 36, 24);
		window->addSpriteMap("UFOImg", sf::Vector2f(870, 307), 35, 29);
		window->addSpriteMap("bulletImg", sf::Vector2f(849, 214), 14, 6);
		window->addSpriteMap("explosionImg1", sf::Vector2f(801, 220), 37, 34);
		window->addSpriteMap("explosionImg2", sf::Vector2f(839, 220), 37, 34);
		window->addSpriteMap("explosionImg3", sf::Vector2f(877, 220), 37, 34);
		window->addSpriteMap("explosionImg4", sf::Vector2f(915, 220), 37, 34);
		window->addSpriteMap("buttonImg", sf::Vector2f(801, 255), 150, 50);
		window->addSpriteMap("smallButtonImg", sf::Vector2f(800, 415), 150, 50);
		audio->addSample("boomSnd", "sound/boom2.wav");
		audio->addSample("shotSnd", "sound/pop1.wav");
	}
	else if (asset == "MainMenu")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addSprite("PlayButtonSpr", "buttonImg", sf::Vector2f(245, 240));
		window->addSprite("HighScoreButtonSpr", "buttonImg", sf::Vector2f(245, 300));
		window->addSprite("OptionsButtonSpr", "buttonImg", sf::Vector2f(245, 360));
		window->addText("TitleTxt", sf::Vector2f(175, 50), sf::Color::White, 70, "Asteroids");
		window->addText("PlayTxt", sf::Vector2f(290, 245), sf::Color::White, 30, "Play");
		window->addText("HighScoresTxt", sf::Vector2f(251, 310), sf::Color::White, 25, "High Scores");
		window->addText("SettingsTxt", sf::Vector2f(267, 365), sf::Color::White, 30, "Settings");
	}
	else if (asset == "HighScore")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addSprite("MenuButtonSpr", "buttonImg", sf::Vector2f(245, 360));
		window->addText("TitleTxt", sf::Vector2f(180, 50), sf::Color::White, 50, "High Scores");
		window->addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
		window->addText("NameTxt1", sf::Vector2f(380, 150), sf::Color::White, 30, "-");
		window->addText("NameTxt2", sf::Vector2f(380, 200), sf::Color::White, 30, "-");
		window->addText("NameTxt3", sf::Vector2f(380, 250), sf::Color::White, 30, "-");
		window->addText("NameTxt4", sf::Vector2f(380, 300), sf::Color::White, 30, "-");
		window->addText("ScoreTxt1", sf::Vector2f(200, 150), sf::Color::White, 30, "-");
		window->addText("ScoreTxt2", sf::Vector2f(200, 200), sf::Color::White, 30, "-");
		window->addText("ScoreTxt3", sf::Vector2f(200, 250), sf::Color::White, 30, "-");
		window->addText("ScoreTxt4", sf::Vector2f(200, 300), sf::Color::White, 30, "-");
	}
	else if (asset == "Options")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addSprite("MenuButtonSpr", "buttonImg", sf::Vector2f(245, 360));
		window->addSprite("KeyboardButtonSpr", "buttonImg", sf::Vector2f(245, 180));
		window->addSprite("SoundButtonSpr", "buttonImg", sf::Vector2f(245, 240));
		window->addSprite("ApplyButtonSpr", "buttonImg", sf::Vector2f(245, 300));
		window->addText("TitleTxt", sf::Vector2f(225, 50), sf::Color::White, 50, "Settings");
		window->addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
		window->addText("ApplyTxt", sf::Vector2f(282, 305), sf::Color::White, 30, "Apply");
		window->addText("SoundTxt", sf::Vector2f(255, 245), sf::Color::White, 29, "Sound On");
		window->addText("KeyboardTxt", sf::Vector2f(257, 186), sf::Color::White, 30, "Keyboard");
	}
	else if (asset == "Game")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addSprite("ShipSpr", "shipImg", sf::Vector2f(302, 228));
		window->addSprite("UFOSpr", "UFOImg", sf::Vector2f(-500, -500));
		window->batchAddSprite(4, "BulletSpr", "bulletImg", sf::Vector2f(-500, -500));
		window->batchAddSprite(12, "LargeAsteroidSpr", "asteroidLargeImg", sf::Vector2f(-500, -500));
		window->batchAddSprite(24, "MediumAsteroidSpr", "asteroidMediumImg", sf::Vector2f(-500, -500));
		window->batchAddSprite(48, "SmallAsteroidSpr", "asteroidSmallImg", sf::Vector2f(-500, -500));
		std::vector<std::string> tempVect;
		tempVect.push_back("explosionImg1");
		tempVect.push_back("explosionImg2");
		tempVect.push_back("explosionImg3");
		tempVect.push_back("explosionImg4");
		window->batchAddAnimation(4, "ExplosionAni", tempVect, sf::Vector2f(-500, -500), 1.75);
		window->pauseAnimation("ExplosionAni1");
		window->pauseAnimation("ExplosionAni2");
		window->pauseAnimation("ExplosionAni3");
		window->pauseAnimation("ExplosionAni4");
		window->addText("ScoreBoardTxt", sf::Vector2f(10, 0), sf::Color::White, 25, "Score: 0");
		window->addText("LevelTxt", sf::Vector2f(280, 0), sf::Color::White, 25, "Level: 1");
		window->addText("LivesTxt", sf::Vector2f(540, 0), sf::Color::White, 25, "Lives: 3");
		window->addText("PausedTxt", sf::Vector2f(-500, -500), sf::Color::White, 40, "Pause");
	}
	else if (asset == "KeyboardSetup")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addSprite("OptionsButtonSpr", "buttonImg", sf::Vector2f(245, 360));
		window->addSprite("ApplyButtonSpr", "buttonImg", sf::Vector2f(245, 300));
		window->addSprite("FireButtonSpr", "buttonImg", sf::Vector2f(50, 30));
		window->addSprite("PauseButtonSpr", "buttonImg", sf::Vector2f(50, 130));
		window->addSprite("HyperspaceButtonSpr", "buttonImg", sf::Vector2f(50, 230));
		window->addSprite("RightButtonSpr", "buttonImg", sf::Vector2f(350, 30));
		window->addSprite("LeftButtonSpr", "buttonImg", sf::Vector2f(350, 130));
		window->addSprite("AccelerateButtonSpr", "buttonImg", sf::Vector2f(350, 230));
		window->addText("FireTxt", sf::Vector2f(95, 30), sf::Color::White, 40, "Fire");
		window->addText("PauseTxt", sf::Vector2f(72, 130), sf::Color::White, 40, "Pause");
		window->addText("HyperspaceTxt", sf::Vector2f(56, 237), sf::Color::White, 26, "Hyperspace");
		window->addText("RightTxt", sf::Vector2f(380, 30), sf::Color::White, 40, "Right");
		window->addText("LeftTxt", sf::Vector2f(390, 130), sf::Color::White, 40, "Left");
		window->addText("AccelerateTxt", sf::Vector2f(356, 235), sf::Color::White, 30, "Accelerate");
		window->addText("FireKeyTxt", sf::Vector2f(220, 30), sf::Color::Green, 40, "-");
		window->addText("PauseKeyTxt", sf::Vector2f(220, 130), sf::Color::Green, 40, "-");
		window->addText("HyperspaceKeyTxt", sf::Vector2f(220, 230), sf::Color::Green, 40, "-");
		window->addText("RightKeyTxt", sf::Vector2f(520, 30), sf::Color::Green, 40, "-");
		window->addText("LeftKeyTxt", sf::Vector2f(520, 130), sf::Color::Green, 40, "-");
		window->addText("AccelerateKeyTxt", sf::Vector2f(520, 230), sf::Color::Green, 40, "-");
		window->addText("BackTxt", sf::Vector2f(288, 365), sf::Color::White, 30, "Back");
		window->addText("ApplyTxt", sf::Vector2f(282, 305), sf::Color::White, 30, "Apply");
		window->addText("PressKeyTxt", sf::Vector2f(-500, -500), sf::Color::Yellow, 40, "Press Any Key");
	}
	else if (asset == "EnterHighScore")
	{
		window->addSprite("BackgroundSpr", "backgroundImg", sf::Vector2f(0, 0));
		window->addText("CongratsTxt", sf::Vector2f(75, 50), sf::Color::White, 70, "Congratulations");
		window->addText("MadeScoreTxt", sf::Vector2f(105, 130), sf::Color::White, 40, "You Made A High Score!");
		window->addText("EnterNameTxt", sf::Vector2f(170, 180), sf::Color::Yellow, 40, "Enter Your Name");
		window->addText("NameTxt", sf::Vector2f(170, 250), sf::Color::Red, 40, "");
		window->addSprite("EnterButtonSpr", "buttonImg", sf::Vector2f(245, 360));
		window->addText("BackTxt", sf::Vector2f(285, 365), sf::Color::White, 30, "Done");
	}
	else if (asset == "Clear")
	{
		window->deleteAllEntitys();
	}
}