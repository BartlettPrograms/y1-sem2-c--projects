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
#include <SFML/Graphics.hpp>

class StampTool
{
public:
	StampTool();
	~StampTool();
	void DrawStampToCanvas(sf::RenderTexture& CanvasTexture);
	void UpdateSprite(sf::Vector2f mousePos);
	void DrawToScreen(sf::RenderWindow& window);
	sf::Texture& GetStampTexture();
	void RefreshStampSprite();
private:
	// Load loadIcon from filesystem
	sf::Image m_StampImage;
	sf::Texture m_StampTexture;
	sf::Sprite* m_StampSprite;
};