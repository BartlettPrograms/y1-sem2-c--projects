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


#include "cCircleTool.h"
#include <iostream>

CircleTool::CircleTool() : m_CircleShape(16)
{
	m_CircleShape.setOutlineThickness(3);
	m_CircleShape.setOutlineColor(sf::Color::Black);
}

CircleTool::~CircleTool()
{

}

void CircleTool::UseTool(sf::Vector2f& mousePos, float _lineThickness)
{
	//Set border thickness
	m_CircleShape.setOutlineThickness(_lineThickness);
	// Set origin to top left
	m_CircleShape.setOrigin(sf::Vector2f(0, 0));
	// Get mouse position and circle position
	sf::Vector2f circlePos = m_CircleShape.getPosition();

	// Calculate the differences in x and y
	float deltaX = mousePos.x - circlePos.x;
	float deltaY = mousePos.y - circlePos.y;

	// Calculate radius
	float NewCircleRadius = std::sqrt(deltaX * deltaX + deltaY * deltaY);
	m_CircleShape.setRadius(NewCircleRadius);

	// Calculate scale factors
	const float epsilon = 0.0001f; // Avoid division by zero
	float scaleX = deltaX / (NewCircleRadius + epsilon);
	float scaleY = deltaY / (NewCircleRadius + epsilon);

	// Apply the scale
	m_CircleShape.setScale(sf::Vector2f(scaleX, scaleY));
}

void CircleTool::DrawCircleToCanvas(sf::RenderTexture& CanvasTexture)
{
	CanvasTexture.draw(m_CircleShape);
	std::cout << "Successfully drawn circle to board" << std::endl;
	m_CircleShape.setRadius(12.5);
	m_CircleShape.setScale(sf::Vector2f(1, 1));
}

void CircleTool::UpdateCircle(sf::Vector2f mousePos)
{
	m_CircleShape.setPosition(mousePos);

}

void CircleTool::DrawToScreen(sf::RenderWindow& window)
{
	window.draw(m_CircleShape);
}

void CircleTool::SetColor(sf::Color color)
{
	m_CircleShape.setFillColor(color);
}

void CircleTool::SetShapePosition(sf::Vector2f position)
{
	m_CircleShape.setPosition(position);
}

sf::CircleShape CircleTool::GetCircle()
{
	return m_CircleShape;
}
