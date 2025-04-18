#include "cBoxCollider.h"

cBoxCollider::cBoxCollider(sf::FloatRect bounds)
	: mBounds(bounds)
{
	std::cout << "Collider Position x: " << mBounds.position.x << "  y: " << mBounds.position.y << std::endl;
	std::cout << "Collider size x: " << mBounds.size.x << "  y: " << mBounds.size.y << std::endl;
}

cBoxCollider::~cBoxCollider()
{
}

void cBoxCollider::Move(float dx, float dy)
{
	mBounds.position.x += dx;
	mBounds.position.y += dy;
}

bool cBoxCollider::CheckCollision(cBoxCollider& other, float push)
{
	//std::cout << "Collider x: " << mBounds.position.x << "  y: " << mBounds.position.y << std::endl;
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		std::cout << "Collision Detected!!" << std::endl;
		
		push = std::min(std::max(push, 0.0f), 1.0f);    /// COOL CLAMP CODE!!!

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}
