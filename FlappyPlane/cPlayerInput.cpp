#include "cPlayerInput.h"
#include <iostream>

cPlayerInput::cPlayerInput()
    : m_bSpacePressed(false)
    , m_bLeftArrowPressed(false)
    , m_bRightArrowPressed(false)
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

bool cPlayerInput::IsSpacePressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}

bool cPlayerInput::IsLeftArrowPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}

bool cPlayerInput::IsRightArrowPressed() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
