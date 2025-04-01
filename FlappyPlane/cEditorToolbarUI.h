#pragma once
#include <SFML/Graphics.hpp>
#include "cFileInterface.h"
#include "cRectPlatformToolButton.h"
//#include "cLineToolButton.h"
//#include "cCircleToolButton.h"
//#include "cStampToolButton.h"
//#include "cPolygonToolButton.h"
//#include "cSaveButton.h"
//#include "cLoadButton.h"
//#include "cColorPickerButton.h"


class cEditorToolbarUI {
public:
    cEditorToolbarUI(sf::RenderWindow* window, cEditorDrawTool& _DrawTool, sf::RenderTexture* _canvasTexture);
    void Draw(sf::RenderWindow& window);
private:
    cEditorDrawTool& UserDrawTool;
    FileInterface m_FileInterface;
    //Window variable
    sf::RenderWindow* RenderWindow;
    cRectPlatformToolButton ButtonRectangleTool;
    // Load background image from filesystem
    sf::Texture m_BackgroundTexture;
    sf::Sprite* m_UIBackground;

};