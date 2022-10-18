#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct Stack {
	Node* pTop;
};

bool IsEmpty(Stack S) {
	return (S.pTop == NULL);
}

int Top(Stack S)
{
	if (IsEmpty(S))
		return NULL;
	return S.pTop->data;
}

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

struct Queue
{
	Node* pHead, * pTail;
};

//Kiểm tra Queue rỗng
bool IsEmpty(Queue Q)
{
	return (Q.pHead == NULL);
}

//Xem dữ liệu phần tử đầu Queue, sử dụng giá trị đặc biệt NULLDATA để cho biết Queue rỗng
int Front(Queue Q)
{
	if (Q.pHead == NULL)
		return NULL;
	return Q.pHead->data;
}

void Enqueue(Queue& Q, Node* p)
{
	if (Q.pHead == NULL)
		Q.pHead = Q.pTail = p;
	else
	{
		Q.pTail->pNext = p;
		Q.pTail = p;
	}
}

int Dequeue(Queue& Q)
{
	Node* p = Q.pHead;
	if (Q.pHead == Q.pTail)
		Q.pHead = Q.pTail = NULL;
	else if (Q.pHead != NULL) {
		Q.pHead = p->pNext; p->pNext = NULL;
	}
	int data = p->data;
	delete p;
	return data;
}

int main() {
	return 0;
}