#pragma once
#include "cEditorDrawTool.h"
#include "cEditorToolbarUI.h"
#include "cPlayerInput.h"
#include "cFileInterface.h"

class cLevelEditorManager
{
public:
	cLevelEditorManager(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList, cFileInterface& fileInterface);
	~cLevelEditorManager();
	
	void Update();
	void Draw();
private:
	cEditorDrawTool mDrawTool;
	cEditorToolbarUI mToolbar;
	sf::RenderWindow& mMainWindow;

	// DrawGrid
	float mGridSize = 24;
};