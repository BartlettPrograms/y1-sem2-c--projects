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

class RectangleTool
{
public:
	RectangleTool();
	~RectangleTool();
	void UseTool(sf::Vector2f& mousePos, float _lineThickness);
	void DrawRectToCanvas(sf::RenderTexture& CanvasTexture);
	void UpdateRect(sf::Vector2f mousePos);
	void DrawToScreen(sf::RenderWindow& window);
	void SetColor(sf::Color color);
	void SetShapePosition(sf::Vector2f position);
	sf::RectangleShape GetRect();
private:
	sf::RectangleShape m_RectShape;
};