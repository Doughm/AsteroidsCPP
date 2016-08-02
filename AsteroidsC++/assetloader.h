#ifndef ASSETLOADER
#define ASSETLOADER

#include <string>
#include <SFML/Graphics.hpp>
#include "window.h"
#include "audio.h"

class AssetLoader
{
public:
	AssetLoader(Window*, Audio*);
	~AssetLoader();
	void loadAssets(std::string const& asset);

private:
	Window* window;
	Audio* audio;
};

#endif