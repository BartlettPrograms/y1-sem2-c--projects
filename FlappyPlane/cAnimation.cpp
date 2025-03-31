#include "cAnimation.h"
#include <iostream>

void cAnimation::LoadSpriteSheet(std::string filePath)
{
	mTexture = sf::Texture(filePath);
	mTexture.setSmooth(true);
	mSprite = new sf::Sprite(mTexture);
}

void cAnimation::SetScale(sf::Vector2f scale)
{
	mScale = scale;
	mSprite->setScale(mScale);
}
