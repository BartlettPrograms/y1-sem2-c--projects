#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class RectangleToolButton : public cButtonUI
{
public:
    RectangleToolButton(float x, float y, float width, float height, cEditorDrawTool& tool);
    ~RectangleToolButton();
    void OnButtonClick() override;
    void Draw(sf::RenderWindow& window) override;
private:
    cEditorDrawTool& UserDrawTool;
    sf::RectangleShape m_UIIcon;
};