#pragma once
#include "cButtonUI.h"
#include "cMainMenu.h"

class cMainMenu;

class cPlayButtonUI : public cButtonUI
{
public:
	cPlayButtonUI(sf::Vector2f position, sf::Vector2f size, cMainMenu& mainMenu);
	~cPlayButtonUI();
	void OnButtonClick() override;
private:
	cMainMenu& mMainMenu;
};