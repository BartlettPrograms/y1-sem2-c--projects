#include "cLevelEditorManager.h"

cLevelEditorManager::cLevelEditorManager(sf::RenderWindow& mainWindow)
	: mMainWindow(mainWindow)
	, mDrawTool(mainWindow)
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
}
