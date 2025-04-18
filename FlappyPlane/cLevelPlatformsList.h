#pragma once
#include "cPlatformRect.h"
#include "cPlayerCharacter.h"
#include <vector>

class cLevelPlatformsList
{
public:
	cLevelPlatformsList();
	~cLevelPlatformsList();
	void AddPlatform(cPlatformRect* platform);
	void DrawPlatforms(sf::RenderWindow& window);
	void CheckCollisions(cPlayerCharacter& playerCharacter);
private:
	std::vector<cPlatformRect*> mPlatformList;
	sf::Vector2f mCollisionDirection;
	void ClearList();
};