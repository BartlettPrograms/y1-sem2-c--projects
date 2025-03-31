#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cBoxCollider
{
public:
	cBoxCollider(sf::FloatRect& bounds);
	~cBoxCollider();

	bool CheckCollision(cBoxCollider& other, float push);
	sf::Vector2f GetPosition() { return mBounds.position; }
	sf::Vector2f GetHalfSize() { return mBounds.size / 2.0f; }
protected:
	sf::FloatRect& mBounds;
};
