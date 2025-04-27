#include "cLevelEditorButtonUI.h"

cLevelEditorButtonUI::cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size, cMainMenu& mainMenu)
	: cButtonUI(position, size)
	, mMainMenu(mainMenu)
{

}

cLevelEditorButtonUI::~cLevelEditorButtonUI()
{
}

void cLevelEditorButtonUI::OnButtonClick()
{

	mMainMenu.mIsActive = false;
}
