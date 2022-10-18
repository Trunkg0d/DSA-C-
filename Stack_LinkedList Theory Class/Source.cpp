#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct Stack {
	Node* pTop;
};

void Push(Stack& S, Node* p)
{
	if (S.pTop == NULL)
		S.pTop = p;
	else
	{
		p->pNext = S.pTop;
		S.pTop = p;
	}
}

int Pop(Stack& S)
{
	Node* p = S.pTop;
	if (S.pTop != NULL)
	{
		S.pTop = p->pNext;
		p->pNext = NULL;
	}
	int data = p->data;
	delete p;
	return data;
}

int main() {
	return 0;
}