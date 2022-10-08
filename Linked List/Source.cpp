#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};

NODE* createNode(int data) {
	NODE* tmp = new NODE;
	tmp->key = data;
	tmp->p_next = NULL;
	return tmp;
}

List* createList(NODE* p_node) {
	List* list = new List;
	list->p_head = p_node;
	list->p_tail = p_node;
	return list;
}

void printLinkedList(NODE* root) {
	while (root != NULL) {
		cout << root->key << "->";
		root = root->p_next;
	}
	cout << "NULL" << endl;
}

void addHead(List* L, int data) {
	NODE* newnode = createNode(data);
	newnode->p_next = L->p_head;
	L->p_head = newnode;
}

void addTail(List* L, int data) {
	NODE* newnode = createNode(data);
	L->p_tail->p_next = newnode;
	L->p_tail = newnode;
}

void addPos(List* L, int data, int pos) {
	NODE* newnode = createNode(data);
	int real_pos = 0;
	NODE* root = L->p_head;
	int check = 0;
	while (real_pos < pos && root != NULL) {
		real_pos += 1;
		if (real_pos == pos) {
			break;
		}
		root = root->p_next;
	}
	if (root == NULL) {
		addTail(L, data);
	}
	else {
		newnode->p_next = root->p_next;
		root->p_next = newnode;
	}
}

void removeHead(List* L) {
	NODE* second_node = L->p_head->p_next;
	L->p_head = second_node;
	L->p_head->p_next = second_node->p_next;
}

void removeTail(List* L) {
	NODE* root = L->p_head;
	while (root != L->p_tail) {
		if (root->p_next == L->p_tail) {
			break;
		}
		root = root->p_next;
	}
	root->p_next = NULL;
}

void removePos(List* L, int pos) {
	NODE* root = L->p_head;
	NODE* left = new NODE;
	int real_pos = 0;
	while (real_pos < pos && root != NULL) {
		real_pos += 1;
		left = root;
		root = root->p_next;
		if (real_pos == pos) {
			break;
		}
	}
	left->p_next = root->p_next;
	root->p_next = NULL;
}

void removeAll(List* L) {
	L->p_head = NULL;
	L->p_tail = NULL;
}


int main() {
	NODE *firstNode;
	List *list;
	firstNode = createNode(0);																													
	list = createList(firstNode);
	printLinkedList(list->p_head);

	addHead(list, 1);
	printLinkedList(list->p_head);

	addTail(list, 100);
	printLinkedList(list->p_head);

	addPos(list, 2, 1);
	addPos(list, 3, 2);
	addPos(list, 10, 3);
	printLinkedList(list->p_head);

	removeHead(list);
	printLinkedList(list->p_head);

	removeTail(list);
	printLinkedList(list->p_head);

	removePos(list, 2);
	printLinkedList(list->p_head);

	removeAll(list);
	printLinkedList(list->p_head);
	return 0;
}