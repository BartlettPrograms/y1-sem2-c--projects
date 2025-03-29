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


#include "cPolygonToolButton.h"
#include <iostream>
#include "cSaveButton.h"

PolygonToolButton::PolygonToolButton(float x, float y, float width, float height, DrawTool& _userDrawTool)
	: Button(x, y, width, height),
	UserDrawTool(_userDrawTool)
{
	// Load image
	m_PolygonIconImage.loadFromFile("Sprites/PolygonSprite.png");
	m_PolygonIconTexture.loadFromImage(m_PolygonIconImage);
	m_UIIcon = new sf::Sprite(m_PolygonIconTexture);
	// Set position
	m_UIIcon->setOrigin(sf::Vector2f(8, 8));
	m_UIIcon->setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

PolygonToolButton::~PolygonToolButton()
{
	delete m_UIIcon;
}

void PolygonToolButton::OnButtonClick() {
	UserDrawTool.SetTool(DrawTool::ToolType::ToolMode_Polygon);
}

void PolygonToolButton::Draw(sf::RenderWindow& window)
{
	Button::Draw(window);
	window.draw(*m_UIIcon);
}