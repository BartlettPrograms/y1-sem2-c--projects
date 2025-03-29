#include "cGameManager.h"

cGameManager::cGameManager(sf::RenderWindow& window) 
    : mPlayerCharacter()
    , mGameWindow(window)
    , mDeltaSeconds(0.0f)
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
}

void cGameManager::RefreshDeltaTime()
{
    mDeltaTime = mClock.restart();
    mDeltaSeconds = mDeltaTime.asSeconds();
}