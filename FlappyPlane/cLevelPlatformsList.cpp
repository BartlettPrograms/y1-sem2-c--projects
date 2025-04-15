#include "cLevelPlatformsList.h"

cLevelPlatformsList::cLevelPlatformsList()
{

}

void cLevelPlatformsList::AddPlatform(cPlatformRect platform)
{
	mPlatformList.push_back(platform);
}

void cLevelPlatformsList::DrawPlatforms(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i].Draw(window);
	}
}
