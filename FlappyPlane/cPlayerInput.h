#pragma once
#include <SFML/Graphics.hpp>

class cPlayerInput
{
public:
    cPlayerInput();
    //void UpdateInput(const sf::Event* event); // Takes an event instead of polling
    bool IsSpacePressed() const;
    bool IsLeftArrowPressed() const;
    bool IsRightArrowPressed() const;
    bool IsLeftClickPressed() const;
};