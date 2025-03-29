#pragma once
#include <iostream>

class cUpdateable
{
public:
	cUpdateable();
	~cUpdateable();
	virtual void Update(float DeltaSeconds) = 0;
private:

};