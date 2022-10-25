#include<iostream>
#include<math.h>
using namespace std;

struct NODE{
    int key;
    NODE* p_next;
};

struct List{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

NODE* createNode(int data){
    NODE* node = new NODE;
    node->key = data;
    node->p_next = NULL;
}

List* addHead(List* &list, int data){
    NODE* node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = node;
    } else{
        node->p_next = list->p_head;
        list->p_head = node;
    }
}

List* addTail(List* &list, int data){
    NODE* node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = node;
    } else{
        list->p_tail->p_next = node;
        list->p_tail = node;
    }
}

void printList(List* list){
    NODE* root = list->p_head;
    while(root!=NULL){
        cout << root->key << " ";
        root = root->p_next;
    }
    cout << endl;
}

void reverseList(List* &list){
    NODE* root = list->p_head;
    List* temp = new List;
    while(root!=NULL){
        addHead(temp, root->key);
        root= root->p_next;
    }
    list = temp;
}

void deleteList(List* &list){
    NODE* root = list->p_head;
    while(root!=NULL){
        NODE* temp = root;
        root = root->p_next;
        delete temp;
    }
    list->p_head = list->p_tail = NULL;
}

void reverseGroup(List* &list, int k){
    int count = 0;
    List* temp_list = new List;
    NODE* root = list->p_head;
    List* temp = new List;
    while(root!=NULL){
        if(count < k){
            addHead(temp, root->key);
            count += 1;
            if (count == k || root->p_next == NULL){
                NODE* root1 = temp->p_head;
                while(root1 != NULL){
                    addTail(temp_list, root1->key);
                    root1 = root1->p_next;
                }
                deleteList(temp);
                count = 0;
            }
        }
        root = root->p_next;
    }
    list = temp_list;
}

struct Stack{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

void push(Stack* &stack, int data){
    NODE* node = createNode(data);
    if(stack->p_head == NULL){
        stack->p_head = stack->p_tail = node;
    } else{
        node->p_next = stack->p_head;
        stack->p_head = node;
    }
}

int pop(Stack* &stack){
    if(stack->p_head == NULL){
        cout << "Stack is empty!" << endl;
        return NULL;
    } else{
        NODE* temp = stack->p_head;
        stack->p_head = stack->p_head->p_next;
        int data = temp->key;
        delete temp;
        return data;
    }
}

void printStack(Stack* stack){
    NODE* root = stack->p_head;
    while(root!=NULL){
        cout << root->key << " ";
        root = root->p_next;
    }
    cout << endl;
}

struct Queue{
    NODE* p_head = NULL;
    NODE* p_tail = NULL;
};

void enqueue(Queue* &queue, int data){
    NODE* node = createNode(data);
    if(queue->p_head == NULL){
        queue->p_head = queue->p_tail = node;
    } else{
        queue->p_tail->p_next = node;
        queue->p_tail = node;
    }
}

int dequeue(Queue* queue){
    if(queue->p_head == NULL){
        cout << "Queue is empty" << endl;
        return NULL;
    } else {
        NODE* temp = queue->p_head;
        int data = temp->key;
        queue->p_head = queue->p_head->p_next;
        delete temp;
        return data;
    }
}

int convertDec(Queue* queue){
    NODE* root = queue->p_head;
    int dec = 0;
    int i=0;
    while(root != NULL){
        int num = 0;
        num = dequeue(queue);
        dec+=num*pow(2,i);
        i++;
        root = root->p_next;
        if(queue->p_head == NULL){
            break;
        }
    }
    return dec;
}

void printQueue(Queue* queue){
    NODE* root = queue->p_head;
    while(root!=NULL){
        cout << root->key << " ";
        root = root->p_next;
    }
    cout << endl;
}

int main(){
    Stack* stack = new Stack;
    Queue* queue = new Queue;
    enqueue(queue, 1);
    enqueue(queue, 0);
    enqueue(queue, 1);
    enqueue(queue, 0);
    printQueue(queue);
    cout << convertDec(queue);
    return 0;
}