#include "cEditorDrawTool.h"

cEditorDrawTool::cEditorDrawTool(sf::RenderWindow& mainWindow, cPlayerInput& playerInput, cLevelPlatformsList& platformsList)
	: mMainWindow(mainWindow)
	, mActiveTool(nullptr)
	, mPlayerInput(playerInput)
	, mPlatformsList(platformsList)
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

void cEditorDrawTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f toolPosition)
{
	// Left click / Draw Logic
	if (mPlayerInput.IsLeftClickPressed() && window.hasFocus())
	{
		UseTool(toolPosition);
		mIsDrawing = true;
	}
	else
	{
		if (mIsDrawing)
		{
			CompleteUseTool();
			mIsDrawing = false;
		}
		else
		{
			mActiveTool->UpdateCursor(window, toolPosition);
		}
	}

	// Right click / Delete Logic
	if (mPlayerInput.IsRightClickPressed() && window.hasFocus())
	{
		sf::Vector2f mousePosF = sf::Vector2f(sf::Mouse::getPosition());
		mPlatformsList.CheckCollisionWithPoint(&mousePosF);
	}
}

void cEditorDrawTool::UseTool(sf::Vector2f& toolPosition)
{
	toolPosition.x += mGridSize;
	toolPosition.y += mGridSize;
	mActiveTool->UseTool(toolPosition);
}

void cEditorDrawTool::CompleteUseTool()
{
	cPlatformRect* platform = mActiveTool->CompleteUseTool();
	mPlatformsList.AddPlatform(platform);
}

void cEditorDrawTool::DeleteTool()
{
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition());
	mPlatformsList.CheckCollisionWithPoint(&mousePos);
}

void cEditorDrawTool::DrawCursorToScreen(sf::RenderWindow& window)
{
	mActiveTool->DrawToolToScreen(window);
}