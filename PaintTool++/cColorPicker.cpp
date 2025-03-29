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


#include "cColorPicker.h"

ColorPicker::ColorPicker()
{
    m_ColorPickerImage.loadFromFile("Sprites/ColorPicker.png");
    m_ColorPickerTexture.loadFromImage(m_ColorPickerImage);
    m_ColorPickerSprite = new sf::Sprite(m_ColorPickerTexture);
}

ColorPicker::~ColorPicker()
{
    delete m_ColorPickerSprite;
}

void ColorPicker::DrawColorPicker(sf::RenderWindow& window)
{
    window.draw(*m_ColorPickerSprite);
}

void ColorPicker::PickColor(sf::RenderWindow& window, DrawTool& drawTool)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    m_DrawingColor = m_ColorPickerImage.getPixel(sf::Vector2u(mousePos));
    drawTool.SetColor(m_DrawingColor);
}