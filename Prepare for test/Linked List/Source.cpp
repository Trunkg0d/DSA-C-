#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head = NULL;
	NODE* p_tail = NULL;
};

NODE* createNode(int key) {
	NODE* node = new NODE;
	node->key = key;
	node->p_next = NULL;
	return node;
}

void addTail(List*& list, int key) {
	NODE* node = createNode(key);
	if (list->p_head == NULL) {
		list->p_head = list->p_tail = node;
	}
	else {
		NODE* root = list->p_head;
		while (root != NULL) {
			if (root->p_next == NULL) {
				root->p_next = node;
				list->p_tail = node;
				break;
			}
			root = root->p_next;
		}
	}
}

void printList(List* list) {
	NODE* root = list->p_head;
	while (root != NULL) {
		cout << root->key << " ";
		root = root->p_next;
	}
	cout << endl;
}

List* ConcatList(List* L1, List* L2) {
	List* list3 = new List;
	NODE* root1 = L1->p_head;
	NODE* root2 = L2->p_head;
	while (root1 != NULL && root2 != NULL) {
		if (root1->key >= root2->key) {
			addTail(list3, root2->key);
			root2 = root2->p_next;
		}
		if (root1->key < root2->key) {
			addTail(list3, root1->key);
			root1 = root1->p_next;
		}
	}
	while (root1 != NULL) {
		addTail(list3, root1->key);
		root1 = root1->p_next;
	}
	while (root2 != NULL) {
		addTail(list3, root2->key);
		root2 = root2->p_next;
	}
	return list3;
}

void MergeList(List*& L1, List* L2) {
	List* list3 = new List;
	NODE* root1 = L1->p_head;
	NODE* root2 = L2->p_head;
	while (root1 != NULL && root2 != NULL) {
		if (root1->key >= root2->key) {
			addTail(list3, root2->key);
			root2 = root2->p_next;
		}
		if (root1->key < root2->key) {
			addTail(list3, root1->key);
			root1 = root1->p_next;
		}
	}
	while (root1 != NULL) {
		addTail(list3, root1->key);
		root1 = root1->p_next;
	}
	while (root2 != NULL) {
		addTail(list3, root2->key);
		root2 = root2->p_next;
	}
	L1 = list3;
}


int main() {
	List* list1 = new List;
	List* list2 = new List;
	addTail(list1, 5);
	addTail(list1, 12);
	addTail(list1, 23);
	addTail(list1, 34);
	addTail(list1, 67);
	printList(list1);

	addTail(list2, 6);
	addTail(list2, 20);
	addTail(list2, 34);
	addTail(list2, 34);
	addTail(list2, 55);
	addTail(list2, 78);
	addTail(list2, 90);
	printList(list2);

	List* list3 = new List;
	list3 = ConcatList(list1, list2);
	printList(list3);

	MergeList(list1, list2);
	printList(list1);
	return 0;
}