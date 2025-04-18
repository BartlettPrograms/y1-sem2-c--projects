#pragma once
#include "cGameObject.h"
#include "cAnimator.h"
#include "cBoxCollider.h"

enum eCharacterType {
	TYPE_BLANK,
	TYPE_PLAYER,
	TYPE_ENEMY,
	TYPE_FRIEND,
	TYPE_NEUTRAL
};

class cCharacter
{
protected:
	eCharacterType mCharacterType;
	// Character Animator
	cAnimator mPlayerAnimator;
	// Physics members
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Vector2f mMaxVelocity;
	float mGravity = 300; // 9.81 * 16 // adjusted gravity for 16pixels = 1m
	// Dampen Movment
	float mMoveInputMultGrounded = 0.8f;
	float mMoveInputMultAirborne = 0.3f;
	float mVelocityDampGrounded = 3;
	float mVelocityDampAirborne = .5;
	float mVelocityDeadzone = 15;
	// Collision
	cBoxCollider mCollider;
	sf::Vector2f mColliderOffset;
	// Character Jumping
	bool m_bGrounded = false;
	float m_fJumpImpulse = 175;
	// Debug
	sf::RectangleShape mDebugColliderShape;
	sf::CircleShape mDebugPositionShape;
public:
	cCharacter(
		eCharacterType type, 
		sf::Vector2f position, 
		sf::FloatRect bounds,
		sf::Vector2f colliderOffset,
		sf::Vector2f _maxVelocity
	);
	~cCharacter();

	void CharacterPhysicsUpdate(float _DeltaSeconds);
	void DrawDebug(sf::RenderWindow& renderWindow);
	bool IsGrounded() const { return m_bGrounded; }
	void OnCollision(sf::Vector2f direction);

	// Collision
	cBoxCollider& GetCollider() { return mCollider; }
};