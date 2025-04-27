#include "cMainMenu.h"

cMainMenu::cMainMenu(sf::RenderWindow& renderWindow)
	: mText(mTitleFont, "NINJA", 30U)
	, mRenderWindow(renderWindow)
	, mPlayButtonUI ( 
		mPlayButtonPosition
		, mButtonSize
		, *this)
	, mLevelEditorButtonUI (
		mLevelEditorButtonPosition
		, mButtonSize
		, *this
	)
{
	// get fonts
	if (!mTitleFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load title font!" << std::endl;
	}
	if (!mBodyFont.openFromFile("Assets/Fonts/TypeLightSans-KV84p.otf"))
	{
		std::cerr << "Failed to load body font!" << std::endl;
	}

	// set text
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
	if (mIsActive)
	{
		mRenderWindow.draw(mText);
		mPlayButtonUI.Update(mRenderWindow);
		mPlayButtonUI.Draw(mRenderWindow);
	}
}

void cMainMenu::StartGame()
{
	cGameManager GameManager = new cGameManager(window, PlayerInput, LevelPlatformsList);
}

void cMainMenu::StartLevelEditor()
{

}
