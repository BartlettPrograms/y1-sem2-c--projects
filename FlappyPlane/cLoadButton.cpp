#include "cLoadButton.h"

cLoadButton::cLoadButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList)
	: cButtonUI(position, size)
	, mFileInterface(_userFileInterface)
	, mPlatformList(platformList)
{
	// Load image
	mLoadIconTexture.loadFromFile("Assets/Sprites/UI/Toolbar/LoadIcon.png");
	mUIIcon = new sf::Sprite(mLoadIconTexture);
	// Set position
	mUIIcon->setOrigin(sf::Vector2f(mUIIcon->getLocalBounds().size.x / 2, mUIIcon->getLocalBounds().size.y / 2));
	mUIIcon->setPosition(sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2)));
}

cLoadButton::~cLoadButton()
{
	delete mUIIcon;
}

void cLoadButton::OnButtonClick()
{
	// Load to the platform list
	
}

void cLoadButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Update(window);
	// Draw Button to screen
	cButtonUI::Draw(window);
	window.draw(*mUIIcon);
}