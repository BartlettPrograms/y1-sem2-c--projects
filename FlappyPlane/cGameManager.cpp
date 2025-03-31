#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window)
    : mPlayerCharacter()
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatform1(sf::FloatRect(sf::Vector2f(300, -300), sf::Vector2f(700, 600)))
    , mPlatform2(sf::FloatRect(sf::Vector2f(150, 300), sf::Vector2f(400, 600)))
{
}

cGameManager::~cGameManager()
{
}

void cGameManager::GameTick()
{
    RefreshDeltaTime();
    mPlayerCharacter.Update(mDeltaSeconds);

    mPlatform1.GetCollider().CheckCollision(mPlayerCharacter.GetCollider(), 0.0f);
    //mPlatform2.GetCollider().CheckCollision(mPlayerCharacter.GetCollider(), 1.0f);

    mPlatform1.Draw(mGameWindow);
    //mPlatform2.Draw(mGameWindow);
    mPlayerCharacter.Draw(mGameWindow);
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}