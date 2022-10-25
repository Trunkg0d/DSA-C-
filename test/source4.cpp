#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* p_next;
};

struct Stack{
    Node* p_head = NULL;
    Node* p_tail = NULL;
};

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->p_next = NULL;
    return node;
}

void push(Stack* &stack, int data){
    Node* node = createNode(data);
    if(stack->p_head == NULL){
        stack->p_head = stack->p_tail = node;
    } else {
        node->p_next = stack->p_head;
        stack->p_head = node;
    }
}

int pop(Stack* stack){
    if(stack->p_head == NULL){
        return 0;
    } else {
        Node* temp = stack->p_head;
        stack->p_head = stack->p_head->p_next;
        int data = temp->data;
        delete temp;
        return data;
    }
}

void DecToBin(int dec){
    Stack* stack = new Stack;
    while(dec!=0){
        push(stack, dec%2);
        dec/=2;
    }
    while(true){
        if(stack->p_head == NULL){
            break;
        } else {
            cout << pop(stack);
        }
    }
}

void printStack(Stack* stack){
    Node* root = stack->p_head;
    while(root!=NULL){
        cout << root->data << " ";
        root = root->p_next;
    }
    cout << endl;
}

int main(){
    DecToBin(5);
    return 0;
}