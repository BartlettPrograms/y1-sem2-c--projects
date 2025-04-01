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

void cCharacter::CharacterPhysicsUpdate(float _DeltaSeconds)
{
	// Physics update
	mVelocity.y += mGravity * _DeltaSeconds; // gravity
	mBounds.position += mVelocity * _DeltaSeconds; // movement


	// Clamp position to not fall below ground && grounded reset
	if (mBounds.position.y > 768 - 30)
	{
		mPlayerAnimator.EndFall();
		mBounds.position.y = 768 - 30;
		mVelocity.y = 0;
		m_bGrounded = true;
	}

	// Clamp x position to keep player inside screen
	if (mBounds.position.x < 64)
	{
		mBounds.position.x = 64;
		mVelocity.x = 0;
	}
	else if (mBounds.position.x > 1302)
	{
		mBounds.position.x = 1302;
		mVelocity.x = 0;
	}

	// Clamp velocity to max velocity
	if (mVelocity.x > mMaxVelocity.x) { mVelocity.x = mMaxVelocity.x; }
	if (mVelocity.x < (-1 * mMaxVelocity.x)) { mVelocity.x = (-1 * mMaxVelocity.x); }
	if (mVelocity.y > mMaxVelocity.y) { mVelocity.y = mMaxVelocity.y; }
	if (mVelocity.y < (-1 * mMaxVelocity.y)) { mVelocity.y = (-1 * mMaxVelocity.y); }


	// Position follows collider
	mPosition.x = mBounds.position.x;
	mPosition.y = mBounds.position.y;
}


void cCharacter::DrawDebug(sf::RenderWindow& renderWindow)
{
	//std::cout << "Collider Position x: " << mBounds.position.x << "  y: " << mBounds.position.y << std::endl;
	//std::cout << "Collider size x: " << mBounds.size.x << "  y: " << mBounds.size.y << std::endl;

	mDebugPositionShape.setPosition(mBounds.position);
	mDebugColliderShape.setPosition(mBounds.position);
	renderWindow.draw(mDebugColliderShape); // draw collider
	renderWindow.draw(mDebugPositionShape); // draw player ground center
}