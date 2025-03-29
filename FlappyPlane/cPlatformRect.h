#pragma once
#include "cGameObject.h"
#include "cBoxCollider.h"
#include "cPlayerCharacter.h"

class cPlatformRect : public cGameObject, cBoxCollider
{
public:
	cPlatformRect(sf::Vector2f size, sf::Vector2f position);
	~cPlatformRect();

	void Draw(sf::RenderWindow& window) override;
	cBoxCollider GetCollider() { return cBoxCollider(mBody); };
private:
	sf::RectangleShape mBody;
};