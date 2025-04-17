#include "cLevelPlatformsList.h"

cLevelPlatformsList::cLevelPlatformsList()
{

}

cLevelPlatformsList::~cLevelPlatformsList()
{
	ClearList();
}

void cLevelPlatformsList::AddPlatform(cPlatformRect* platform)
{
	std::cout << "Added platform to list" << std::endl;
	mPlatformList.push_back(platform);
}

void cLevelPlatformsList::DrawPlatforms(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i]->Draw(window);
	}
}

void cLevelPlatformsList::CheckCollisions(cPlayerCharacter& playerCharacter)
{
	for (size_t i = 0; i < mPlatformList.size(); ++i) {
		mPlatformList[i]->Update(playerCharacter);
	}
}

void cLevelPlatformsList::ClearList()
{
	// Delete each platform object and clear the vector
	for (cPlatformRect* platform : mPlatformList) {
		delete platform;
	}
	mPlatformList.clear();
}
