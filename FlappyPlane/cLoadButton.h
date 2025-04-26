#pragma once
#include "cButtonUI.h"
#include "cFileInterface.h"
#include "cLevelPlatformsList.h"

class cLoadButton : public cButtonUI
{
public:
	cLoadButton(sf::Vector2f position, sf::Vector2f size, cFileInterface& _userFileInterface, cLevelPlatformsList& platformList);
	~cLoadButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;

private:
	cFileInterface& mFileInterface;
	cLevelPlatformsList& mPlatformList;

	sf::Texture mLoadIconTexture; // Load Texture
	sf::Sprite* mUIIcon; // create sprite from above
};