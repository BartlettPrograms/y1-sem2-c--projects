#include "cRectPlatformTool.h"


cRectPlatformTool::cRectPlatformTool()
{
	mShape = new sf::RectangleShape(mRectSize);

	mShape->setFillColor(sf::Color::Blue);
}

cRectPlatformTool::~cRectPlatformTool()
{

}

// Mouse Clicked Function
void cRectPlatformTool::UseTool(sf::Vector2f& mousePos)
{
	mShape->setOrigin(sf::Vector2f(0, 0));
	sf::Vector2f NewShapeSize = sf::Vector2f(1, 1) + sf::Vector2f(
		mousePos.x - mShape->getPosition().x,
		mousePos.y - mShape->getPosition().y
	);
	// Dynamic cast on update bad?
	dynamic_cast<sf::RectangleShape*>(mShape)->setSize(NewShapeSize);
}

// Mouse released Function
void cRectPlatformTool::CompleteUseTool()
{
	// bound to pass in
	sf::FloatRect bounds;
	bounds = sf::FloatRect(
		mShape->getPosition(), 
		mShape->getLocalBounds().size
	);

	// Create platform
	cPlatformRect newPlatform = cPlatformRect(bounds);

	// reset size on complete
	// Dynamic cast on update bad?
	dynamic_cast<sf::RectangleShape*>(mShape)->setSize(mRectSize);
}


void cRectPlatformTool::UpdateCursor(sf::RenderWindow& window, sf::Vector2f& mousePos)
{
	mShape->setPosition(mousePos);
}

// Draws tool UI each frame
void cRectPlatformTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(*mShape);
}

