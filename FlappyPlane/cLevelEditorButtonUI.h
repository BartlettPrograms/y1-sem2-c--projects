#pragma once
#include "cButtonUI.h"
#include "cMainMenu.h"

class cMainMenu;

class cLevelEditorButtonUI : public cButtonUI
{
public:
	cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size, cMainMenu& mainMenu);
	~cLevelEditorButtonUI();
	void OnButtonClick() override;
private:
	cMainMenu& mMainMenu;
};