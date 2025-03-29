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
#include "cButton.h"
#include "cDrawTool.h"

class LineThicknessPositiveButton : public Button
{
public:
    LineThicknessPositiveButton(float x, float y, float width, float height, DrawTool& tool);
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    DrawTool& m_UserDrawTool;
    sf::RectangleShape m_UIIcon1;
    sf::RectangleShape m_UIIcon2;
};