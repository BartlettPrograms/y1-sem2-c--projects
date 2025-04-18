#pragma once
#include <SFML/Graphics.hpp>
#include "cAnimationRunning.h"
#include "cAnimationJumping.h"
#include "cAnimationIdle.h"
#include "cAnimationSliding.h"
#include "cAnimationWallslide.h"

class cAnimator : cDrawable
{
public:
	cAnimator();
	~cAnimator();
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
	// Directions
	void FaceLeft();
	void FaceRight();
	void BeginJump();
	void JumpPeak();
	void EndFall();
	void SetRunning(bool isRunning);
	void SetSliding(bool isSliding);
	void SetWallsliding(bool isWallsliding);
private:
	// Face left or right
	const sf::Vector2f mFaceLeftScale;
	const sf::Vector2f mFaceRightScale;
	// Animation variables
	bool mIsRunning = false;
	bool mIsSliding = false;
	// Animations
	cAnimation* mCurrentAnimation;
	cAnimationRunning mRunningAnimation;
	cAnimationJumping mJumpingAnimation;
	cAnimationIdle mIdleAnimation;
	cAnimationSliding mSlidingAnimation;
	cAnimationWallslide mWallslideAnimation;
};