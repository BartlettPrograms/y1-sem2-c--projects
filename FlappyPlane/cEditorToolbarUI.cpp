#include "cEditorToolbarUI.h"


cEditorToolbarUI::cEditorToolbarUI(sf::RenderWindow* window, cEditorDrawTool& _DrawTool, sf::RenderTexture* _canvasTexture)
	: RenderWindow(window), UserDrawTool(_DrawTool)
	, ButtonRectangleTool(sf::Vector2f(15.0f, 15.0f), sf::Vector2f(25.0f, 25.0f), UserDrawTool)
{
	// load image
	m_BackgroundTexture.loadFromFile("Sprites/UI/Toolbar/ToolbarBackground.png");
	m_UIBackground = new sf::Sprite(m_BackgroundTexture);
}

void cEditorToolbarUI::Draw(sf::RenderWindow& window) {
	window.draw(*m_UIBackground);
	ButtonRectangleTool.Update(window);
	ButtonRectangleTool.Draw(window);
	//ButtonCircleTool.Update(window);
	//ButtonCircleTool.Draw(window);
	//ButtonLineTool.Update(window);
	//ButtonLineTool.Draw(window);
	//ButtonPolygonTool.Update(window);
	//ButtonPolygonTool.Draw(window);
	//m_ButtonStampTool.Update(window);
	//m_ButtonStampTool.Draw(window);
	//m_SaveButton.Update(window);
	//m_SaveButton.Draw(window);
	//m_LoadButton.Update(window);
	//m_LoadButton.Draw(window);
	//m_ColorPickerButton.Update(window);
	//m_ColorPickerButton.Draw(window);
	// Update line thickness visual
}
