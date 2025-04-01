#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class FileInterface
{
public:
	FileInterface();
	~FileInterface();
	void LoadFile(sf::RenderTexture* _Texture);
	void LoadStamp(sf::Texture* _Texture);
	void SaveFile(sf::RenderTexture* _Texture);

	void  DialogChooseColor(sf::Color& _Colour);
};