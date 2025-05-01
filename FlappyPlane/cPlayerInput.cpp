#include "cPlayerInput.h"
#include <iostream>

cPlayerInput::cPlayerInput()
{
}

/*
void cPlayerInput::UpdateInput(const sf::Event* event)
{
    // Key pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        m_bSpacePressed = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        m_bLeftArrowPressed = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        m_bRightArrowPressed = true;
    }

    // Key released
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        m_bSpacePressed = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        m_bLeftArrowPressed = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        m_bRightArrowPressed = false;
    }
}
*/

bool cPlayerInput::IsJumpInputPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}

bool cPlayerInput::IsMoveLeftInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
}

bool cPlayerInput::IsMoveRightInputPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D));
}

bool cPlayerInput::IsLeftClickPressed() const
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}
