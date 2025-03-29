#pragma once
#include "cAnimation.h"

class cAnimationRunning : public cAnimation
{
public:
	cAnimationRunning();
	~cAnimationRunning();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};