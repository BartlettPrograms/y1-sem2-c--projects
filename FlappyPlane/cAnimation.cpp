#include "cAnimation.h"
#include <iostream>

void cAnimation::SetScale(sf::Vector2f scale)
{
	mScale = scale;
	mSprite->setScale(mScale);
}
