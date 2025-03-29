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



#include "cPolygonTool.h"
#include <iostream>

PolygonTool::PolygonTool()
	: m_VertexCount(0),
	m_isDrawingLine(false)
{
	m_LineTool.SetColor(sf::Color::Black);
	m_Polygon.setFillColor(sf::Color::Magenta);
	m_Polygon.setOutlineColor(sf::Color::Black);
}

PolygonTool::~PolygonTool()
{
	m_PolygonVectors.ClearList();
}

// Mouse Pressed
void PolygonTool::UseTool(sf::Vector2f mousePos)
{
	if (!m_isDrawingLine) return;

	// Add new vertex
	m_PolygonVectors.InsertTail(m_VertexCount, m_LineTool.GetLineRect(), mousePos);
	m_VertexCount++;

	// Set the line's starting position to the last vertex (if any)
	if (m_VertexCount > 0) {
		Node* lastNode = m_PolygonVectors.GetNode(m_VertexCount - 1);
		if (lastNode != nullptr) {
			m_LineTool.SetShapePosition(lastNode->GetFinalPosition());
		}
		else {
			std::cerr << "Error: Last node is nullptr when m_VertexCount = " << m_VertexCount << std::endl;
			return; // Or handle the error appropriately
		}
	}
	m_isDrawingLine = false;
}
// Mouse Released
void PolygonTool::MouseReleased(sf::RenderTexture& _CanvasTexture)
{
	//m_LineTool.SetShapePosition(m_PolygonVectors.GetNode(m_VertexCount)->GetFinalPosition());
	m_isDrawingLine = true;
	m_LineTool.SetShapeSize(sf::Vector2f(25, 7));
}

void PolygonTool::UpdateLine(sf::Vector2f mousePos, float lineThickness)
{
	// dont move line to cursor only if not drawing
	if (!m_isDrawingLine && m_VertexCount == 0) {
		m_LineTool.UpdateLine(mousePos);
	}
	else {
		// tool being used - draw line from placement to cursor
		m_LineTool.UseTool(mousePos, lineThickness);
	}
}

void PolygonTool::DrawToScreen(sf::RenderWindow& window)
{
	m_LineTool.DrawToScreen(window);
	if (m_VertexCount > 0)
	{
		for (int i = 0; i < m_PolygonVectors.NumNodes(); i++)
		{
			window.draw(m_PolygonVectors.GetNode(i)->GetRect());
		}
	}

	window.draw(m_Polygon);
}

void PolygonTool::CompletePolygonStructure(float lineThickness, sf::RenderTexture& _CanvasTexture)
{
	m_isDrawingLine = false;
	m_Polygon.setPointCount(m_VertexCount);

	for (int i = 0; i < m_VertexCount; i++)
	{
		m_Polygon.setPoint(i, { m_PolygonVectors.GetNode(i)->GetFinalPosition() });

	}
	m_Polygon.setOutlineThickness(lineThickness);
	_CanvasTexture.draw(m_Polygon);
	m_VertexCount = 0;
	m_PolygonVectors.ClearList();
	// reset line tool length
	m_LineTool.SetShapeSize(sf::Vector2f(25, 7));
}

void PolygonTool::SetColor(sf::Color color)
{
	m_Polygon.setFillColor(color);
}
