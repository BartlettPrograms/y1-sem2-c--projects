#pragma once
#include "cPhysicsObject.h"
#include "cPlayerInput.h"
#include "cAnimator.h"
#include "cBoxCollider.h"

class cPlayerCharacter : public cPhysicsObject, cBoxCollider
{
public:
	cPlayerCharacter();
	~cPlayerCharacter();
	void Update(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
	void Jump();
	void HandleInput();
	// Collision
	cBoxCollider& GetCollider() { return *this; }

	//Debug
	void DrawDebug(sf::RenderWindow& renderWindow);
private:
	// Player Input
	cPlayerInput mPlayerInput;
	sf::Vector2f m_vPlayerInputNormalized;
	// Collision
	sf::RectangleShape mBody;
	// Physics members
	float mGravity = 400;
	sf::Vector2f mMaxVelocity;
	float mMoveInputMultGrounded = 0.8;
	float mMoveInputMultAirborne = 0.3;
	float mVelocityDampGrounded = 3;
	float mVelocityDampAirborne = .5;
	float mVelocityDeadzone = 15;
	// Player Animator
	cAnimator mPlayerAnimator;
	//Player Movement
	bool m_bGrounded = true;
	float m_fJumpImpulse = 300;
	// Debug
	sf::CircleShape mDebugPositionShape;
};