#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* p_next;
};

struct LIST {
	NODE* p_head;
	NODE* p_tail;
};

// LIST constructor method: create a null list
LIST* initList() {
	LIST* list = new LIST;
	list->p_head = NULL;
	list->p_tail = NULL;
	return list;
}


NODE* createNode(int data) {
	NODE* node = new NODE;
	node->data = data;
	node->p_next = NULL;
	return node;
}

LIST* createList(NODE* node) {
	LIST* list = new LIST;
	list->p_head = list->p_tail = node;
	return list;
}

void addHead(LIST* list, int data) {
	NODE* node = createNode(data);
	if (list->p_head == NULL) {
		list->p_head = list->p_tail = node;
	}
	else {
		node->p_next = list->p_head;
		list->p_head = node;
	}
}

void addTail(LIST* list, int data) {
	NODE* node = createNode(data);
	if (list->p_head == NULL) {
		list->p_head = node;
		list->p_tail = node;
	}
	else if (list->p_head!= NULL && list->p_tail == NULL) {
		list->p_tail = node;
	}
	else {
		list->p_tail->p_next = node;
		list->p_tail = node;
	}
}

void addPos(LIST* list, int data, int pos) {
	NODE* root = list->p_head;
	int real_pos = 0;
	NODE* newnode = createNode(data); 
	NODE* prev = new NODE;
	while (real_pos < pos && root != NULL) {
		real_pos += 1;
		prev = root;
		root = root->p_next;
		if (real_pos == pos) {
			break;
		}
	}
	if (root == NULL) {
		addTail(list, data);
	}
	else {
		prev->p_next = newnode;
		newnode->p_next = root;
	}
}

void removeHead(LIST* list) {
	if (list->p_head != NULL) {
		NODE* temp = list->p_head->p_next;
		list->p_head->p_next = NULL;
		list->p_head = temp;
	}
	else {
		cout << "LIST IS NULL, DON'T HAVE HEAD NODE" << endl;
	}
}

void removeTail(LIST* list) {
	if (list->p_head != NULL) {
		NODE* root = list->p_head;
		while (root != list->p_tail) {
			if (root->p_next == list->p_tail) {
				break;
			}
			root = root->p_next;
		}
		if (root == list->p_head && root->p_next == NULL) {
			list->p_head = NULL;
			list->p_tail = NULL;
		}
		else {
			root->p_next = NULL;
			list->p_tail = root;
		}
	}
	else {
		cout << "LIST IS NULL, DON'T HAVE TAIL NODE" << endl;
	}
}

void removePos(LIST* list, int pos) {
	NODE* root = list->p_head;
	NODE* prev = new NODE;
	if (list->p_head != NULL) {
		if (pos == 0) {
			removeHead(list);
		}
		else {
			int real_pos = 0;
			while (real_pos < pos && root != NULL) {
				prev = root;
				root = root->p_next;
				real_pos += 1;
				if (real_pos == pos || root == NULL) {
					break;
				}
			}
			prev->p_next = root->p_next;
		}
	}
	else {
		cout << "The List is Empty Now" << endl;
	}
}

void removeAll(LIST* list) {
	list->p_head = NULL;
	list->p_tail = NULL;
}

int countElements(LIST* list) {
	int count = 0;
	NODE* root = list->p_head;
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
	cout << "NULL";
	cout << endl;
}

int main() {
	LIST* list = initList();
	NODE* node;
	int key = 0;
	cout << "Input key: " << endl;
	cout << "key = 1: Add a node to the head of the list" << endl;
	cout << "key = 2: Add a node to the tail of the list" << endl;
	cout << "key = 3: Add a node to the pos" << endl;
	cout << "key = 4: Remove Head" << endl;
	cout << "key = 5: Remove Tail" << endl;
	cout << "key = 6: Remove Pos" << endl;
	cout << "key = 7: Remove All" << endl;
	cout << "key = 8: Count element in list" << endl;
	cin >> key;
	while (key != 0) {
		if (key == 1) {
			int data = 0;
			cout << "Input node data: " << endl;
			cin >> data;
			addHead(list, data);
			printList(list->p_head);
		}
		if (key == 2) {
			int data = 0;
			cout << "Input node data: " << endl;
			cin >> data;
			addTail(list, data);
			printList(list->p_head);
		}
		if (key == 3) {
			int data = 0;
			cout << "Input node data: " << endl;
			cin >> data;
			int pos = 0;
			cout << "Input position: " << endl;
			cin >> pos;
			addPos(list, data, pos);
			printList(list->p_head);
		}
		if (key == 4) {
			removeHead(list);
			printList(list->p_head);
		}
		if (key == 5) {
			removeTail(list);
			printList(list->p_head);
		}
		if (key == 6) {
			int pos = 0;
			cout << "Input delete position: " << endl;
			cin >> pos;
			removePos(list, pos);
			printList(list->p_head);
		}
		if (key == 7) {
			removeAll(list);
			printList(list->p_head);
		}
		if (key == 8) {
			cout << "Count: " << countElements(list) << endl;
		}
		cout << "Input key: " << endl;
		cout << "key = 1: Add a node to the head of the list" << endl;
		cout << "key = 2: Add a node to the tail of the list" << endl;
		cout << "key = 3: Add a node to the pos" << endl;
		cout << "key = 4: Remove Head" << endl;
		cout << "key = 5: Remove Tail" << endl;
		cout << "key = 6: Remove Pos" << endl;
		cout << "key = 7: Remove All" << endl;
		cout << "key = 8: Count element in list" << endl;
		cin >> key;
		if (key == 0) {
			break;
		}
	}
	return 0;
}