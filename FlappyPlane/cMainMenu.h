#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayButtonUI.h"
#include <iostream>

class cPlayButtonUI;

class cMainMenu
{
public:
	cMainMenu(sf::RenderWindow& renderWindow);
	~cMainMenu();
	void Update();
	bool mIsActive = true;
private:
	// Render Window
	sf::RenderWindow& mRenderWindow;

	// Title
	sf::Font mTitleFont;
	sf::Font mBodyFont;
	sf::Text mText;
	sf::Vector2f mTitlePosition = sf::Vector2f(1366 / 2, 768 / 2);

	// Buttons
	sf::Vector2f ButtonSize = sf::Vector2f(400, 150);
	sf::Vector2f mPlayButtonPosition = sf::Vector2f(1366 / 2, 500);
	cPlayButtonUI* mPlayButtonUI;
};