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


#include "cLoadButton.h"

LoadButton::LoadButton(float x, float y, float width, float height, FileInterface& _userFileInterface, sf::RenderTexture& _canvasTexture)
	: Button(x, y, width, height), m_FileInterface(_userFileInterface), m_CanvasTexture(_canvasTexture) 
{
	// Load image
	m_LoadIconImage.loadFromFile("Sprites/LoadIcon.png");
	m_LoadIconTexture.loadFromImage(m_LoadIconImage);
	m_UIIcon = new sf::Sprite(m_LoadIconTexture);
	// Set position
	m_UIIcon->setOrigin(sf::Vector2f(8, 8));
	m_UIIcon->setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

LoadButton::~LoadButton()
{
	delete m_UIIcon;
}

void LoadButton::OnButtonClick()
{
	m_FileInterface.LoadFile(&m_CanvasTexture);
}

void LoadButton::Draw(sf::RenderWindow& window) 
{
	Button::Draw(window);
	window.draw(*m_UIIcon);
}