/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c)
 2025 Media Design School
 File Name : PaintTool++.exe
 Description : Budget paint tool
 Author : Matthew Bartlett
 Mail : matthew.bartlett@mds.ac.nz
 **************************************************************************/


#pragma once
#include "cButton.h"
#include "cFileInterface.h"
#include "cDrawTool.h"

class ColorPickerButton : public Button
{
public:
	ColorPickerButton(float x, float y, float width, float height, FileInterface& _userFileInterface, DrawTool& _userDrawTool);
	~ColorPickerButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	FileInterface& m_FileInterface;
	DrawTool& m_DrawTool;
	// Load loadIcon from filesystem
	sf::Image m_RainbowIconImage;
	sf::Texture m_RainbowIconTexture;// Create texture from above
	sf::Sprite* m_UIIcon; // create sprite from above
};