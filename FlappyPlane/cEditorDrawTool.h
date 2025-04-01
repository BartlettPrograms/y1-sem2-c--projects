#pragma once
#include "cRectangleTool.h"
//#include "cCircleTool.h"
//#include "cLineTool.h"
//#include "cPolygonTool.h"
//#include "cStampTool.h"
#include <SFML/Graphics.hpp>

class cEditorDrawTool {
public:
    DrawTool(sf::RenderTexture& canvasTexture);
    enum class ToolType {
        ToolMode_None,
        ToolMode_Rect,
        ToolMode_Circle,
        ToolMode_Line,
        ToolMode_Polygon,
        ToolMode_StampTool
    };
    void SetTool(ToolType type);
    void SetColor(sf::Color color);
    void UseTool(sf::RenderWindow& window, sf::Vector2f& mousePos);
    void DrawToolToBoard(sf::RenderWindow& window);
    void UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos);
    void ChangeLineToolThickness(float changeValue);
    float GetLineToolThickness();
    void DrawCurrentToolToBoard(sf::RenderWindow& window);
    void OnRightMouseClick();
    //StampTool& GetStampTool();
private:
    ToolType m_ActiveTool = ToolType::ToolMode_Rect;
    cRectangleTool m_RectangleTool;
    //CircleTool m_CircleTool;
    //LineTool m_LineTool;
    //PolygonTool m_PolygonTool;
    //StampTool m_StampTool;
    bool m_IsDrawing = false;
    sf::RectangleShape m_Rectangle;
    sf::Vector2f m_NewShapeSize;
    // Canvas objects
    sf::RenderTexture& m_CanvasTexture;
};