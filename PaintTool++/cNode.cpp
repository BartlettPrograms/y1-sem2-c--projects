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


#include "cNode.h"

Node::Node(int Key) : mKey(Key), m_PolygonLine(), m_vfinalPosition(sf::Vector2f(0, 0)), mNext(nullptr)
{
}

Node::~Node()
{
}

int Node::GetKey()
{
	return mKey;
}

sf::RectangleShape Node::GetRect()
{
	return m_PolygonLine;
}

sf::Vector2f Node::GetFinalPosition()
{
	return m_vfinalPosition;
}

void Node::SetRectangleShape(sf::RectangleShape _rect)
{
	m_PolygonLine = _rect;
}

void Node::SetFinalPosition(sf::Vector2f Value)
{
	m_vfinalPosition = Value;
}

sf::Vector2f Node::GetValue()
{
	return m_vfinalPosition;
}

void Node::SetNext(Node* Next)
{
	mNext = Next;
}

Node* Node::GetNext()
{
	return mNext;
}
