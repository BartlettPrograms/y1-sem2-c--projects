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


#include "cButton.h"
#include <iostream>

// Constructor
Button::Button(float x, float y, float width, float height)
    : f_PosX(x), f_PosY(y), f_Width(width), f_Height(height),
    isPressed(false), isHovered(false),
    defaultColor(sf::Color::White), hoverColor(sf::Color::Yellow), clickColor(sf::Color::Red)
{
    // Initialize button properties
    buttonShape.setPosition(sf::Vector2f(f_PosX, f_PosY));
    buttonShape.setSize(sf::Vector2f(f_Width, f_Height));

    // Set default colors
    defaultColor = sf::Color(100, 100, 100);  // Gray
    hoverColor = sf::Color(150, 150, 150);    // Lighter gray
    clickColor = sf::Color(80, 80, 80);       // Darker gray

    buttonShape.setFillColor(defaultColor);
    isPressed = false;
    isHovered = false;
}

// Is button hovered?
bool Button::IsMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (mousePos.x < Button::GetXPos() || mousePos.x > GetXPos() + GetWidth()) // mouse outside horizontal bounds
    {
        return false;
    }
    if (mousePos.y < GetYPos() || mousePos.y > GetYPos() + GetHeight()) // mouse outside vertical bounds
    {
        return false;
    }
    return true; // mouse must be inside bounds
}

// Is button clicked?
bool Button::IsButtonClicked(sf::RenderWindow& window) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

// Update Button
void Button::Update(sf::RenderWindow& window) {
    if (IsMouseOver(window)) {
        isHovered = true;
        if (IsButtonClicked(window)) {
            buttonShape.setFillColor(clickColor);
            if (!isPressed)
            {
                isPressed = true;
                OnButtonClick();
            }
        }
        else {
            buttonShape.setFillColor(hoverColor);
            isPressed = false;
        }
    }
    else {
        buttonShape.setFillColor(defaultColor);
        isHovered = false;
        isPressed = false;
    }
}

// Draw the button
void Button::Draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
}

void Button::SetIconShape(sf::Shape* shape)
{
}

// get member variables
float Button::GetXPos() {
    return f_PosX;
}
float Button::GetYPos() {
    return f_PosY;
}
float Button::GetHeight() {
    return f_Height;
}
float Button::GetWidth() {
    return f_Width;
}

// Set member variables
void Button::SetXPos(float _PosX) {
    f_PosX = _PosX;
    buttonShape.setPosition(sf::Vector2f(f_Width, f_Height));
}
void Button::SetYPos(float _PosY) {
    f_PosY = _PosY;
    buttonShape.setPosition(sf::Vector2f(f_Width, f_Height));
}
void Button::SetWidth(float _Width) {
    f_Width = _Width;
    buttonShape.setSize(sf::Vector2f(f_Width, f_Height));
}
void Button::SetHeight(float _Height) {
    f_Height = _Height;
    buttonShape.setSize(sf::Vector2f(f_Width, f_Height));
}