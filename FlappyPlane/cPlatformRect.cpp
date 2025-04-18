#include "cPlatformRect.h"

cPlatformRect::cPlatformRect(sf::FloatRect bounds)
	: mBoxCollider(bounds)
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

void cPlatformRect::Update(cCharacter& character, sf::Vector2f& collisionDirection)
{
	if(mBoxCollider.CheckCollision(character.GetCollider(), collisionDirection, 1.0f))
		character.OnCollision(collisionDirection);
}

void cPlatformRect::EditorInitPosition()
{
	float newPosX = mPosition.x + mBody.getLocalBounds().size.x / 2;
	float newPosY = mPosition.y + mBody.getLocalBounds().size.y / 2;

	mPosition = sf::Vector2f(newPosX, newPosY);
}
