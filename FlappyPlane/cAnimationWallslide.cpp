#include "cAnimationWallslide.h"

cAnimationWallslide::cAnimationWallslide()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(127, 248);
    LoadSpriteSheet("Assets/Sprites/StickmanWallslide.png");
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);
    mSprite->setOrigin(sf::Vector2f(10, mFrameSize.y));
}

cAnimationWallslide::~cAnimationWallslide()
{
}

void cAnimationWallslide::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationWallslide::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
