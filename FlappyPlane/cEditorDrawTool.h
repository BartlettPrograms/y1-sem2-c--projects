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
    // Left click
    void UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos);
    void UseTool(sf::Vector2f& mousePos);
    void CompleteUseTool();
    // Right click
    void DeleteTool();
    // Draw to screen
    void DrawCursorToScreen(sf::RenderWindow& window);

protected:
    cPlayerInput& mPlayerInput;
    sf::RenderWindow& mMainWindow;
    // Tool objects
    cBaseDrawTool* mActiveTool;
    cRectPlatformTool mRectangleTool;
    
    // DrawGrid
    float mGridSize = 24;

    // Current Game Level data
    cLevelPlatformsList& mPlatformsList; // Platforms

    // Draw tool helpers
    bool mIsDrawing = false;
};