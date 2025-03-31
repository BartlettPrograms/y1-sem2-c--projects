#pragma once
#include "cGameObject.h"
#include "cBoxCollider.h"
#include "cPlayerCharacter.h"

class cPlatformRect : public cGameObject, cBoxCollider
{
public:
	cPlatformRect(sf::FloatRect bounds);
	~cPlatformRect();

	void Draw(sf::RenderWindow& window) override;
	cBoxCollider& GetCollider() { return *this; };
private:
	sf::RectangleShape mBody;
};