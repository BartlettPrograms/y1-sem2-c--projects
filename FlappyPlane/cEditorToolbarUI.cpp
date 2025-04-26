#include "cEditorToolbarUI.h"


cEditorToolbarUI::cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool, cLevelPlatformsList& platformsList, cFileInterface& fileInterface)
	: mMainWindow(window), UserDrawTool(_DrawTool)
	, mToolbarWindow(sf::VideoMode({ 256, 256 }), "Editor Toolbar")
	, mButtonRectangleTool(sf::Vector2f(15.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), _DrawTool)
	, mSaveButton(sf::Vector2f(15.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
	, mLoadButton(sf::Vector2f(45.0f, 226.0f), sf::Vector2f(25.0f, 25.0f), fileInterface, platformsList)
{
	mToolbarWindow.setPosition(mMainWindow.getPosition() + sf::Vector2i(mMainWindow.getSize().x + 2, 0));
	// load image
	mBackgroundTexture.loadFromFile("Assets/Sprites/UI/Toolbar/ToolbarBackground.png");
	mUIBackground = new sf::Sprite(mBackgroundTexture);
}

void cEditorToolbarUI::Update()
{
	mButtonRectangleTool.Update(mToolbarWindow);
}

void cEditorToolbarUI::Draw() {
	mToolbarWindow.draw(*mUIBackground);
	mButtonRectangleTool.Draw(mToolbarWindow);
	mSaveButton.Draw(mToolbarWindow);
	mLoadButton.Draw(mToolbarWindow);
	mToolbarWindow.display();
}
