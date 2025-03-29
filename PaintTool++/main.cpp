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


#include <SFML/Graphics.hpp>
#include "cDrawTool.h"
#include "cToolbar.h"
#include "cColorPicker.h"
#include <iostream>
#include <cmath>


int main()
{
    // Create Windows
    sf::RenderWindow WindowCanvas(sf::VideoMode({ 1280, 720 }), "Paint++");
    sf::RenderWindow WindowToolbar(sf::VideoMode({ 256, 205 }), "Toolbar++");
    sf::RenderWindow WindowColourPicker(sf::VideoMode({ 256, 255 }), "Color Picker++");
    WindowToolbar.setPosition(WindowCanvas.getPosition() + sf::Vector2i(WindowCanvas.getSize().x + 2, 0));
    WindowColourPicker.setPosition(WindowCanvas.getPosition() - sf::Vector2i(WindowColourPicker.getSize().x + 2, 0));
    WindowCanvas.setMouseCursorVisible(false);
    WindowCanvas.setFramerateLimit(60);
    WindowToolbar.setFramerateLimit(60);


    // Create Canvas to paint on
    sf::RenderTexture BackgroundTexture{ WindowCanvas.getSize() };
    sf::Sprite CanvasSprite(BackgroundTexture.getTexture());
    BackgroundTexture.clear(sf::Color::White);

    DrawTool UserDrawTool(BackgroundTexture);

    // Create Toolbar
    ToolbarUI Toolbar(&WindowToolbar, UserDrawTool, &BackgroundTexture);

    // Create Colour picker window
    ColorPicker UserColorPicker;

    // Track mouse position
    sf::Vector2i mousePos;

    // Main Loop
    while (WindowCanvas.isOpen())
    {
        // Detect window closures && mouse release
        while (const std::optional CanvasEvent = WindowCanvas.pollEvent())
        {
            // Close Window
            if (CanvasEvent->is<sf::Event::Closed>())
                WindowCanvas.close();
            // Handle OnMouseReleased
            if (CanvasEvent->is<sf::Event::MouseButtonReleased>())
            {
                if (const auto* buttonPressed = CanvasEvent->getIf<sf::Event::MouseButtonReleased>())
                {
                    if (buttonPressed->button == sf::Mouse::Button::Left)
                    {
                        // Stop Drawing.. display shape
                        UserDrawTool.DrawToolToBoard(WindowCanvas);
                    }
                }
            }
        }
        while (const std::optional ToolbarEvent = WindowToolbar.pollEvent())
        {
            if (ToolbarEvent->is<sf::Event::Closed>())
                WindowCanvas.close();
        }
        while (const std::optional ColorPickerEvent = WindowColourPicker.pollEvent())
        {
            if (ColorPickerEvent->is<sf::Event::Closed>())
                WindowCanvas.close();

            if (ColorPickerEvent->is<sf::Event::MouseButtonPressed>())
            {
                if (WindowColourPicker.hasFocus())
                {
                    UserColorPicker.PickColor(WindowColourPicker, UserDrawTool);
                }
            }
        }
        sf::Vector2i mousePosInt = sf::Mouse::getPosition(WindowCanvas);
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(mousePosInt);
        // Handle OnMouseClicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (WindowCanvas.hasFocus())
            {
                UserDrawTool.UseTool(WindowCanvas, mousePos);
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            if (WindowCanvas.hasFocus())
            {
                UserDrawTool.OnRightMouseClick();
            }
        }

       // Clear Windows
        WindowCanvas.clear();
        WindowToolbar.clear();
        // Draw Canvas
        WindowCanvas.draw(CanvasSprite);
        // Draw toolbar
        Toolbar.Draw(WindowToolbar);
        // Draw Colour picker sprite
        UserColorPicker.DrawColorPicker(WindowColourPicker);
        // Display mouse cursor
        UserDrawTool.UpdateCursor(WindowCanvas, mousePos);
        UserDrawTool.DrawCurrentToolToBoard(WindowCanvas);
        // Display draw buffer
        WindowCanvas.display();
        WindowToolbar.display();
        WindowColourPicker.display();
    }
}