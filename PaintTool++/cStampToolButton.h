#pragma once
#include "cButton.h"
#include "cFileInterface.h"
#include "cDrawTool.h"

class StampToolButton : public Button
{
public:
	StampToolButton(float x, float y, float width, float height, DrawTool& _userDrawTool, FileInterface& _userFileInterface);
	~StampToolButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	// PaintTool++ Objects
	FileInterface& m_FileInterface;
	DrawTool& m_UserDrawTool;
	// Load Icon from filesystem
	sf::Image m_StampIconImage;
	sf::Texture m_StampIconTexture;// Create texture from above
	sf::Sprite* m_UIIcon; // create sprite from above
};