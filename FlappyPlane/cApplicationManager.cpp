#include "cApplicationManager.h"

cApplicationManager::cApplicationManager(cFileInterface& fileInterface, cLevelPlatformsList& platformList)
	: mFileInterface(fileInterface)
	, mPlatformList(platformList)
{

}

cApplicationManager::~cApplicationManager() 
{

}

void cApplicationManager::LoadLevel()
{
	mFileInterface.LoadLevelByName("levelTest1.json", mPlatformList);
}
