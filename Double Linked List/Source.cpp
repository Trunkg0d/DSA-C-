#include <iostream>
using namespace std;
struct DNode {
	int value;
	DNode* p_next;
	DNode* p_prev;
};

struct DList {
	DNode* p_head, * p_tail;
};

DNode* CreateNode(int value) {
	DNode* p = new DNode;
	p->p_next = p->p_prev = NULL;
	return p;
}

void AddFirst(DList& L, DNode* p) {
	if (L.p_head == NULL) {
		L.p_head = L.p_tail = p;
	}
	else {
		L.p_head->p_prev = p;
		p->p_next = L.p_head;
		L.p_head = p;
	}
}

void AddLast(DList& L, DNode* p) {
	if (L.p_head == NULL) {
		L.p_head = L.p_tail = p;
	}
	else {
		L.p_tail->p_next = p;
		p->p_prev = L.p_tail;
		L.p_tail = p;
	}
}

void AddBefore(DList& L, DNode* node, DNode* p) {
	if (node != NULL) {
		if (node == L.p_head) {
			AddFirst(L, p);
		}
		else {
			DNode* q = node->p_prev;
			p->p_prev = q;
			node->p_prev = q->p_next = p;
			p->p_next = node;
		}
	}
}

int main() {
	return 0;
}