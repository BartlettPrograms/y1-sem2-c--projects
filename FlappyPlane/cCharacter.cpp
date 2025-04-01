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
	//mVelocity.y += mGravity * _DeltaSeconds; // gravity
	mPosition += mVelocity * _DeltaSeconds; // movement


	// Clamp position to not fall below ground && grounded reset
	if (mPosition.y > 768 - 30)
	{
		mPlayerAnimator.EndFall();
		mPosition.y = 768 - 30;
		mVelocity.y = 0;
		m_bGrounded = true;
	}

	// Clamp x position to keep player inside screen
	if (mPosition.x < 64)
	{
		mPosition.x = 64;
		mVelocity.x = 0;
	}
	else if (mPosition.x > 1302)
	{
		mPosition.x = 1302;
		mVelocity.x = 0;
	}

	// Clamp velocity to max velocity
	if (mVelocity.x > mMaxVelocity.x) { mVelocity.x = mMaxVelocity.x; }
	if (mVelocity.x < (-1 * mMaxVelocity.x)) { mVelocity.x = (-1 * mMaxVelocity.x); }
	if (mVelocity.y > mMaxVelocity.y) { mVelocity.y = mMaxVelocity.y; }
	if (mVelocity.y < (-1 * mMaxVelocity.y)) { mVelocity.y = (-1 * mMaxVelocity.y); }


	// Collider currently follows this objects position
	mBounds.position.x = mPosition.x;
	mBounds.position.y = mPosition.y;
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