#pragma once
#include "cLevelPlatformsList.h"
#include "cFileInterface.h"

class cApplicationManager
{
public:
	cApplicationManager();
	~cApplicationManager();
	// Getters
	bool IsLevelEditorRunning() { return mIsLevelEditorRunning; }
	bool IsGameRunning() { return mIsGameRunning; }
	bool IsMainMenuActive() { return mIsMainMenuActive; }
	// Setters
	void SetLevelEditorRunning(bool isRunning) { mIsLevelEditorRunning = isRunning; }
	void SetGameRunning(bool isRunning) { mIsGameRunning = isRunning; }
	void SetMainMenuActive(bool isActive) { mIsMainMenuActive = isActive; }

	static cApplicationManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new cApplicationManager();
		}
		return instance;
	}


private:
	bool mIsLevelEditorRunning = false;
	bool mIsGameRunning = false;
	bool mIsMainMenuActive = true;

	static cApplicationManager* instance;
};