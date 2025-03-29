#pragma once
#include "cAnimation.h"

class cAnimationJumping : public cAnimation
{
public:
	cAnimationJumping();
	~cAnimationJumping();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds) override;
	void Draw(sf::RenderWindow& renderWindow) override;
	void ResetAnimation();
	bool mIsJumpPeakReached = false;
private:
};