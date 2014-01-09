#include "audio.h"

Audio::Audio()
{
	soundOn = true;
}

Audio::~Audio()
{
	clearAll();
	delete soundBuffer;
}

//returns if the sound is on or off
bool Audio::getSoundOn()
{
	return soundOn;
}

//sets if the sound is off or on
void Audio::setSoundOn(bool sound)
{
	soundOn = sound;
}

//turns sound on or off
void Audio::soundToggle()
{
	if (soundOn == true)
    {
        soundOn = false;
    }
    else
    {
        soundOn = true;
    }
}

//adds a new sound into memory
void Audio::addSample(std::string const& name, std::string const& file)
{
	if (soundOn==true)
    {
		soundBuffer = new sf::SoundBuffer();
		soundBuffer->loadFromFile(file);
		sampleMap[name].setBuffer(*soundBuffer);
    }
}

//plays a sample
void Audio::samplePlay(std::string const& name)
{
	if (soundOn==true)
    {
		sampleMap[name].play();
	}
}

//pauses a sample
void Audio::samplePause(std::string const& name)
{
	if (soundOn==true)
    {
		sampleMap[name].pause();
	}
}

//sets if a sample loops
void Audio::sampleLoop(std::string const& name, bool loop)
{
	if (soundOn==true)
    {
		sampleMap[name].setLoop(loop);
	}
}

//stops a sample playing
void Audio::sampleStop(std::string const& name)
{
	if (soundOn==true)
    {
		sampleMap[name].stop();
	}
}

//sets the volume of the sample [0 -100]
void Audio::sampleVolume(std::string const& name, float volume)
{
	if (soundOn==true)
    {
		sampleMap[name].setVolume(volume);
	}
}

//adds a file to play from the hard drive
void Audio::addMusic(std::string const& name, std::string const& file)
{
	if (soundOn==true)
    {
		musicMap[name] = new sf::Music;
		musicMap[name]->openFromFile(file);
	}
}

//plays a music file
void Audio::musicPlay(std::string const& name)
{
	if (soundOn==true)
    {
		musicMap[name]->play();
	}
}

//pauses a music file
void Audio::musicPause(std::string const& name)
{
	if (soundOn==true)
    {
		musicMap[name]->pause();
	}
}

//sets if a music file loops
void Audio::musicLoop(std::string const& name, bool loop)
{
	if (soundOn==true)
    {
		musicMap[name]->setLoop(loop);
	}
}

//stops a music file from playing
void Audio::musicStop(std::string const& name)
{
	if (soundOn==true)
    {
		musicMap[name]->stop();
	}
}

//sets the volume of the music [0 -100]
void Audio::musicVolume(std::string const& name, float volume)
{
	if (soundOn==true)
    {
		musicMap[name]->setVolume(volume);
	}
}

//clears all samples from this object
void Audio::clearSamples()
{
	sampleMap.clear();
}

//clears all music from this object
void Audio::clearMusic()
{
	for(musicIterator = musicMap.begin(); musicIterator != musicMap.end(); ++musicIterator)
	{
		delete musicIterator->second;
	}
	musicMap.clear();
}

//clears all sounds from this object
void Audio::clearAll()
{
	sampleMap.clear();
	for(musicIterator = musicMap.begin(); musicIterator != musicMap.end(); ++musicIterator)
	{
		delete musicIterator->second;
	}
	musicMap.clear();
}