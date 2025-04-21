#pragma once
#include "cPlatform.h"

class cPlatformSlope : public cPlatform
{
private:
	sf::ConvexShape mBody;
public:
	cPlatformSlope() {}
	~cPlatformSlope() {}

	void CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection) override;
};