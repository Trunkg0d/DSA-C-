#include <iostream>
#include <string>
using namespace std;

struct NODE{
    char key;
    NODE* pNext;
};

struct Stack{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

NODE* createNode(char key){
    NODE* node = new NODE;
    node->key = key;
    node->pNext = NULL;
    return node;
}

void push(Stack* stack, char key){
    NODE* node = createNode(key);
    if(stack->p_head == NULL){
        stack->p_head = stack->p_tail = node;
    } else{
        node->pNext = stack->p_head;
        stack->p_head = node;
    }
}

char pop(Stack* stack){
    if(stack->p_head == NULL){
        cout << "Stack is empty!" << endl;
        return NULL;
    } else{
        NODE* p = stack->p_head;
        char data = stack->p_head->key;
        stack->p_head = p->pNext;
        p->pNext = NULL;
        delete p;
        return data;
    }
}

void printStack(Stack* stack){
    NODE* root = stack->p_head;
    while(root!=NULL){
        cout << root->key << " ";
        root = root->pNext;
    }
    cout << endl;
}

//////////////////////////////////////////////////

struct Queue{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

void enqueue(Queue* queue, char data){
    NODE* node = createNode(data);
    if(queue->p_head == NULL){
        queue->p_head = queue->p_tail = node;
    } else{
        queue->p_tail->pNext = node;
        queue->p_tail = node;
    }
}

char dequeue(Queue* queue){
    if(queue->p_head == NULL){
        cout << "Queue is empty" << endl;
        return 0;
    } else{
        NODE* p = queue->p_head;
        char data = p->key;
        queue->p_head = p->pNext;
        p->pNext = NULL;
        delete p;
        return data;
    }
}

void printQueue(Queue* queue){
    NODE* root = queue->p_head;
    while(root!=NULL){
        cout << root->key << " ";
        root = root->pNext;
    }
    cout << endl;
}

void ReverseString(string s, Stack* &stack){
    for(int i=0;i<s.length();i++){
        push(stack, s[i]);
    }
    NODE* p = stack->p_head;
    while(p!=NULL){
        cout << p->key;
        p = p->pNext;
    }
}

int main(){
    Stack* stack = new Stack;
    Queue* queue = new Queue;
    cout << "Input string: " << endl;
    string s="";
    getline(cin, s);
    ReverseString(s, stack);
    return 0;
}