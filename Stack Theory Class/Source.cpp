#include <iostream>
using namespace std;

struct Stack {
	int* StkArray;
	int StkMax;
	int StkTop;
};

Stack* createStack() {
	Stack* stk = new Stack;
	cout << "Input max:" << endl;
	cin >> stk->StkMax;
	stk->StkArray = new int[stk->StkMax];
	stk->StkTop = -1;
	return stk;
}

void push(Stack*& stk, int data) {
	if (stk->StkTop == stk->StkMax - 1) {
		cout << "Stack is Full" << endl;
	}
	else {
		if (stk->StkTop == -1) {
			stk->StkArray[0] = data;
			stk->StkTop = 0;
		}
		else {
			int pos = stk->StkTop + 1;
			stk->StkArray[pos] = data;
			stk->StkTop = pos;
		}
	}
}

int pop(Stack*& stk) {
	if (stk->StkTop == NULL) {
		return 0;
	}
	else {
		int data = stk->StkArray[stk->StkTop];
		stk->StkTop = stk->StkTop - 1;
		return data;
	}
}

void PrintStack(Stack* stk) {
	int n = stk->StkTop + 1;
	for (int i = 0; i < n; i++) {
		cout << stk->StkArray[i] << " ";
	}
	cout << endl << "--------------" << endl;
}

int main() {
	Stack* stk = createStack();
	cout << "Input key: " << endl;
	cout << "key = 1: Push" << endl;
	cout << "key = 2: Pop" << endl;
	cout << "key = 0: Exit" << endl;
	int key = 0;
	cin >> key;
	while (true) {
		if (key == 1) {
			cout << "Input data to push" << endl;
			int data;
			cin >> data;
			push(stk, data);
			PrintStack(stk);
		}
		if (key == 2) {
			cout << "Data is: " << pop(stk) << endl;
			PrintStack(stk);
		}
		if (key == 0) {
			break;
		}

		cout << "Input key: " << endl;
		cout << "key = 1: Push" << endl;
		cout << "key = 2: Pop" << endl;
		cout << "key = 0: Exit" << endl;
		cin >> key;
	}
	
	return 0;
}

//Khoi tao stack rong
//int InitStack(Stack& s, int MaxItems) {
//	s.StkArray = new int[MaxItems];
//	if (s.StkArray == NULL) {
//		return 0;
//	}
//	s.StkMax = MaxItems;
//	s.StkTop = -1;
//	return 1;
//}

// Kkiem tra stack rong
//int IsEmpty(const Stack& s) {
//	if (s.StkTop == -1) {
//		return 1;
//	}
//	return 0;
//}

// Kiem tra Stack day
//int IsFull(const Stack& s) {
//	if (s.StkTop == s.StkMax - 1) {
//		return 1;
//	} 
//	return 0;
//}

// Push
//init Push(Stack& s, int newitem) {
//	if (IsFull(s)) {
//		return 0;
//	}
//	s.StkTop++;
//	s.StkArray[s.StkTop] = newitem;
//	return 1;
//}