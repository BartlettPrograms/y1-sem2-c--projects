#pragma once
#include "cPlayerInput.h"
#include "cCharacter.h"

class cPlayerCharacter : public cCharacter
{
public:
	cPlayerCharacter(sf::Vector2f _position);
	~cPlayerCharacter();
	void Update(float DeltaSeconds);
	void Draw(sf::RenderWindow& renderWindow) override;
	void Jump();
	void HandleInput();
	// Collision
	cBoxCollider& GetCollider() { return *this; }

	// Player Values
	static const sf::Vector2f PLAYER_SIZE;
	static const sf::FloatRect PLAYER_BOUNDS;
	static const sf::Vector2f PLAYER_MAX_VELOCITY;
	static const sf::Vector2f PLAYER_COLLIDER_OFFSET;
private:
	// Player Input
	cPlayerInput mPlayerInput;
	sf::Vector2f m_vPlayerInputNormalized;
};