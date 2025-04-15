#pragma once
#include <SFML/Graphics.hpp>
#include "cFileInterface.h"
#include "cRectPlatformToolButton.h"


class cEditorToolbarUI {
public:
    cEditorToolbarUI(sf::RenderWindow& window, cEditorDrawTool& _DrawTool);
    void Update();
    void Draw();
private:
    cEditorDrawTool& UserDrawTool;
    FileInterface m_FileInterface;
    sf::RenderWindow& mMainWindow;
    cRectPlatformToolButton ButtonRectangleTool;

    // Toolbar Window
    sf::RenderWindow mToolbarWindow;

    // Background Image
    sf::Texture m_BackgroundTexture;
    sf::Sprite* m_UIBackground;
};