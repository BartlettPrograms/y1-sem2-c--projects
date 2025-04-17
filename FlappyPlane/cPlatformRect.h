#pragma once
#include "cGameObject.h"
#include "cBoxCollider.h"
#include "cCharacter.h"

class cPlatformRect : public cGameObject, cBoxCollider
{
public:
	cPlatformRect(sf::FloatRect bounds);
	~cPlatformRect();

	void Draw(sf::RenderWindow& window) override;
	void Update(cCharacter& character);
	cBoxCollider& GetCollider() { return *this; };
	void EditorInitPosition();
private:
	sf::RectangleShape mBody;
};