#include "cMainMenu.h"

cMainMenu::cMainMenu(sf::RenderWindow& renderWindow)
	: mText(mTitleFont, "NINJA", 30U)
	, mRenderWindow(renderWindow)
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

	mPlayButtonUI = new cPlayButtonUI(
		mPlayButtonPosition,
		ButtonSize,
		*this
	);
}

cMainMenu::~cMainMenu()
{
	delete mPlayButtonUI;
}

void cMainMenu::Update()
{
	if (mIsActive)
	{
		mRenderWindow.draw(mText);
		mPlayButtonUI->Update(mRenderWindow);
		mPlayButtonUI->Draw(mRenderWindow);
	}
}
