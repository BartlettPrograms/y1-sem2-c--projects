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


#include "cLineThicknessNegativeButton.h"

LineThicknessNegativeButton::LineThicknessNegativeButton(float x, float y, float width, float height, DrawTool& _userDrawTool)
    : Button(x, y, width, height),
    m_UserDrawTool(_userDrawTool), 
    m_UIIcon(sf::Vector2f(24.0f, 6.0f))
{
    // Minus Icon Rectangle
    m_UIIcon.setFillColor(sf::Color::Black);
    m_UIIcon.setOrigin(sf::Vector2f(12, 3));
    m_UIIcon.setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));// Rectangle 1
}

void LineThicknessNegativeButton::OnButtonClick()
{
    m_UserDrawTool.ChangeLineToolThickness(-5);
}

void LineThicknessNegativeButton::Draw(sf::RenderWindow& window)
{
    Button::Draw(window);
    window.draw(m_UIIcon);
}
