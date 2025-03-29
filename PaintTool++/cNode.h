/***********************************************************************
 Bachelor of Software Engineering
 Media Design School
 Auckland
 New Zealand
 (c)
 2025 Media Design School
 File Name : PaintTool++.exe
 Description : Budget paint tool
 Author : Matthew Bartlett
 Mail : matthew.bartlett@mds.ac.nz
 **************************************************************************/


#pragma once
#include <SFML/Graphics.hpp>

class Node
{
protected:
	int mKey;
	sf::RectangleShape m_PolygonLine; // You can get start position from 
	sf::Vector2f m_vfinalPosition;
	Node* mNext;

public:
	Node(int Key);
	~Node();
	int GetKey();
	sf::RectangleShape GetRect();
	sf::Vector2f GetFinalPosition();
	void SetRectangleShape(sf::RectangleShape _rect);
	void SetFinalPosition(sf::Vector2f Value);
	sf::Vector2f GetValue();
	void SetNext(Node* Next);
	Node* GetNext();
};