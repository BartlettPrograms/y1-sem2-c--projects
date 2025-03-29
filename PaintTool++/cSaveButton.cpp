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


#include "cSaveButton.h"

SaveButton::SaveButton(float x, float y, float width, float height, FileInterface& _userFileInterface, sf::RenderTexture& _canvasTexture)
	: Button(x, y, width, height), m_FileInterface(_userFileInterface), m_CanvasTexture(_canvasTexture) 
{
	// load image
	m_SaveIconImage.loadFromFile("Sprites/SaveIcon.png");
	m_SaveIconTexture.loadFromImage(m_SaveIconImage);
	m_UIIcon = new sf::Sprite(m_SaveIconTexture);
	// set position
	m_UIIcon->setOrigin(sf::Vector2f(8, 8));
	m_UIIcon->setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

SaveButton::~SaveButton()
{
	delete m_UIIcon;
}

void SaveButton::OnButtonClick()
{
	m_FileInterface.SaveFile(&m_CanvasTexture);
}

void SaveButton::Draw(sf::RenderWindow& window)
{
	Button::Draw(window);
	window.draw(*m_UIIcon);
}