#include "cMainMenu.h"

cMainMenu::cMainMenu(sf::RenderWindow& renderWindow)
	: mText(mTitleFont, "NINJA", 30U)
	, mRenderWindow(renderWindow)
	// Play Button
	, mPlayButtonUI ( 
		mPlayButtonPosition
		, mButtonSize
	)
	// Level Edit Button
	, mLevelEditorButtonUI (
		mLevelEditorButtonPosition
		, mButtonSize
	)
{
	// get title font
	if (!mTitleFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}
	// set title text
	mText.setFont(mTitleFont);
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(42);
	mText.setPosition(mTitlePosition);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

cMainMenu::~cMainMenu()
{

}

void cMainMenu::Update()
{
	mRenderWindow.draw(mText);
	mPlayButtonUI.Update(mRenderWindow);
	mPlayButtonUI.Draw(mRenderWindow);
	mLevelEditorButtonUI.Update(mRenderWindow);
	mLevelEditorButtonUI.Draw(mRenderWindow);
}

