#pragma once
#include <SFML/Graphics.hpp>
#include "cDrawable.h"

class cGameObject : public cDrawable
{
public:
protected:
	// Position
	sf::Vector2f mPosition;
	// Graphics
	sf::Texture mTexture;// Create texture from above
	sf::Sprite* mSprite; // create sprite from above
};