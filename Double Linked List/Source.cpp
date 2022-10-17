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

// Them node p vao truoc node cho truoc
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

// Them node p vao sau node cho truoc
void AddAfter(DList& L, DNode* node, DNode* p) {
	if (node != NULL) {
		if (node == L.p_tail) {
			AddLast(L, p);
		}
		else {
			DNode* q = node->p_next;
			p->p_next = q;
			node->p_next = q->p_prev = p;
			p->p_prev = node;			
		}
	}
}

// Trich phan tu dau cua danh sach
DNode* PickFirst(DList& L) {
	DNode* p = L.p_head;
	if (L.p_head == L.p_tail) {
		L.p_head = L.p_tail = NULL;
	}
	else {
		L.p_head = L.p_head->p_next;
		L.p_head->p_prev = NULL;
		p->p_next = NULL;
	}
	return p;
}

// Trich phan tu cuoi danh sach
DNode* PickLast(DList& L) {
	DNode* p = L.p_tail;
	if (L.p_head == L.p_tail) {
		L.p_head = L.p_tail = NULL;
	}
	else {
		L.p_tail = L.p_tail->p_prev;
		L.p_tail->p_next = NULL;
		p->p_prev = NULL;
	}
	return p;
}

// Huy phan tu dau tien ra khoi danh sach
void RemoveFirst(DList& L) {
	DNode* p = PickFirst(L);
	delete p;
}

// Huy phan tu cuoi cung ra khoi danh sach
void RemoveLast(DList& L) {
	DNode* p = PickLast(L);
	delete p;
}

// Huy phan tu co gia tri xac dinh ra khoi danh sach
void Remove(DList& L, int value) {
	DNode* p = L.p_head;
	while (p != NULL && p->value != value) {
		p = p->p_next;
	}
	if (p == L.p_head) {
		RemoveFirst(L);
	}
	else if (p == L.p_tail) {
		RemoveLast(L);
	}
	else if (p != NULL) {
		p->p_next->p_prev = p->p_prev;
		p->p_prev->p_next = p->p_next;
		delete p;
	}
}

int main() {
	int a[] = { 1,2,3,4,5,6,7 };
	int n = 7;
	DList L = { NULL, NULL };
	for (int i = 0; i < n; i++) {
		DNode* p = CreateNode(a[i]);
		AddLast(L, p);
	}
	return 0;
}