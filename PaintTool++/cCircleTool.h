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


#pragma once
#include <SFML/Graphics.hpp>

class CircleTool
{
public:
	CircleTool();
	~CircleTool();
	void UseTool(sf::Vector2f& mousePos, float _lineThickness);
	void DrawCircleToCanvas(sf::RenderTexture& CanvasTexture);
	void UpdateCircle(sf::Vector2f mousePos);
	void DrawToScreen(sf::RenderWindow& window);
	void SetColor(sf::Color color);
	void SetShapePosition(sf::Vector2f position);
	sf::CircleShape GetCircle();
private:
	sf::CircleShape m_CircleShape;
};