#pragma once

struct node
{
	int value;
	node* pNext;

	node(int n) :value(n), pNext(nullptr) {}
};

class SLL
{
private:
	node* phead;

public:
	SLL();
	~SLL();

	void Insert(int num);
	void Delete(int num);
	void Print();
};