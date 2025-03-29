#pragma once
#include "cAnimation.h"

class cAnimationIdle : public cAnimation
{
public:
	cAnimationIdle();
	~cAnimationIdle();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};