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


#include "cRectangleToolButton.h"
#include <iostream>

RectangleToolButton::RectangleToolButton(float x, float y, float width, float height, DrawTool& _userDrawTool)
    : Button(x, y, width, height),
    UserDrawTool(_userDrawTool), m_UIIcon(sf::Vector2f(16.0f, 16.0f)) 
{
    m_UIIcon.setFillColor(sf::Color::Blue);
    m_UIIcon.setOrigin(sf::Vector2f(8, 8));
    m_UIIcon.setPosition(sf::Vector2f(f_PosX + (f_Width / 2), f_PosY + (f_Height / 2)));
}

void RectangleToolButton::OnButtonClick() {
    UserDrawTool.SetTool(DrawTool::ToolType::ToolMode_Rect);
}

void RectangleToolButton::Draw(sf::RenderWindow& window)
{
    Button::Draw(window);
    window.draw(m_UIIcon);
}