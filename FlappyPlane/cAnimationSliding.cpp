#include "cAnimationSliding.h"

cAnimationSliding::cAnimationSliding()
{
    LoadSpriteSheet("Sprites/StickmanSlide.png");

    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(254, 298);

    mSprite->setScale(sf::Vector2f(.11f, .11f));
    mSprite->setOrigin(sf::Vector2f((mFrameSize.x / 2) * .11, (mFrameSize.y / 2) * .11));

    mSpriteRect = sf::IntRect(sf::Vector2i(0, 0), mFrameSize);
    mFrameDuration = 0.15f;
    mAnimationTime = 0.0f;
    mCurrentFrame = sf::Vector2u(0, 0);

    mSprite->setTextureRect(mSpriteRect);
}

cAnimationSliding::~cAnimationSliding()
{
}

void cAnimationSliding::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationSliding::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
