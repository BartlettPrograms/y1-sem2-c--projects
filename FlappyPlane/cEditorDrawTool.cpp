#include "cEditorDrawTool.h"

cEditorDrawTool::cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput)
	: mMainWindow(mainWindow)
	, mActiveTool(nullptr)
	, mPlayerInput(playerInput)
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
	if (mPlayerInput.IsLeftClickPressed())
	{
		UseTool(mousePos);
	}
	else
	{
		mActiveTool->UpdateCursor(window, mousePos);
	}
}

void cEditorDrawTool::UseTool(sf::Vector2f& mousePos)
{
	mActiveTool->UseTool(mousePos);
}

void cEditorDrawTool::DrawCursorToScreen(sf::RenderWindow& window)
{
	mActiveTool->DrawToolToScreen(window);
}

void cEditorDrawTool::CompleteUseTool()
{
	mActiveTool->CompleteUseTool();
}

