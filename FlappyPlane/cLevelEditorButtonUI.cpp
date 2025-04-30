#include "cLevelEditorButtonUI.h"

cLevelEditorButtonUI::cLevelEditorButtonUI(sf::Vector2f position, sf::Vector2f size)
	: cButtonUI(position, size)
	, mText(mBodyFont, "LEVEL EDITOR", 20U)
{
	// get font
	if (!mBodyFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}
	// Do the crap from cMainMenu.cpp
	mText.setString("LEVEL EDITOR");
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

cLevelEditorButtonUI::~cLevelEditorButtonUI()
{

}

void cLevelEditorButtonUI::OnButtonClick()
{
	cSingleton::GetInstance().AppManager.SetMainMenuActive(false);
	cSingleton::GetInstance().AppManager.SetLevelEditorRunning(true);
	cSingleton::GetInstance().AppManager.SetGameRunning(true);
}

void cLevelEditorButtonUI::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
