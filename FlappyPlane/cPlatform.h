#pragma once
#include "cGameObject.h"
#include "cCharacter.h"

class cPlatform : public cGameObject
{
private:

public:
	cPlatform() {}
	~cPlatform() {}

	virtual void CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection);
};