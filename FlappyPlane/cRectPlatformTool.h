#pragma once
#include "cPlatformRect.h"
#include "cBaseDrawTool.h"

#include <iostream>

class cRectPlatformTool : cBaseDrawTool
{
public:
	cRectPlatformTool();
	~cRectPlatformTool();
	void UseTool(sf::Vector2f& mousePos) override;
	void CompleteUseTool(sf::RenderTexture& CanvasTexture) override; // instead of canvas texture we need some type of list
	void UpdateShape(sf::Vector2f mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(20, 20);
};