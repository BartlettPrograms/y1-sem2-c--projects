#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayButtonUI.h"
#include "cLevelEditorButtonUI.h"
#include "cApplicationManager.h"
#include <iostream>


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
	sf::Text mText;
	sf::Vector2f mTitlePosition = sf::Vector2f(1366 / 2, (768 / 2) - 300);

	// Buttons
	sf::Vector2f mButtonSize = sf::Vector2f(300, 100);
	sf::Vector2f mPlayButtonPosition = sf::Vector2f(1366 / 2, 300);
	sf::Vector2f mLevelEditorButtonPosition = sf::Vector2f(1366 / 2, 500);
	cPlayButtonUI mPlayButtonUI;
	cLevelEditorButtonUI mLevelEditorButtonUI;
};