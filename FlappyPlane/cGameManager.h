#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerCharacter.h"
#include "cPlatformRect.h"
#include <iostream>

class cGameManager
{
public:
	cGameManager(sf::RenderWindow& window);
	~cGameManager();
	void GameTick();
	
private:
	// Clock & DeltaTime
	sf::Clock mClock;
	sf::Time mDeltaTime;
	float mDeltaSeconds;
	void RefreshDeltaTime();
	// Render Window
	sf::RenderWindow& mGameWindow;
	// Player Character
	cPlayerCharacter mPlayerCharacter;
	// Platform
	cPlatformRect mPlatform1;
	cPlatformRect mPlatform2;
};