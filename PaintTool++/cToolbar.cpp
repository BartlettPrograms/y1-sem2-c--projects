/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c)
 2025 Media Design School
 File Name : PaintTool++.exe
 Description : Budget paint tool
 Author : Matthew Bartlett
 Mail : matthew.bartlett@mds.ac.nz
 **************************************************************************/


#include "cToolbar.h"


ToolbarUI::ToolbarUI(sf::RenderWindow* window, DrawTool& _DrawTool, sf::RenderTexture* _canvasTexture)
	: RenderWindow(window), UserDrawTool(_DrawTool), m_canvasTexture(*_canvasTexture),
	ButtonRectangleTool(15.0f, 15.0f, 25.0f, 25.0f, UserDrawTool),
	ButtonCircleTool(55.0f, 15.0f, 25.0f, 25.0f, UserDrawTool),
	ButtonLineTool(95.0f, 15.0f, 25.0f, 25.0f, UserDrawTool),
	ButtonPolygonTool(135, 15, 25, 25, UserDrawTool),
	m_ButtonStampTool(175, 15, 25, 25, UserDrawTool, m_FileInterface),
	m_SaveButton(15.0f, 155.0f, 50, 30, m_FileInterface, m_canvasTexture),
	m_LoadButton(191.0f, 155.0f, 50, 30, m_FileInterface, m_canvasTexture),
	m_LineThicknessNegativeButton(15, 80, 35, 35, UserDrawTool),
	m_LineThicknessPositiveButton(206, 80, 35, 35, UserDrawTool),
	m_ColorPickerButton(215, 15, 25, 25, m_FileInterface, UserDrawTool)
{
	// load image
	m_BackgroundImage.loadFromFile("Sprites/ToolbarBackground.png");
	m_BackgroundTexture.loadFromImage(m_BackgroundImage);
	m_UIBackground = new sf::Sprite(m_BackgroundTexture);

	// Line thickness visual shape
	m_LineThicknessVisual.setFillColor(sf::Color::White);
	m_LineThicknessVisual.setPosition(sf::Vector2f(128, 97));
	m_LineThicknessVisual.setSize(sf::Vector2f(2,40));
}

void ToolbarUI::Draw(sf::RenderWindow& window) {
	window.draw(*m_UIBackground);
	ButtonRectangleTool.Update(window);
	ButtonRectangleTool.Draw(window);
	ButtonCircleTool.Update(window);
	ButtonCircleTool.Draw(window);
	ButtonLineTool.Update(window);
	ButtonLineTool.Draw(window);
	ButtonPolygonTool.Update(window);
	ButtonPolygonTool.Draw(window);
	m_ButtonStampTool.Update(window);
	m_ButtonStampTool.Draw(window);
	m_SaveButton.Update(window);
	m_SaveButton.Draw(window);
	m_LoadButton.Update(window);
	m_LoadButton.Draw(window);
	m_LineThicknessNegativeButton.Update(window);
	m_LineThicknessNegativeButton.Draw(window);
	m_LineThicknessPositiveButton.Update(window);
	m_LineThicknessPositiveButton.Draw(window);
	m_ColorPickerButton.Update(window);
	m_ColorPickerButton.Draw(window);
	// Update line thickness visual
	UpdateLineThicknessUIOrigin();
	window.draw(m_LineThicknessVisual);
}

void ToolbarUI::UpdateLineThicknessUIOrigin()
{
	float lineThickness = UserDrawTool.GetLineToolThickness();
	m_LineThicknessVisual.setSize(sf::Vector2f(lineThickness, 36));
	m_LineThicknessVisual.setOrigin(sf::Vector2f(lineThickness / 2, 18));
}
