#include "cPhysicsObject.h"

cPhysicsObject::cPhysicsObject(sf::FloatRect& bounds, sf::Vector2f _maxVelocity)
	: cBoxCollider(bounds)
	, mMaxVelocity(_maxVelocity)
{

}

cPhysicsObject::~cPhysicsObject()
{
}
