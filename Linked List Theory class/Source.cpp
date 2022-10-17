#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

Node* createNode(int value) {
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;
	return p;
}

void AddFirst(Node*& pHead, Node* p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		p->pNext = pHead;
	}
}

void AddLast(Node*& pHead, Node* p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		AddLast(pHead->pNext, p);
	}
}

void AddBefore(Node*& pHead, Node* node, Node* p) {
	if (pHead == node) {
		AddFirst(pHead, p);
	}
	else if (pHead->pNext == node) {
		p->pNext = node;
		pHead->pNext = p;
	}
	else {
		AddBefore(pHead->pNext, node, p);
	}
}

Node* PickFirst(Node*& pHead) {
	Node* p = pHead;
	if (pHead != NULL) {
		pHead = p->pNext;
		p->pNext = NULL;
	}
	return p;
}

Node* PickLast(Node*& pHead) {
	if (pHead == NULL)
		return NULL;
	if (pHead->pNext == NULL) {
		Node* p = pHead;
		pHead = NULL;
		return p;
	}
	return PickLast(pHead->pNext);
}

void RemoveLast(Node*& pHead) {
	Node* p = PickLast(pHead);
	delete p;
}

void RemoveFirst(Node*& pHead) {
	Node* p = PickFirst(pHead);
	delete p;
}

void Remove(Node*& pHead, int value) {
	if (pHead != NULL) {
		if (pHead->data == value) {
			RemoveFirst(pHead);
		}
		else {
			Remove(pHead->pNext, value);
		}
	}
}

void PrintList(Node*& pHead) {
	if (pHead != NULL) {
		cout << pHead->data << " ";
		PrintList(pHead->pNext);
	}
}

void PrintReverseList(Node* pHead) {
	if (pHead != NULL) {
		PrintReverseList(pHead->pNext);
		cout << pHead->data << " ";
	}
}

void RemoveList(Node* pHead) {
	while (pHead != NULL) {
		Node* p = pHead;
		pHead = pHead->pNext;
		delete p;
	}
}

//Huy tat ca phan tu co gia tri trung voi gia tri duoc cho truoc
void RemoveAll(Node*& pHead, int value) {
	if (pHead != NULL) {
		if (pHead->data == value) {
			RemoveFirst(pHead);
			RemoveAll(pHead, value);
		}
		else {
			RemoveAll(pHead->pNext, value);
		}
	}
}

//Duyet danh sach

int main() {
	return 0;
}