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
#include "cNode.h"
#include "cList.h"
#include "cLineTool.h"
#include <SFML/Graphics.hpp>

class PolygonTool
{
public:
	PolygonTool();
	~PolygonTool();
	void UseTool(sf::Vector2f mousePos);
	void MouseReleased(sf::RenderTexture& _CanvasTexture);
	void UpdateLine(sf::Vector2f mousePos, float lineThickness);
	void DrawToScreen(sf::RenderWindow& window);
	void CompletePolygonStructure(float lineThickness, sf::RenderTexture& _CanvasTexture);
	void SetColor(sf::Color color);
private:
	List m_PolygonVectors;
	sf::ConvexShape m_Polygon;
	LineTool m_LineTool;
	int m_VertexCount;
	bool m_isDrawingLine;
};