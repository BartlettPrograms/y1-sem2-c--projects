#include "cCharacter.h"

cCharacter::cCharacter(
	eCharacterType type, 
	sf::Vector2f position, 
	sf::FloatRect bounds,
	sf::Vector2f colliderOffset, 
	sf::Vector2f _maxVelocity)
	: cPhysicsObject(bounds, _maxVelocity)
	, mDebugColliderShape(bounds.size)
	, mDebugPositionShape(4)
	, mCharacterType(type)
{
	mDebugColliderShape.setOrigin(bounds.size / 2.0f);
	mDebugPositionShape.setOrigin(sf::Vector2f(2, 2));
	mColliderOffset = colliderOffset;
}

cCharacter::~cCharacter()
{
}

void cCharacter::CharacterPhysicsUpdate(float _DeltaSeconds)
{
	// Physics update
	if (!m_bGrounded) {
		mVelocity.y += mGravity * _DeltaSeconds; // gravity
	}
	mCollider.mBounds.position += mVelocity * _DeltaSeconds; // movement


	// Clamp position to not fall below ground && grounded reset
	if (mCollider.mBounds.position.y > 750)
	{
		mPlayerAnimator.EndFall();
		mCollider.mBounds.position.y = 750;
		mVelocity.y = 0;
		m_bGrounded = true;
	}

	// Clamp x position to keep player inside screen
	if (mCollider.mBounds.position.x < 64)
	{
		mCollider.mBounds.position.x = 64;
		mVelocity.x = 0;
	}
	else if (mCollider.mBounds.position.x > 1302)
	{
		mCollider.mBounds.position.x = 1302;
		mVelocity.x = 0;
	}

	// Clamp velocity to max velocity
	if (mVelocity.x > mMaxVelocity.x) { mVelocity.x = mMaxVelocity.x; }
	if (mVelocity.x < (-1 * mMaxVelocity.x)) { mVelocity.x = (-1 * mMaxVelocity.x); }
	if (mVelocity.y > mMaxVelocity.y) { mVelocity.y = mMaxVelocity.y; }
	if (mVelocity.y < (-1 * mMaxVelocity.y)) { mVelocity.y = (-1 * mMaxVelocity.y); }

	mPosition = mCollider.mBounds.position - mColliderOffset;
}


void cCharacter::DrawDebug(sf::RenderWindow& renderWindow)
{
	mDebugColliderShape.setPosition(mCollider.mBounds.position);
	mDebugPositionShape.setPosition(mPosition);
	renderWindow.draw(mDebugColliderShape); // draw collider
	renderWindow.draw(mDebugPositionShape); // draw player ground center
}

void cCharacter::SetGrounded(bool isGrounded)
{
	mPlayerAnimator.EndFall();
	mVelocity.y = 0;
	m_bGrounded = true;
}
