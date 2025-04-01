#include "cButtonUI.h"
#include <iostream>

// Constructor
cButtonUI::cButtonUI(sf::Vector2f position, sf::Vector2f size)
    : mPosition(position), 
    mSize(size),
    isPressed(false), 
    isHovered(false)
{
    mButtonShape.setPosition(mPosition);
    mButtonShape.setSize(mSize);
    mButtonShape.setOrigin(mSize / 2.0f);

    // Set default colors
    mDefaultColor = sf::Color(100, 100, 100);  // Gray
    mHoverColor = sf::Color(150, 150, 150);    // Lighter gray
    mClickColor =  sf::Color(80, 80, 80);       // Darker gray

    mButtonShape.setFillColor(mDefaultColor);
    isPressed = false;
    isHovered = false;
}

// Is button hovered?
bool cButtonUI::IsMouseOver(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (mousePos.x < mPosition.x - (mSize.x / 2) || mousePos.x > mPosition.x + (mSize.x / 2)) // mouse outside horizontal bounds
    {
        return false;
    }
    if (mousePos.y < mPosition.y - (mSize.y / 2)|| mousePos.y > mPosition.y + (mSize.y / 2)) // mouse outside vertical bounds
    {
        return false;
    }
    return true; // mouse must be inside bounds
}

// Is button clicked?
bool cButtonUI::IsButtonClicked(sf::RenderWindow& window) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

// Update Button
void cButtonUI::Update(sf::RenderWindow& window) {
    if (IsMouseOver(window)) {
        isHovered = true;
        if (IsButtonClicked(window)) {
            mButtonShape.setFillColor(mClickColor);
            if (!isPressed)
            {
                isPressed = true;
                OnButtonClick();
            }
        }
        else {
            mButtonShape.setFillColor(mHoverColor);
            isPressed = false;
        }
    }
    else {
        mButtonShape.setFillColor(mDefaultColor);
        isHovered = false;
        isPressed = false;
    }
}

// Draw the button
void cButtonUI::Draw(sf::RenderWindow& window) {
    window.draw(mButtonShape);
}

// get member variables
sf::Vector2f cButtonUI::GetPosition()
{
    return mPosition;
}
sf::Vector2f cButtonUI::GetSize()
{
    return mSize;
}


// Set member variables
void cButtonUI::SetPosition(sf::Vector2f position) {
    mPosition = position;
}
void cButtonUI::SetSize(sf::Vector2f size) {
    mPosition = size;
}