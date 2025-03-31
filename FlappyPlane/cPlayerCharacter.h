#pragma once
#include "cPlayerInput.h"
#include "cCharacter.h"

class cPlayerCharacter : public cCharacter
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
};