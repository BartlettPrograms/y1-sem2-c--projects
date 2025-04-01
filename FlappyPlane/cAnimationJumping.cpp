#include "cAnimationJumping.h"

cAnimationJumping::cAnimationJumping()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(3, 1);
    mFrameSize = sf::Vector2i(300, 313);
    LoadSpriteSheet("Sprites/StickmanJumping.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);
}

cAnimationJumping::~cAnimationJumping()
{
}

void cAnimationJumping::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    mSprite->setPosition(PlayerPosition);

    // only modify sprite when applicable
    if (mIsJumpPeakReached && mCurrentFrame.x < mTotalFrames.x -1)
    {
        mAnimationTime += DeltaSeconds;

        // Check if it's time to switch frames
        if (mAnimationTime >= mFrameDuration)
        {
            mAnimationTime -= mFrameDuration;   // Reset timer
            mCurrentFrame.x++;                  // Cycle through frames

            mSpriteRect.position = (sf::Vector2i(mFrameSize.x * mCurrentFrame.x, 0));
            mSpriteRect.size = mFrameSize;

            // Update sprite rectangle
            mSprite->setTextureRect(mSpriteRect);
        }
    }
}

void cAnimationJumping::Draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(*mSprite);
}

void cAnimationJumping::ResetAnimation()
{
    mCurrentFrame = sf::Vector2u(0, 0);
    mSpriteRect.position = (sf::Vector2i(0, 0));
    mSpriteRect.size = mFrameSize;
    mAnimationTime = 0.0f;
    mIsJumpPeakReached = false;
    mSprite->setTextureRect(mSpriteRect);
}
