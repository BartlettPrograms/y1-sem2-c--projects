#include "cAnimationIdle.h"

cAnimationIdle::cAnimationIdle()
{
    // Animation setup
    mTotalFrames = sf::Vector2u(1, 1);
    mFrameSize = sf::Vector2i(300, 324);
    LoadSpriteSheet("Sprites/StickmanIdle.png");

    mCurrentFrame = sf::Vector2u(0, 0);
}

cAnimationIdle::~cAnimationIdle()
{
}

void cAnimationIdle::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    // Set sprite position
    mSprite->setPosition(PlayerPosition);
}

void cAnimationIdle::Draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*mSprite);
}
