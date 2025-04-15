#pragma once
#include "cRectPlatformTool.h"
#include <SFML/Graphics.hpp>
#include "cLevelPlatformsList.h"
#include "cPlayerInput.h"

class cEditorDrawTool {
public:
    cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList);
    enum class ToolType {
        ToolMode_None,
        ToolMode_Rect,
        ToolMode_Circle,
        ToolMode_Line,
        ToolMode_Polygon,
        ToolMode_StampTool
    };
    void SetTool(ToolType type);
    void UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos);
    void UseTool(sf::Vector2f& mousePos);
    void DrawCursorToScreen(sf::RenderWindow& window);
    void CompleteUseTool();
private:
    cPlayerInput& mPlayerInput;
    sf::RenderWindow& mMainWindow;
    cBaseDrawTool* mActiveTool;
    cRectPlatformTool mRectangleTool;

    // Current Game Level data
    cLevelPlatformsList& mPlatformsList; // Platforms
};