/*#pragma once
#include "cButton.h"
#include "cDrawTool.h"

class StampToolButton : public Button
{
public:
	StampToolButton(float x, float y, float width, float height, DrawTool& tool);
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	DrawTool& UserDrawTool;
	// Load saveIcon from filesystem
	sf::Image m_SaveIconImage;
	sf::Texture m_SaveIconTexture;// Create texture from above
	sf::Sprite* m_UIIcon; // create sprite from above
};*/