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
	virtual void DrawToolToScreen(sf::RenderWindow& window) = 0;

	virtual void UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos) = 0;
	virtual void UseTool(sf::Vector2f& mousePos) = 0;
	virtual void CompleteUseTool() = 0;
protected:
	sf::Shape* mShape; // Create a base platform class
};