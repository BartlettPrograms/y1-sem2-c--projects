#pragma once
#include <SFML/Graphics.hpp>

class cBaseDrawTool
{
public:
	cBaseDrawTool();
	~cBaseDrawTool();
	void SetShape(sf::Shape* shape);
	sf::Shape* GetShape();
	void SetColor(sf::Color color);
	void DrawToolToScreen(sf::RenderWindow& window);

	virtual void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) = 0;
	virtual void UseTool(sf::Vector2f& mousePos) = 0;
	virtual void CompleteUseTool(sf::RenderTexture& CanvasTexture) = 0;
protected:
	sf::Shape* mShape; // Create a base platform class
};