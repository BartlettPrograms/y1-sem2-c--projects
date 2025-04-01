#pragma once
#include "cButtonUI.h"
#include "cEditorDrawTool.h"

class cEditorDrawTool;

class cRectPlatformToolButton : public cButtonUI
{
public:
    cRectPlatformToolButton(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool);
    ~cRectPlatformToolButton();
    void OnButtonClick() override;
private:
    cEditorDrawTool& mUserDrawTool;
    sf::RectangleShape mUIIcon;
};