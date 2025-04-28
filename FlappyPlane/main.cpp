#include "cApplicationManager.h"
#include "cMainMenu.h"
#include "cGameManager.h"
#include "cLevelPlatformsList.h"
#include "cLevelEditorManager.h"
#include "cPlayerInput.h"
#include "cFileInterface.h"

int main()
{
    // Background texture
    sf::RenderWindow window(sf::VideoMode({ 1366, 768}), "Ninja Clone");
    sf::RectangleShape Background(sf::Vector2f(window.getSize()));
    Background.setFillColor(sf::Color(150, 150, 150));


    // Application Manager
    cApplicationManager& AppManager = cSingleton::GetInstance().AppManager;
    AppManager.IsGameRunning();

    std::cout << "GameManager Running: " << AppManager.IsGameRunning() << std::endl;
    std::cout << "LevelEditor Running: " << AppManager.IsLevelEditorRunning() << std::endl;

    // === cSingleton::GetInstance() ===

    // Create File Interface
    cFileInterface FileInterface;
    // Shared Level list
    cLevelPlatformsList LevelPlatformsList;
    // Create Game managers
    cPlayerInput PlayerInput;
    cGameManager GameManager(window, PlayerInput, LevelPlatformsList);
    // Create Level Editor
    cLevelEditorManager LevelEditor(window, PlayerInput, LevelPlatformsList, FileInterface);
    // Create Main Menu
    cMainMenu MainMenu(window);

    // Create Application Manager
    cApplicationManager ApplicationManager;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(Background);
        if (AppManager.IsGameRunning())
        {
            // Draw / Run game
            GameManager.GameTick();
        }
        if (AppManager.IsLevelEditorRunning())
        {
            // Draw / Run level editor
            LevelEditor.Update();
            LevelEditor.Draw();
        }
        if (AppManager.IsMainMenuActive())
        {
            // Draw / Run MainMenu
            MainMenu.Update();
        }
        window.display();
    }

    return 0;
}