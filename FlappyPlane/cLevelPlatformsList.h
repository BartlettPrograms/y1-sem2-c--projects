#pragma once
#include "cPlatformRect.h"
#include <vector>

class cLevelPlatformsList
{
public:
	cLevelPlatformsList();
	void AddPlatform(cPlatformRect platform);
	void DrawPlatforms(sf::RenderWindow& window);
private:
	std::vector<cPlatformRect> mPlatformList;
};