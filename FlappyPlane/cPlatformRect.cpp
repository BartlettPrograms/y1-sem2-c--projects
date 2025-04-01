#include "cPlatformRect.h"

cPlatformRect::cPlatformRect(sf::FloatRect bounds)
	: cBoxCollider(bounds)
{
	mBody.setPosition(bounds.position);
	mBody.setSize(bounds.size);
	mBody.setOrigin(bounds.size / 2.0f);
	mBody.setFillColor(sf::Color(77, 77, 77));
}

cPlatformRect::~cPlatformRect()
{

}

void cPlatformRect::Draw(sf::RenderWindow& window)
{
	window.draw(mBody);
}

void cPlatformRect::Update(cCharacter& character)
{
	if (CheckCollision(character, 1.0f))
	{
		character.SetGrounded(true);
	}
}
