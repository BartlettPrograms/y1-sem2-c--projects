#pragma once
#include <SFML/Graphics.hpp>

class cPlayerInput
{
public:
    cPlayerInput();
    bool IsJumpInputPressed() const;
    bool IsMoveLeftInputPressed() const;
    bool IsMoveRightInputPressed() const;
    bool IsLeftClickPressed() const;
};