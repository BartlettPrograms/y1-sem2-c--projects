#include "cCharacter.h"

cCharacter::cCharacter(eCharacterType type, sf::FloatRect bounds, sf::Vector2f position, sf::Vector2f _maxVelocity)
	: cPhysicsObject(bounds, _maxVelocity)
	, mDebugColliderShape(bounds.size)
	, mDebugPositionShape(4)
	, mCharacterType(type)
{

}

cCharacter::~cCharacter()
{
}

void cCharacter::CharacterPhysicsUpdate()
{

}
