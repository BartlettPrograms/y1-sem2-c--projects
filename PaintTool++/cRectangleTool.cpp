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


#include "cRectangleTool.h"
#include <iostream>

RectangleTool::RectangleTool() : m_RectShape(sf::Vector2f(26, 26))
{
	m_RectShape.setFillColor(sf::Color::Blue);
	m_RectShape.setOutlineColor(sf::Color::Black);
}

RectangleTool::~RectangleTool()
{

}

// Mouse Clicked Function
void RectangleTool::UseTool(sf::Vector2f& mousePos, float _lineThickness)
{
    // Outer rectangle setup
	m_RectShape.setOrigin(sf::Vector2f(0, 0));
	m_RectShape.setOutlineThickness(_lineThickness);
    sf::Vector2f NewShapeSize = sf::Vector2f(1, 1) + sf::Vector2f(
        mousePos.x - m_RectShape.getPosition().x,
        mousePos.y - m_RectShape.getPosition().y
    );
	m_RectShape.setSize(NewShapeSize);
}
// Mouse released Function
void RectangleTool::DrawRectToCanvas(sf::RenderTexture& CanvasTexture)
{
	CanvasTexture.draw(m_RectShape);
	m_RectShape.setSize(sf::Vector2f(26, 26));
}

void RectangleTool::UpdateRect(sf::Vector2f mousePos)
{
	m_RectShape.setPosition(mousePos);
}

void RectangleTool::DrawToScreen(sf::RenderWindow& window)
{
	window.draw(m_RectShape);
}

void RectangleTool::SetColor(sf::Color color)
{
	m_RectShape.setFillColor(color);
}

void RectangleTool::SetShapePosition(sf::Vector2f position)
{
	m_RectShape.setPosition(position);
}

sf::RectangleShape RectangleTool::GetRect()
{
	return m_RectShape;
}
