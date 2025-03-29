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


#include "cLineThicknessPositiveButton.h"

LineThicknessPositiveButton::LineThicknessPositiveButton(float x, float y, float width, float height, DrawTool& _userDrawTool)
    : Button(x, y, width, height),
    m_UserDrawTool(_userDrawTool),
    m_UIIcon1(sf::Vector2f(24.0f, 6.0f)),
    m_UIIcon2(sf::Vector2f(6.0f, 24.0f))
{
    // Plus horizontal Rectangle
    m_UIIcon1.setFillColor(sf::Color::Black);
    m_UIIcon1.setOrigin(sf::Vector2f(12, 3));
    m_UIIcon1.setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
    // Plus vertical Rectangle
    m_UIIcon2.setFillColor(sf::Color::Black);
    m_UIIcon2.setOrigin(sf::Vector2f(3, 12));
    m_UIIcon2.setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

void LineThicknessPositiveButton::OnButtonClick()
{
    m_UserDrawTool.ChangeLineToolThickness(5);
}

void LineThicknessPositiveButton::Draw(sf::RenderWindow& window)
{
    Button::Draw(window);
    window.draw(m_UIIcon1);
    window.draw(m_UIIcon2);
}
