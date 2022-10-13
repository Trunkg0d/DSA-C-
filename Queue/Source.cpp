#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* p_next;
};

struct QUEUE {
	NODE* p_head = NULL;
	NODE* p_tail = NULL;
};

NODE* createNode(int data) {
	NODE* node = new NODE;
	node->data = data;
	node->p_next = NULL;
	return node;
}

QUEUE* createQueue(int data) {
	QUEUE* queue = new QUEUE;
	NODE* node = new NODE;
	node = createNode(data);
	queue->p_head = queue->p_tail = node;
	return queue;
}

void enqueue(QUEUE*& queue, int data) {
	if (queue->p_head == NULL) {
		queue = createQueue(data);
	}
	else {
		NODE* node = createNode(data);
		queue->p_tail->p_next = node;
		node->p_next = NULL;
		queue->p_tail = node;
	}
}

int dequeue(QUEUE* queue) {
	if (queue->p_head == NULL) {
		cout << "THe queue is empty" << endl;
		return NULL;
	}
	else {
		NODE* rm = queue->p_head;
		queue->p_head = queue->p_head->p_next;
		int data = rm->data;
		free(rm);
		return data;
	}
}

int countElement(QUEUE* queue) {
	NODE* root = queue->p_head;
	int count = 0;
	while (root != NULL) {
		count += 1;
		root = root->p_next;
	}
	return count;
}

void printQueue(NODE* root) {
	while (root != NULL) {
		cout << root->data << "->";
		root = root->p_next;
	}
	cout << "NULL" << endl;
}

bool isNull(QUEUE* queue) {
	if (queue->p_head == NULL) {
		return true;
	}
	return false;
}

int main() {
	QUEUE* queue = new QUEUE;
	int key = 0;
	cout << "Input key: " << endl;
	cout << "key = 1: Enqueue " << endl;
	cout << "key = 2: Dequeue" << endl;
	cout << "key = 3: Count element" << endl;
	cout << "key = 4: Check null queue" << endl;
	cout << "key = 0: Exit" << endl;
	cin >> key;
	while (true) {
		if (key == 1) {
			int data = 0;
			cout << "Input data: " << endl;
			cin >> data;
			enqueue(queue, data);
			printQueue(queue->p_head);
		}
		if (key == 2) {
			cout << "Data is: " << dequeue(queue) << endl;
			printQueue(queue->p_head);
		}
		if (key == 3) {
			cout << "Count is: " << countElement(queue) << endl;
			cout << endl;
		}
		if (key == 4) {
			if (isNull(queue) == true) {
				cout << "The queue is null" << endl;
			}
			else {
				cout << "The queue not null" << endl;
			}
		}
		if (key == 0) {
			break;
		}
		cout << "Input key: " << endl;
		cout << "key = 1: Enqueue " << endl;
		cout << "key = 2: Dequeue" << endl;
		cout << "key = 3: Count element" << endl;
		cout << "key = 4: Check null queue" << endl;
		cout << "key = 0: Exit" << endl;
		cin >> key;
	}
	return 0;
}