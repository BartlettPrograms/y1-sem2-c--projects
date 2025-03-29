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


#include "cColorPickerButton.h"

ColorPickerButton::ColorPickerButton(float x, float y, float width, float height, FileInterface& _userFileInterface, DrawTool& _userDrawTool)
	: Button(x, y, width, height), m_FileInterface(_userFileInterface), m_DrawTool(_userDrawTool)
{
	// load image
	m_RainbowIconImage.loadFromFile("Sprites/RainbowIcon.png");
	m_RainbowIconTexture.loadFromImage(m_RainbowIconImage);
	m_UIIcon = new sf::Sprite(m_RainbowIconTexture);
	// set position
	m_UIIcon->setOrigin(sf::Vector2f(8, 8));
	m_UIIcon->setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

ColorPickerButton::~ColorPickerButton()
{
	delete m_UIIcon;
}

void ColorPickerButton::OnButtonClick()
{
	sf::Color newColor;
	m_FileInterface.DialogChooseColor(newColor);
	m_DrawTool.SetColor(newColor);
}

void ColorPickerButton::Draw(sf::RenderWindow& window)
{
	Button::Draw(window);
	window.draw(*m_UIIcon);
}
