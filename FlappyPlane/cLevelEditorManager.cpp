#include "cLevelEditorManager.h"

cLevelEditorManager::cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& mPlatformsList)
	: mMainWindow(mainWindow)
	, mDrawTool(mainWindow, playerInput)
	, mToolbar(mainWindow, mDrawTool)
	, mPlatformsList(mPlatformsList)
{

}

cLevelEditorManager::~cLevelEditorManager()
{
}

void cLevelEditorManager::Update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(mMainWindow);
	mDrawTool.UpdateCursor(mMainWindow, sf::Vector2f(mousePos));
	mToolbar.Update();
}

void cLevelEditorManager::Draw()
{
	mDrawTool.DrawCursorToScreen(mMainWindow);
	mToolbar.Draw();
}
