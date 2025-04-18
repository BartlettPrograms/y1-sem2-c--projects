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
	void Update(cCharacter& character, sf::Vector2f& collisionDirection);
	cBoxCollider& GetCollider() { return mBoxCollider; };
	void EditorInitPosition();
};