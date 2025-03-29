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


#include "cDrawTool.h"
#include <iostream>

//Constructor
DrawTool::DrawTool(sf::RenderTexture& canvasTexture)
	: m_CanvasTexture(canvasTexture),
	m_Circle(m_NewCircleRadius),
	m_Rectangle(sf::Vector2f(25.0f, 25.0f)),
	m_IsDrawing(false),
	m_NewShapeSize(sf::Vector2f(0.0f, 0.0f))
{
	// Set initial properties for member shapes
	m_Circle.setFillColor(sf::Color::Green);
	m_Circle.setOrigin(sf::Vector2f(12.5, 12.5));
	m_Circle.setRadius(m_NewCircleRadius);
	m_Circle.setScale(sf::Vector2f(1, 1));
	m_Rectangle.setPosition(sf::Vector2f(2000, 2000));
	m_Rectangle.setFillColor(sf::Color::Blue);
	m_Rectangle.setOrigin(sf::Vector2f(m_Rectangle.getSize().x / 2, m_Rectangle.getSize().y / 2));
}
// SetDrawTool to Rect, cricle, square
void DrawTool::SetTool(ToolType type)
{
	m_ActiveTool = type;
}
void DrawTool::SetColor(sf::Color color)
{
	m_RectangleTool.SetColor(color);
	m_CircleTool.SetColor(color);
	m_LineTool.SetColor(color);
	m_PolygonTool.SetColor(color);
}
// Mouse Button Pressed function
void DrawTool::UseTool(sf::RenderWindow& window, sf::Vector2f& mousePos) {
	// User draws out what the user wants to add to the board
	m_IsDrawing = true;
	switch (m_ActiveTool)
	{
	case ToolType::ToolMode_Rect:
		m_RectangleTool.UseTool(mousePos, m_LineToolThickness);
		break;
	case ToolType::ToolMode_Circle:
		m_CircleTool.UseTool(mousePos, m_LineToolThickness);
		break;
	case ToolType::ToolMode_Line:
		m_LineTool.UseTool(mousePos, m_LineToolThickness);
		break;
	case ToolType::ToolMode_Polygon:
		m_PolygonTool.UseTool(mousePos);
		break;
	case ToolType::ToolMode_StampTool:
		m_StampTool.DrawStampToCanvas(m_CanvasTexture);
		break;
	}
}
// Mouse Button Released function
void DrawTool::DrawToolToBoard(sf::RenderWindow& window)
{
	m_IsDrawing = false;
	// Write what the user has drawn to the board
	switch (m_ActiveTool)
	{
	case ToolType::ToolMode_Rect:
		m_RectangleTool.DrawRectToCanvas(m_CanvasTexture);
		break;
	case ToolType::ToolMode_Circle:
		m_CircleTool.DrawCircleToCanvas(m_CanvasTexture);
		break;
	case ToolType::ToolMode_Line:
		m_LineTool.DrawLineToCanvas(m_CanvasTexture);
		break;
	case ToolType::ToolMode_Polygon:
		m_PolygonTool.MouseReleased(m_CanvasTexture);
		break;
	}
	m_CanvasTexture.display();
}
// ToolGraphic follow MousePosition
void DrawTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos)
{
	// polygon tool has its own move cursor conditions
	if (m_ActiveTool == DrawTool::ToolType::ToolMode_Polygon)
	{
		m_PolygonTool.UpdateLine(mousePos, m_LineToolThickness);
	}


	if (m_IsDrawing) return;
	// Move shape to cursor position
	switch (m_ActiveTool)
	{
	case DrawTool::ToolType::ToolMode_Rect:
		m_RectangleTool.UpdateRect(mousePos);
		break;
	case DrawTool::ToolType::ToolMode_Circle:
		m_CircleTool.UpdateCircle(mousePos);
		break;
	case DrawTool::ToolType::ToolMode_Line:
		m_LineTool.UpdateLine(mousePos);
		break;
	case ToolType::ToolMode_StampTool:
		m_StampTool.UpdateSprite(mousePos);
		break;
	}
}
// Change line tool thickness
void DrawTool::ChangeLineToolThickness(float changeValueBy)
{
	float newThickness = m_LineToolThickness + changeValueBy;

	// Stop thickness from going below the minimum value
	if (newThickness < 2.0f) {
		return;
	}
	if (newThickness > 145)// Stop the thickness from going above the max value
	{
		return;
	}
	m_LineToolThickness = newThickness;
}
// Get line tool thickness
float DrawTool::GetLineToolThickness()
{
	return m_LineToolThickness;
}

void DrawTool::DrawCurrentToolToBoard(sf::RenderWindow& window)
{
	switch (m_ActiveTool)
	{
	case DrawTool::ToolType::ToolMode_Rect:
		m_RectangleTool.DrawToScreen(window);
		break;
	case DrawTool::ToolType::ToolMode_Circle:
		m_CircleTool.DrawToScreen(window);
		break;
	case DrawTool::ToolType::ToolMode_Line:
		m_LineTool.DrawToScreen(window);
		break;
	case DrawTool::ToolType::ToolMode_Polygon:
		m_PolygonTool.DrawToScreen(window);
		break;
	case ToolType::ToolMode_StampTool:
		m_StampTool.DrawToScreen(window);
		break;
	}
}

void DrawTool::OnRightMouseClick()
{
	// complete polygon structure only
	if (m_ActiveTool == DrawTool::ToolType::ToolMode_Polygon)
	{
		m_PolygonTool.CompletePolygonStructure(m_LineToolThickness, m_CanvasTexture);
	}
}

StampTool& DrawTool::GetStampTool()
{
	return m_StampTool;
}
