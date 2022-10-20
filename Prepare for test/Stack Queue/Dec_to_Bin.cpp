#include <iostream>
#include <string>
using namespace std;

struct NODE{
    int key;
    NODE* pNext;
};

struct Stack{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

NODE* createNode(int key){
    NODE* node = new NODE;
    node->key = key;
    node->pNext = NULL;
    return node;
}

void push(Stack* stack, int key){
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
        int data = stack->p_head->key;
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

void enqueue(Queue* queue, int data){
    NODE* node = createNode(data);
    if(queue->p_head == NULL){
        queue->p_head = queue->p_tail = node;
    } else{
        queue->p_tail->pNext = node;
        queue->p_tail = node;
    }
}

int dequeue(Queue* queue){
    if(queue->p_head == NULL){
        cout << "Queue is empty" << endl;
        return 0;
    } else{
        NODE* p = queue->p_head;
        int data = p->key;
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
//2/2 =1, 2-1*2 =0 -- 1/2 = 0, 1-0*2 = 1, -- 
void DecToBinR(int dec, Stack* stack){
    if(dec == 0){
        NODE* root = stack->p_head;
        while(root!=NULL){
            cout << root->key;
            root = root->pNext;
        }
        cout << endl;
    } else{
        int r = dec%2;
        push(stack, r);
        dec = dec/2;
        DecToBinR(dec, stack);
    }
}

int main(){
    Stack* stack = new Stack;
    Queue* queue = new Queue;
    int n=0;
    cout << "Input n: " << endl;
    cin >> n;
    DecToBinR(n, stack);
    return 0;
}