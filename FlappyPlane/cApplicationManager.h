#pragma once

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
private:
	bool mIsLevelEditorRunning = false;
	bool mIsGameRunning = false;
	bool mIsMainMenuActive = true;
};



// Lazy singleton - this may be an "anti-pattern" but fk it I want to learn singletons rn
class cSingleton
{
protected:
	cSingleton() = default;

public:
	cApplicationManager AppManager;

	static cSingleton& GetInstance()
	{
		static cSingleton instance;
		return instance;
	}

	cSingleton(const cSingleton&) = delete;  // No copy constructors allowed
	cSingleton(cSingleton&&) = delete; // No move constructor allowed (I dont even know what that is yet)
	cSingleton& operator = (const cSingleton&) = delete; // Copy Assignment Operator allowed
	cSingleton& operator = (const cSingleton&&) = delete; // Move Assignment Operator allowed
};

