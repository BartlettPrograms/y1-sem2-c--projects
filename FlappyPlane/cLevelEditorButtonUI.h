#pragma once
#include "cButtonUI.h"
#include "cApplicationManager.h"

class cMainMenu;

class cLevelEditorButtonUI : public cButtonUI
{
public:
	cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size);
	~cLevelEditorButtonUI();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	sf::Font mBodyFont;
	sf::Text mText;
};