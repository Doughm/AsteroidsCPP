//AsteroidsC++ 1.01
//Programer Douglas Harvey-Marose
//
//  Version Changes 1.01
//  complete refactor of the program
//  fixed a few minor graphic and audio bugs
//
// - Known isues -
//  all collision detection is bounding box, can look odd
//  rarely a level doesn't end, not sure how to fix
//
//  Assets from:
//  opengameart.org
//  The Games Factory Pro
//

#include "game.h"
#include "ticker.h"
#include "convert.h"
#include "gameTimer.h"
#include "assetLoader.h"
#include "window.h"
#include "audio.h"
#include <vector>
#include <string>
#pragma comment(linker, "/ENTRY:mainCRTStartup")

int main()
{
	Window* window = new Window();
	Audio* audio = new Audio;
	AssetLoader* assetLoader = new AssetLoader(window, audio);
	GameTimer gameTimer;
	Game game(window, audio, assetLoader);

	assetLoader->loadAssets("MainAssets");
	assetLoader->loadAssets("MainMenu");

	while (window->isOpen())
	{

		//updates the game logic
		if (gameTimer.getElapsedTimeMicroseconds() >= game.getUpdateSpeed())
		{
			game.inputUpdate();
			game.menuUpdate();
			game.keyboardBind();
			game.inputString();
			game.pause();
			if (game.isPlaying() == true)
			{
				game.checkBulletCollisions();
				game.checkShipCollisions();
				game.checkEndOfGame();
				game.entityUpdate();
				game.changeLevel();
				game.graphicUpdate();
				game.explosionLastFrame();
			}

			if (game.escape() == true)
			{
				break;
			}

			gameTimer.restartClock();
		}

		//updates the window
		window->drawAll();
	}

	delete assetLoader;
	delete window;
	delete audio;
    return 0;
}