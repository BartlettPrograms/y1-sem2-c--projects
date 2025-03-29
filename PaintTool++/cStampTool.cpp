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


#include "cStampTool.h"

StampTool::StampTool() : m_StampSprite()
{
	m_StampImage.loadFromFile("Sprites/LoadIcon.png");
	m_StampTexture.loadFromImage(m_StampImage);
	m_StampSprite = new sf::Sprite(m_StampTexture);
}

StampTool::~StampTool()
{
	delete m_StampSprite;
}

void StampTool::DrawStampToCanvas(sf::RenderTexture& CanvasTexture)
{
	CanvasTexture.draw(*m_StampSprite);
}

void StampTool::UpdateSprite(sf::Vector2f mousePos)
{
	m_StampSprite->setPosition(mousePos);
}

void StampTool::DrawToScreen(sf::RenderWindow& window)
{
	window.draw(*m_StampSprite);
}

sf::Texture& StampTool::GetStampTexture()
{
	return m_StampTexture;
}

void StampTool::RefreshStampSprite()
{
	m_StampSprite->setTexture(m_StampTexture, true);
	m_StampSprite->setOrigin(sf::Vector2f(m_StampTexture.getSize().x / 2.0f, m_StampTexture.getSize().y / 2.0f));
}