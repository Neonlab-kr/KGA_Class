#include "Example_16_SingleLinkedList.h"
#include <iostream>

SLL::SLL() : phead(nullptr){}

SLL::~SLL()
{
	while (phead)
	{
		node* temp = phead;
		phead = phead->pNext;
		delete temp;
	}
}

void SLL::Insert(int num)
{
	node* newNode = new node(num);
	if (!phead)
	{
		phead = newNode;
	}
	else
	{
		node* temp = phead;
		while (temp->pNext)
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	node* pCurrent = phead;
	node* pNext = phead->pNext;
	if (pCurrent->value == num)
	{
		phead = pNext;
		delete pCurrent;
		return;
	}
	
	while (pNext->value != num)
	{
		pCurrent = pCurrent->pNext;
		pNext = pNext->pNext;

		if (pNext == nullptr) return;
	}
	pCurrent->pNext = pNext->pNext;
	delete pNext;

}

void SLL::Print()
{
	node* temp = phead;

	while (temp)
	{
		std::cout << temp->value << std::endl;
		temp = temp->pNext;
	}
}
