#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window)
    : mPlayerCharacter()
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatform1(sf::FloatRect(sf::Vector2f(250, 700), sf::Vector2f(300, 100)))
    , mPlatform2(sf::FloatRect(sf::Vector2f(800, 700), sf::Vector2f(300, 100)))
{
}

cGameManager::~cGameManager()
{
}

void cGameManager::GameTick()
{
    RefreshDeltaTime();
    mPlayerCharacter.Update(mDeltaSeconds);

    mPlatform1.GetCollider().CheckCollision(mPlayerCharacter.GetCollider(), 1.0f);
    mPlatform2.GetCollider().CheckCollision(mPlayerCharacter.GetCollider(), 1.0f);

    mPlatform1.Draw(mGameWindow);
    mPlatform2.Draw(mGameWindow);
    mPlayerCharacter.Draw(mGameWindow);
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}