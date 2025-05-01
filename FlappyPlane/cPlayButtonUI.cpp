#include "cPlayButtonUI.h"

cPlayButtonUI::cPlayButtonUI(sf::Vector2f position, sf::Vector2f size)
	: cButtonUI(position, size)
	, mText(mBodyFont, "PLAY", 20U)
{
	// get font
	if (!mBodyFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}
	// Do the crap from cMainMenu.cpp
	mText.setString("PLAY");
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

cPlayButtonUI::~cPlayButtonUI()
{

}

void cPlayButtonUI::OnButtonClick()
{
	cApplicationManager::GetInstance()->LoadLevel();
	cApplicationManager::GetInstance()->SetMainMenuActive(false);
	cApplicationManager::GetInstance()->SetGameRunning(true);
	/*cSingleton::GetInstance().AppManager.LoadLevel();
	cSingleton::GetInstance().AppManager.SetMainMenuActive(false);
	cSingleton::GetInstance().AppManager.SetGameRunning(true);*/
}

void cPlayButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
