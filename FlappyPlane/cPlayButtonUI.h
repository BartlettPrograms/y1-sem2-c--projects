#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"

class cMainMenu;

class cPlayButtonUI : public cButtonUI
{
public:
	cPlayButtonUI(sf::Vector2f position, sf::Vector2f size);
	~cPlayButtonUI();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	sf::Font mBodyFont;
	sf::Text mText;
};