#include "cPlatformRect.h"

cPlatformRect::cPlatformRect(sf::FloatRect bounds)
	: cBoxCollider(bounds)
{
	mBody.setPosition(bounds.position);
	mBody.setSize(bounds.size);
	//mBody.setOrigin(size / 2.0f);
}

cPlatformRect::~cPlatformRect()
{

}

void cPlatformRect::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}
