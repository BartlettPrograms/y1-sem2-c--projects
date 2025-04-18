#pragma once
#include <SFML/Graphics.hpp>

class cPlayerInput
{
public:
    cPlayerInput();
    //void UpdateInput(const sf::Event* event); // Takes an event instead of polling
    bool IsJumpInputPressed() const;
    bool IsMoveLeftInputPressed() const;
    bool IsMoveRightInputPressed() const;
    bool IsLeftClickPressed() const;
};