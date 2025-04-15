#include "cEditorToolbarUI.h"


cEditorToolbarUI::cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool)
	: mMainWindow(window), UserDrawTool(_DrawTool)
	, ButtonRectangleTool(sf::Vector2f(15.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), UserDrawTool)
	, mToolbarWindow(sf::VideoMode({ 256, 256 }), "Editor Toolbar")
{
	mToolbarWindow.setPosition(mMainWindow.getPosition() + sf::Vector2i(mMainWindow.getSize().x + 2, 0));
	// load image
	m_BackgroundTexture.loadFromFile("Assets/Sprites/UI/Toolbar/ToolbarBackground.png");
	m_UIBackground = new sf::Sprite(m_BackgroundTexture);
}

void cEditorToolbarUI::Update()
{
	ButtonRectangleTool.Update(mToolbarWindow);
}

void cEditorToolbarUI::Draw() {
	mToolbarWindow.draw(*m_UIBackground);
	ButtonRectangleTool.Draw(mToolbarWindow);
}
