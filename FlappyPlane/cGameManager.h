#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerCharacter.h"
#include "cPlatformRect.h"
#include <iostream>

class cGameManager
{
public:
	cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput);
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
	cPlayerInput& mPlayerInput;
	cPlayerCharacter mPlayerCharacter;
	// Platform
	cPlatformRect mPlatform1;
	cPlatformRect mPlatform2;
};