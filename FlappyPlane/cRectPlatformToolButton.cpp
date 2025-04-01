#include "cRectPlatformToolButton.h"

cRectPlatformToolButton::cRectPlatformToolButton(sf::Vector2f position, sf::Vector2f size, cEditorDrawTool& tool)
	: cButtonUI(position, size)
	, mUserDrawTool(tool)
{

}

cRectPlatformToolButton::~cRectPlatformToolButton()
{
}

void cRectPlatformToolButton::OnButtonClick() {
	mUserDrawTool.SetTool(cEditorDrawTool::ToolType::ToolMode_Rect);
}