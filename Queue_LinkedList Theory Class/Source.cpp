#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
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

// Thêm phần tử vào Queue
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

// Lấy phần tử đầu tiên của Queue
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