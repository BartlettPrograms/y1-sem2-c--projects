#pragma once
#include "cPlatformRect.h"
#include "cPlayerCharacter.h"
#include <vector>

class cLevelPlatformsList
{
	friend class cFileInterface;
public:
	cLevelPlatformsList();
	~cLevelPlatformsList();
	void AddPlatform(cPlatformRect* platform);
	void DrawPlatforms(sf::RenderWindow& window);
	void CheckCollisions(cPlayerCharacter& playerCharacter);
	void CheckCollisionWithPoint(sf::Vector2f* vPosition);
private:
	std::vector<cPlatformRect*> mPlatformList;
	sf::Vector2f mCollisionDirection;
	void ClearList();
};