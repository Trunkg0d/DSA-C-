#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* p_next;
};

struct LIST {
	NODE* p_head = NULL;
	NODE* p_tail = NULL;
};

NODE* createNode(int data) {
	NODE* node = new NODE;
	node->data = data;
	node->p_next = NULL;
	return node;
}

LIST* createList(int data) {
	NODE* node = new NODE;
	node = createNode(data);
	LIST* list = new LIST;
	list->p_head = list->p_tail = node;
	return list;
}

void push(LIST* &list, int data) {
	if (list->p_head == NULL) {
		list = createList(data);
	}
	else {
		NODE* node = createNode(data);
		node->p_next = list->p_head;
		list->p_head = node;
	}
	
}

int pop(LIST* list) {
	if (list->p_head != NULL) {
		NODE* rm = list->p_head;
		list->p_head = list->p_head->p_next;
		int data = rm->data;
		free(rm);
		return data;
	}
	else {
		return NULL;
	}
}

int countElement(LIST* list) {
	NODE* root = list->p_head;
	int count = 0;
	while (root != NULL) {
		count += 1;
		root = root->p_next;
	}
	return count;
}



void printList(NODE* root) {
	while (root != NULL) {
		cout << root->data << "->";
		root = root->p_next;
	}
	cout << "NULL" << endl;
}

int main() {
	LIST* list = new LIST;
	int key = 0;
	cout << "key = 1: Push" << endl;
	cout << "key = 2: Pop" << endl;
	cout << "key = 3: Count element" << endl;
	cout << "Input key: " << endl;
	cin >> key;
	while (true) {
		if (key == 1) {
			int data;
			cout << "Input data: " << endl;
			cin >> data;
			push(list, data);
			printList(list->p_head);
		}
		if (key == 2) {
			cout << "Data is: " <<  pop(list) << endl;
			printList(list->p_head);
		}
		if (key == 3) {
			cout << "Length of stack: " << countElement(list) << endl;
			cout << endl;
		}
		if (key == 0) {
			break;
		}
		cout << "key = 1: Push" << endl;
		cout << "key = 2: Pop" << endl;
		cout << "key = 3: Count element" << endl;
		cout << "Input key: " << endl;
		cin >> key;
	}
	return 0;
}