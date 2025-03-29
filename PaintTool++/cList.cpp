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


#include "cList.h"

List::List() : mHead(nullptr), mNodeAmount(0)
{
}

// cList.cpp


List::~List() {
	while (mHead != nullptr) {
		Node* temp = mHead;
		mHead = mHead->GetNext();
		delete temp;
	}
}

void List::InsertHead(int Key, sf::RectangleShape _rect, sf::Vector2f Value)
{
	Node* newNode = new Node(Key);
	newNode->SetRectangleShape(_rect);
	newNode->SetFinalPosition(Value);
	newNode->SetNext(mHead);
	mHead = newNode;
	mNodeAmount++;
}

void List::InsertTail(int Key, sf::RectangleShape _rect, sf::Vector2f Value) {
	Node* newNode = new Node(Key);
	newNode->SetRectangleShape(_rect);
	newNode->SetFinalPosition(Value);
	newNode->SetNext(nullptr);

	if (mHead == nullptr) {
		mHead = newNode;
	}
	else {
		GetNode(mNodeAmount - 1)->SetNext(newNode);
	}
	mNodeAmount++;
}

void List::InsertBody(int Position, int Key, sf::RectangleShape _rect, sf::Vector2f Value) {
	if (Position <= 0 || mHead == nullptr) {
		InsertHead(Key, _rect, Value);
		return;
	}
	if (Position >= mNodeAmount) {
		InsertTail(Key, _rect, Value);
		return;
	}

	Node* newNode = new Node(Key);
	newNode->SetRectangleShape(_rect);
	newNode->SetFinalPosition(Value);
	Node* prev = GetNode(Position - 1);
	newNode->SetNext(prev->GetNext());
	prev->SetNext(newNode);
	mNodeAmount++;  // Missing in original
}

void List::DeleteHead()
{
	if (mHead == nullptr) {  // Check if list is empty
		return;              // Nothing to delete
	}
	Node* newHead = mHead->GetNext();
	delete mHead;
	mHead = newHead;
	mNodeAmount--;
}

void List::DeleteBody(int Position)
{
	GetNode(Position - 1)->SetNext(GetNode(Position + 1));
	delete GetNode(Position);
	mNodeAmount--;
}

void List::ClearList()
{
	while (mHead != nullptr) {
		Node* temp = mHead;
		mHead = mHead->GetNext();
		delete temp;
		mNodeAmount--;
	}
}

void List::DeleteTail() {
	if (mHead == nullptr) return;
	if (mNodeAmount == 1) {
		delete mHead;
		mHead = nullptr;
	}
	else {
		Node* secondLast = GetNode(mNodeAmount - 2);
		delete secondLast->GetNext();
		secondLast->SetNext(nullptr);
	}
	mNodeAmount--;
}

Node* List::GetNode(int Position)
{
	// Invalid position or empty list
	if (Position < 0 || mHead == nullptr) return nullptr;

	Node* currentNode = mHead;
	for (int i = 0; i < Position; i++) {
		if (currentNode == nullptr) {  // Reached end of list before position
			return nullptr;
		}
		currentNode = currentNode->GetNext();
	}
	return currentNode;
}

Node* List::FindNode(int Key)
{
	// Invalid position or empty list
	if (mHead == nullptr) return nullptr;

	Node* currentNode = mHead;
	while (currentNode != nullptr) {  // Traverse until end of list
		if (currentNode->GetKey() == Key) {  // Found the key
			return currentNode;
		}
		currentNode = currentNode->GetNext();
	}
	return nullptr; // Key not found
}

int List::NumNodes()
{
	return mNodeAmount;
}

bool List::NodeExists(int Key)
{
	if (FindNode(Key) != nullptr) return true;
	return false;
}