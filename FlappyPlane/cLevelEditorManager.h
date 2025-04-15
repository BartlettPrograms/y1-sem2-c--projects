#pragma once
#include "cEditorDrawTool.h"
#include "cEditorToolbarUI.h"
#include "cLevelPlatformsList.h"
#include "cPlayerInput.h"

class cLevelEditorManager
{
public:
	cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList);
	~cLevelEditorManager();
	
	void Update();
	void Draw();
private:
	cEditorDrawTool mDrawTool;
	cEditorToolbarUI mToolbar;
	sf::RenderWindow& mMainWindow;

	// Current Game Level data
	cLevelPlatformsList& mPlatformsList; // Platforms
};