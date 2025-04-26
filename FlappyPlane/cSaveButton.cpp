#include "cSaveButton.h"

cSaveButton::cSaveButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList)
	: cButtonUI(position, size)
	, mFileInterface(_userFileInterface)
	, mPlatformList(platformList)
{
	// load image
	mSaveIconTexture.loadFromFile("Assets/Sprites/UI/Toolbar/SaveIcon.png");
	mUIIcon = new sf::Sprite(mSaveIconTexture);
	// set position
	mUIIcon->setOrigin(sf::Vector2f(mUIIcon->getLocalBounds().size.x/2, mUIIcon->getLocalBounds().size.y / 2));
	mUIIcon->setPosition(sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2)));
}

cSaveButton::~cSaveButton()
{
	delete mUIIcon;
}

void cSaveButton::OnButtonClick()
{
	// Save the platform list
	mFileInterface.SaveLevel();
}

void cSaveButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Update(window);
	// Draw Button to screen
	cButtonUI::Draw(window);
	window.draw(*mUIIcon);
}