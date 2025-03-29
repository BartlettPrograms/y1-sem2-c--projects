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
#include "cNode.h"

class List
{
private:
	Node* mHead;
	int mNodeAmount;
public:
	List();
	~List();
	void InsertHead(int Key, sf::RectangleShape _rect, sf::Vector2f Value);
	void InsertTail(int Key, sf::RectangleShape _rect, sf::Vector2f Value);
	void InsertBody(int Position, int Key, sf::RectangleShape _rect, sf::Vector2f Value);
	void DeleteHead();
	void DeleteTail();
	void DeleteBody(int Position);
	void ClearList();
	Node* GetNode(int Position);
	Node* FindNode(int Key);
	int NumNodes();
	bool NodeExists(int Key);
};