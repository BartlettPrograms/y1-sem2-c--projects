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
#include <SFML/Graphics.hpp>

class Button {
protected:
    sf::RectangleShape buttonShape;
    sf::Shape* iconShape;
    sf::Color defaultColor;
    sf::Color hoverColor;
    sf::Color clickColor;
    bool isPressed;
    bool isHovered;
    float f_PosX;
    float f_PosY;
    float f_Width;
    float f_Height;

public:
    Button(float x, float y, float width, float height);
    virtual ~Button() = default;
    bool IsMouseOver(sf::RenderWindow& window);
    bool IsButtonClicked(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);

    virtual void OnButtonClick() = 0;

    void SetIconShape(sf::Shape* shape);

    // Getters
    float GetXPos();
    float GetYPos();
    float GetHeight();
    float GetWidth();

    // Setters
    void SetXPos(float x);
    void SetYPos(float y);
    void SetWidth(float width);
    void SetHeight(float height);
};