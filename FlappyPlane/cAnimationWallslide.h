#pragma once
#include "cAnimation.h"

class cAnimationWallslide : public cAnimation
{
public:
	cAnimationWallslide();
	~cAnimationWallslide();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
};