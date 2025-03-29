#pragma once
#include "cAnimation.h"

class cAnimationSliding : public cAnimation
{
public:
	cAnimationSliding();
	~cAnimationSliding();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};