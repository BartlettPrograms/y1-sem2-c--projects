#pragma once
#include "cPlatformRect.h"
#include "cBaseDrawTool.h"

#include <iostream>

class cRectPlatformTool : public cBaseDrawTool
{
public:
	cRectPlatformTool();
	~cRectPlatformTool();
	void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) override;
	void DrawToolToScreen(sf::RenderWindow& window) override;
	cPlatformRect* CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(20, 20);
};