#include <SFML/Graphics.hpp>
#include "cGameManager.h"
#include "cMainMenu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1366, 768}), "Ninja Clone");
    window.setKeyRepeatEnabled(false);
    sf::RectangleShape Background(sf::Vector2f(window.getSize()));
    Background.setFillColor(sf::Color(150, 150, 150));

    cMainMenu MainMenu(window);
    cGameManager GameManager(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(Background);
        GameManager.GameTick();
        MainMenu.Update();
        window.display();
    }

    return 0;
}