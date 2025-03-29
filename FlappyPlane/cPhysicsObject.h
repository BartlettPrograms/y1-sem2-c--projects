#include "cGameObject.h"
#include "cUpdateable.h"

class cPhysicsObject : public cGameObject, cUpdateable
{
public:
protected:
	sf::Vector2f mVelocity;
};