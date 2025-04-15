#pragma once
#include "cRectPlatformTool.h"
//#include "cCircleTool.h"
//#include "cLineTool.h"
//#include "cPolygonTool.h"
//#include "cStampTool.h"
#include <SFML/Graphics.hpp>

class cEditorDrawTool {
public:
    cEditorDrawTool(sf::RenderWindow& mainWindow);
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
    void PlacePlatform();
private:
    sf::RenderWindow& mMainWindow;
    cBaseDrawTool* mActiveTool;
    cRectPlatformTool mRectangleTool;
};