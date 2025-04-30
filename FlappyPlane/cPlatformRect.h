#pragma once
#include "cGameObject.h"
#include "cBoxCollider.h"
#include "cCharacter.h"

class cPlatformRect : public cGameObject
{
private:
	sf::RectangleShape mBody;
	cBoxCollider mBoxCollider;
public:
	cPlatformRect(sf::FloatRect bounds);
	~cPlatformRect();

	void Draw(sf::RenderWindow& window) override;
	bool CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection);
	//bool CheckCollideWithPoint(sf::Vector2f* vPosition);
	cBoxCollider& GetCollider() { return mBoxCollider; };
	cBoxCollider GetColliderCopy() { return mBoxCollider; };
	void EditorInitPosition();
};