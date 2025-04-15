#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window, cPlayerInput& playerInput, cLevelPlatformsList& platformsList)
    : mPlayerInput(playerInput)
    , mPlayerCharacter(sf::Vector2f(250, 600), playerInput)
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
    , mPlatformsList(platformsList)
{

}

cGameManager::~cGameManager()
{
}

void cGameManager::GameTick()
{
    RefreshDeltaTime();
    mPlayerCharacter.Update(mDeltaSeconds);
    mPlayerCharacter.Draw(mGameWindow);

    mPlatformsList.DrawPlatforms(mGameWindow);
    //mPlatform1.Update(mPlayerCharacter);
    //mPlatform2.Update(mPlayerCharacter);

    //mPlatform1.Draw(mGameWindow);
    //mPlatform2.Draw(mGameWindow);
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}