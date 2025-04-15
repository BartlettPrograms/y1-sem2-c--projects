#include "cEditorDrawTool.h"

cEditorDrawTool::cEditorDrawTool(sf::RenderWindow& mainWindow)
	: mMainWindow(mainWindow)
	, mActiveTool(nullptr)
{
	SetTool(cEditorDrawTool::ToolType::ToolMode_Rect);
}

void cEditorDrawTool::SetTool(ToolType type)
{
	switch (type)
	{
	case cEditorDrawTool::ToolType::ToolMode_Rect:
		mActiveTool = &mRectangleTool;
		break;
	}
}

void cEditorDrawTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos)
{
	mActiveTool->UpdateCursor(window, mousePos);
}

void cEditorDrawTool::UseTool(sf::Vector2f& mousePos)
{
	mActiveTool->UseTool(mousePos);
}

