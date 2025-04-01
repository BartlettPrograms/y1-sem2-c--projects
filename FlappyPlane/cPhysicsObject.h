#include "cGameObject.h"
#include "cUpdateable.h"
#include "cBoxCollider.h"

class cUpdateable;

class cPhysicsObject : public cGameObject, public cUpdateable, public cBoxCollider
{
public:
	cPhysicsObject(sf::FloatRect& bounds, sf::Vector2f _maxVelocity);
	~cPhysicsObject();
	void SetMaxVelocity(sf::Vector2f _maxVelocity) { mMaxVelocity = _maxVelocity; }
protected:
	sf::Vector2f mVelocity;
	sf::Vector2f mMaxVelocity;
	float mGravity = 400;
};