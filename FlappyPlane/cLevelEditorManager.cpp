#include "cLevelEditorManager.h"

cLevelEditorManager::cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& mPlatformsList)
	: mMainWindow(mainWindow)
	, mDrawTool(mainWindow, playerInput, mPlatformsList)
	, mToolbar(mainWindow, mDrawTool)
{

}

cLevelEditorManager::~cLevelEditorManager()
{
}

void cLevelEditorManager::Update()
{
	// Get mouse position
	sf::Vector2i mousePos = sf::Mouse::getPosition(mMainWindow);
	// Convert to float for calculations
	sf::Vector2f mousePosF = static_cast<sf::Vector2f>(mousePos);

	// Calculate grid-aligned tool position
	sf::Vector2f ToolPosition;
	ToolPosition.x = std::floor(mousePosF.x / mGridSize) * mGridSize;
	ToolPosition.y = std::floor(mousePosF.y / mGridSize) * mGridSize;

	// Update cursor with the tool position
	mDrawTool.UpdateCursor(mMainWindow, ToolPosition);
	mToolbar.Update();
}

void cLevelEditorManager::Draw()
{
	mDrawTool.DrawCursorToScreen(mMainWindow);
	mToolbar.Draw();
}
