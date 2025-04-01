#include "cPlayButtonUI.h"

cPlayButtonUI::cPlayButtonUI(sf::Vector2f position, sf::Vector2f size, cMainMenu& mainMenu)
	: cButtonUI(position, size)
	, mMainMenu(mainMenu)
{

}

cPlayButtonUI::~cPlayButtonUI()
{
}

void cPlayButtonUI::OnButtonClick()
{
	mMainMenu.mIsActive = false;
}
