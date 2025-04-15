#pragma once
#include "cEditorDrawTool.h"
#include"cEditorToolbarUI.h"

class cLevelEditorManager
{
public:
	cLevelEditorManager(sf::RenderWindow& mainWindow);
	~cLevelEditorManager();
	
	void Update();
private:
	cEditorDrawTool mDrawTool;
	cEditorToolbarUI mToolbar;
	sf::RenderWindow& mMainWindow;
};