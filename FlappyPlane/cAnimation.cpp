#include "cAnimation.h"
#include <iostream>

void cAnimation::LoadSpriteSheet(std::string filePath)
{
	mFrameDuration = 0.15f;
	mAnimationTime = 0.0f;

	mTexture = sf::Texture(filePath);
	mTexture.setSmooth(true);
	mSprite = new sf::Sprite(mTexture);

	mSprite->setScale(sf::Vector2f(.11f, .11f));
	mSprite->setOrigin(sf::Vector2f((mFrameSize.x / 2) * .11, (mFrameSize.y) * .11));

	mSpriteRect = sf::IntRect(sf::Vector2i(0, 0), mFrameSize);
	mSprite->setTextureRect(mSpriteRect);
}

void cAnimation::SetScale(sf::Vector2f scale)
{
	mScale = scale;
	mSprite->setScale(mScale);
}
