#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cDrawable
{
public:
	cDrawable();
	~cDrawable();
	virtual void Draw(sf::RenderWindow& renderWindow) = 0;
private:

};