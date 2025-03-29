#include "cAnimator.h"

cAnimator::cAnimator()
    : mFaceLeftScale(sf::Vector2f(-0.11f, 0.11f))
    , mFaceRightScale(sf::Vector2f(0.11f, 0.11f))
{
    mCurrentAnimation = &mIdleAnimation;
}

cAnimator::~cAnimator()
{
}

void cAnimator::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    mCurrentAnimation->Animate(PlayerPosition, DeltaSeconds);
}

void cAnimator::Draw(sf::RenderWindow& renderWindow)
{
    mCurrentAnimation->Draw(renderWindow);
}

void cAnimator::FaceLeft()
{
    mCurrentAnimation->SetScale(mFaceLeftScale);
    mIdleAnimation.SetScale(mFaceLeftScale);
}

void cAnimator::FaceRight()
{
    mCurrentAnimation->SetScale(mFaceRightScale);
    mIdleAnimation.SetScale(mFaceRightScale);
}

void cAnimator::BeginJump()
{
    mCurrentAnimation = &mJumpingAnimation;
}

void cAnimator::JumpPeak()
{
    mJumpingAnimation.mIsJumpPeakReached = true;
}

void cAnimator::EndFall()
{
    mJumpingAnimation.ResetAnimation();
    mJumpingAnimation.mIsJumpPeakReached = false;
    SetRunning(mIsRunning);
}

void cAnimator::SetRunning(bool isRunning)
{
    if (mIsSliding)
    {
        mCurrentAnimation = &mSlidingAnimation;
    } 
    else if (isRunning) 
    {
        mCurrentAnimation = &mRunningAnimation;
        mIsRunning = true;
    }
    else {
        mCurrentAnimation = &mIdleAnimation;
        mIsRunning = false;
    }
}

void cAnimator::SetSliding(bool isSliding)
{
    mIsSliding = isSliding;
}
