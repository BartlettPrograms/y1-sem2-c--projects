#include "cAnimationSliding.h"

cAnimationSliding::cAnimationSliding()
{
    mTexture = sf::Texture("Sprites/StickmanSlide.png");
    mTexture.setSmooth(true);
    mSprite = new sf::Sprite(mTexture);

    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(254, 298);
    mSprite->setOrigin(sf::Vector2f((mFrameSize.x / 2) / 10, (mFrameSize.y / 2) / 10));

    mSprite->setScale(sf::Vector2f(.11f, .11f));

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
