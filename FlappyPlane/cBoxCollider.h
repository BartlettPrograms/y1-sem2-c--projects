#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cBoxCollider
{
public:
	cBoxCollider(sf::RectangleShape& bounds);
	~cBoxCollider();

	bool CheckCollision(cBoxCollider& other, float push);
	sf::Vector2f GetPosition() { return mBounds.getPosition(); }
	sf::Vector2f GetHalfSize() { return mBounds.getSize() / 2.0f; }
protected:
	sf::RectangleShape& mBounds;
};
