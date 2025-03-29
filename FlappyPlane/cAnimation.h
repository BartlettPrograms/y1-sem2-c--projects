#pragma once
#include "cDrawable.h"

class cAnimation : public cDrawable
{
public:
	virtual void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) = 0;
	void SetScale(sf::Vector2f scale);
protected:
	// Time Variables
	float mAnimationTime;
	float mFrameDuration;
	// Image Variables
	sf::Vector2u mCurrentFrame;
	sf::Vector2u mTotalFrames;
	sf::Vector2i mFrameSize;
	sf::Texture mTexture;
	sf::Sprite* mSprite;
	sf::IntRect mSpriteRect;
	// Variables to edit outside of class
	sf::Vector2f mScale;
};