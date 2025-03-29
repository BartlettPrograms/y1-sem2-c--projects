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

class LoadButton : public Button
{
public:
	LoadButton(float x, float y, float width, float height, FileInterface& _userFileInterface, sf::RenderTexture& _canvasTexture);
	~LoadButton();
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	FileInterface& m_FileInterface;
	// Canvas image reference
	sf::RenderTexture& m_CanvasTexture;
	// Load loadIcon from filesystem
	sf::Image m_LoadIconImage;
	sf::Texture m_LoadIconTexture;// Create texture from above
	sf::Sprite* m_UIIcon; // create sprite from above
};