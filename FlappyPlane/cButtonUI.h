#pragma once
#include <SFML/Graphics.hpp>

class cButtonUI {
protected:
    sf::RectangleShape mButtonShape;
    sf::Color mDefaultColor = sf::Color(100, 100, 100);
    sf::Color mHoverColor = sf::Color(150, 150, 150);
    sf::Color mClickColor = sf::Color(80, 80, 80);
    bool isPressed;
    bool isHovered;
    sf::Vector2f mPosition;
    sf::Vector2f mSize;

public:
    cButtonUI(sf::Vector2f position, sf::Vector2f size);
    virtual ~cButtonUI() = default;
    bool IsMouseOver(sf::RenderWindow& window);
    bool IsButtonClicked(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window);

    virtual void OnButtonClick() = 0;

    // Getters
    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();

    // Setters
    void SetPosition(sf::Vector2f position);
    void SetSize(sf::Vector2f size);
};