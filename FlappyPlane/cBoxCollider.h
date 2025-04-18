#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cBoxCollider
{
public:
	cBoxCollider(sf::FloatRect bounds);
	~cBoxCollider();

	void Move(float dx, float dy);

	bool CheckCollision(cBoxCollider& other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return mBounds.position; }
	sf::Vector2f GetHalfSize() { return mBounds.size / 2.0f; }
	sf::FloatRect mBounds;
private:
};
