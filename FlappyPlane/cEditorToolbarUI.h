#pragma once
#include <SFML/Graphics.hpp>
#include "cEditorDrawTool.h"
#include "cFileInterface.h"
#include "ToolButtonRect.h"
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
    void UpdateLineThicknessUIOrigin();
private:
    cEditorDrawTool& UserDrawTool;
    FileInterface m_FileInterface;
    // Canvas texture reference
    sf::RenderTexture& m_canvasTexture;
    //Window variable
    sf::RenderWindow* RenderWindow;
    // Create Buttons here
    RectangleToolButton ButtonRectangleTool;
    //CircleToolButton ButtonCircleTool;
    //LineToolButton ButtonLineTool;
    //PolygonToolButton ButtonPolygonTool;
    //StampToolButton m_ButtonStampTool;
    //SaveButton m_SaveButton;
    //LoadButton m_LoadButton;
    //LineThicknessNegativeButton m_LineThicknessNegativeButton;
    //LineThicknessPositiveButton m_LineThicknessPositiveButton;
    //ColorPickerButton m_ColorPickerButton;
    // Load background image from filesystem
    sf::Texture m_BackgroundTexture;// Create texture from above
    sf::Sprite* m_UIBackground; // create sprite from above

    // Line thickness visual icon
    sf::RectangleShape m_LineThicknessVisual;
};