#include <SFML/Graphics.hpp>
#include "cMainMenu.h"
#include "cGameManager.h"
#include "cLevelPlatformsList.h"
#include "cLevelEditorManager.h"
#include "cPlayerInput.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1366, 768}), "Ninja Clone");
    sf::RectangleShape Background(sf::Vector2f(window.getSize()));
    Background.setFillColor(sf::Color(150, 150, 150));

    // Level list
    cLevelPlatformsList LevelList;

    // Create Game Objects
    cPlayerInput PlayerInput;
    cGameManager GameManager(window, PlayerInput);

    // Create Level Editor
    cLevelEditorManager LevelEditor(window, PlayerInput);

    // Create Main Menu
    cMainMenu MainMenu(window);

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
        LevelEditor.Update();
        LevelEditor.Draw();
        MainMenu.Update();
        window.display();
    }

    return 0;
}