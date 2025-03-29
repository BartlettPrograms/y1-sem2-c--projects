#include "cPlatformRect.h"

cPlatformRect::cPlatformRect(sf::Vector2f size, sf::Vector2f position)
	: cBoxCollider(mBody)
{
	mBody.setPosition(position);
	mBody.setSize(size);
	mBody.setOrigin(size / 2.0f);
}

cPlatformRect::~cPlatformRect()
{
}

void cPlatformRect::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}
