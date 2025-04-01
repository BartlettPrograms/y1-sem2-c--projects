#include "cAnimationRunning.h"

cAnimationRunning::cAnimationRunning()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(4, 1);
    mFrameSize = sf::Vector2i(345, 256);
    LoadSpriteSheet("Assets/Sprites/StickmanRun.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);
}

cAnimationRunning::~cAnimationRunning()
{
}

void cAnimationRunning::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Accumulate time
    mAnimationTime += DeltaSeconds;

    // Set sprite position
    mSprite->setPosition(PlayerPosition);

    // Check if it's time to switch frames
    if (mAnimationTime >= mFrameDuration)
    {
        mAnimationTime -= mFrameDuration;  // Reset timer
        mCurrentFrame.x = (mCurrentFrame.x + 1) % mTotalFrames.x;  // Cycle through frames

        mSpriteRect.position = (sf::Vector2i(mFrameSize.x * (1 + mCurrentFrame.x), 0));
        mSpriteRect.size = mFrameSize;

        // Update sprite rectangle
        mSprite->setTextureRect(mSpriteRect);
    }
}

void cAnimationRunning::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
