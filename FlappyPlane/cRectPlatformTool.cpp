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
void cRectPlatformTool::CompleteUseTool(sf::RenderTexture& CanvasTexture)
{
	// reset size on complete
	// Dynamic cast on update bad?
	dynamic_cast<sf::RectangleShape*>(mShape)->setSize(mRectSize);
}

void cRectPlatformTool::UpdateShape(sf::Vector2f mousePos)
{
	mShape->setPosition(mousePos);
}

