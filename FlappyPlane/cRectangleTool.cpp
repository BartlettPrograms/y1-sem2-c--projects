#include "cRectangleTool.h"


cRectangleTool::cRectangleTool()
{
	mShape = new sf::RectangleShape(mRectSize);

	mShape->setFillColor(sf::Color::Blue);
}

cRectangleTool::~cRectangleTool()
{

}

// Mouse Clicked Function
void cRectangleTool::UseTool(sf::Vector2f& mousePos)
{
	// Outer rectangle setup
	mShape->setOrigin(sf::Vector2f(0, 0));
	sf::Vector2f NewShapeSize = sf::Vector2f(1, 1) + sf::Vector2f(
		mousePos.x - mShape->getPosition().x,
		mousePos.y - mShape->getPosition().y
	);
	// Dynamic cast on update bad?
	dynamic_cast<sf::RectangleShape*>(mShape)->setSize(NewShapeSize);
}

// Mouse released Function
void cRectangleTool::CompleteUseTool(sf::RenderTexture& CanvasTexture)
{
	// reset size on complete
	// Dynamic cast on update bad?
	dynamic_cast<sf::RectangleShape*>(mShape)->setSize(mRectSize);
}

void cRectangleTool::UpdateShape(sf::Vector2f mousePos)
{
	mShape->setPosition(mousePos);
}

