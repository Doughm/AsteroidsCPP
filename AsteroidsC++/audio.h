//plays and manages audio files

#ifndef AUDIO
#define AUDIO

#include<string>
#include <SFML/Audio.hpp>
#include <map>

class Audio
{
public:
	Audio();
	~Audio();
	void soundToggle();
	void setSoundOn(bool);
	bool getSoundOn();
	void addSample(std::string const&, std::string const&);
	void samplePlay(std::string const&);
	void samplePause(std::string const&);
	void sampleLoop(std::string const&, bool);
	void sampleStop(std::string const&);
	void sampleVolume(std::string const&, float);
	void addMusic(std::string const&, std::string const&);
	void musicPlay(std::string const&);
	void musicPause(std::string const&);
	void musicLoop(std::string const&, bool);
	void musicStop(std::string const&);
	void musicVolume(std::string const&, float);
	void clearSamples();
	void clearMusic();
	void clearAll();
private:
	std::map<std::string, sf::Sound> sampleMap;
	std::map<std::string, sf::Music*> musicMap;
	std::map<std::string, sf::Music*>::iterator musicIterator;
	sf::SoundBuffer *soundBuffer;
	bool soundOn;
};

#endif