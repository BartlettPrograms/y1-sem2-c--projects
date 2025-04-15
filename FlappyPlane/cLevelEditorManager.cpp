#include "cLevelEditorManager.h"

cLevelEditorManager::cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput)
	: mMainWindow(mainWindow)
	, mDrawTool(mainWindow, playerInput)
	, mToolbar(mainWindow, mDrawTool)
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
