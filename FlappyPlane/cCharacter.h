#pragma once
#include "cPhysicsObject.h"
#include "cAnimator.h"

enum eCharacterType {
	TYPE_BLANK,
	TYPE_PLAYER,
	TYPE_ENEMY,
	TYPE_FRIEND,
	TYPE_NEUTRAL
};

class cCharacter : public cPhysicsObject
{
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
	void SetGrounded(bool isGrounded);

	// Collision
	cBoxCollider& GetCollider() { return mCollider; }
protected:
	eCharacterType mCharacterType;
	// Character Animator
	cAnimator mPlayerAnimator;
	// Physics members
	float mMoveInputMultGrounded = 0.8f;
	float mMoveInputMultAirborne = 0.3f;
	float mVelocityDampGrounded = 3;
	float mVelocityDampAirborne = .5;
	float mVelocityDeadzone = 15;
	// Character Movement
	bool m_bGrounded = false;
	float m_fJumpImpulse = 300;
	// Debug
	sf::RectangleShape mDebugColliderShape;
	sf::CircleShape mDebugPositionShape;
};