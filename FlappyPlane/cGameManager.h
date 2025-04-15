#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerCharacter.h"
#include "cLevelPlatformsList.h"
#include <iostream>

class cGameManager
{
public:
	cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList);
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
	// Platforms
	cLevelPlatformsList& mPlatformsList;
};