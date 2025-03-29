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


#include "cLineTool.h"
#include <iostream>

LineTool::LineTool() : m_LineShape(sf::Vector2f(25, 7))
{

}

LineTool::~LineTool()
{

}

void LineTool::UseTool(sf::Vector2f& mousePos, float _lineThickness)
{
	// Set origin to top left
	m_LineShape.setOrigin(sf::Vector2f(0, 0));

	// Get Line Start Position
	sf::Vector2f linePos = m_LineShape.getPosition();

	// Calculate the differences in x and y
	float deltaX = mousePos.x - linePos.x;
	float deltaY = mousePos.y - linePos.y;
	// Calculate distance
	float length = std::sqrt(deltaX * deltaX + deltaY * deltaY);

	// Set the rectangle size
	m_LineShape.setSize(sf::Vector2f(length, _lineThickness));

	// Calculate the angle in degrees
	float angle = std::atan2(deltaY, deltaX) * 180.0f / 3.1415926535f;

	// Set the rotation
	m_LineShape.setRotation(sf::degrees(angle));

	// set new shape size x to length
	m_LineShape.setSize(sf::Vector2f(length, _lineThickness));

	// set new origin
	m_LineShape.setOrigin(sf::Vector2f(0, _lineThickness / 2));
}

void LineTool::DrawLineToCanvas(sf::RenderTexture& CanvasTexture)
{
	CanvasTexture.draw(m_LineShape);
	m_LineShape.setSize(sf::Vector2f(25.0f, 7.0f));
}

void LineTool::UpdateLine(sf::Vector2f mousePos)
{
	m_LineShape.setPosition(mousePos);
	
}

void LineTool::DrawToScreen(sf::RenderWindow& window)
{
	window.draw(m_LineShape);
}

void LineTool::SetColor(sf::Color color)
{
	m_LineShape.setFillColor(color);
}

void LineTool::SetShapePosition(sf::Vector2f position)
{
	m_LineShape.setPosition(position);
}

void LineTool::SetShapeSize(sf::Vector2f size)
{
	m_LineShape.setSize(size);
}

sf::RectangleShape LineTool::GetLineRect()
{
	return m_LineShape;
}
