#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* p_next;
};

struct List{
    Node* p_head = NULL;
    Node* p_tail = NULL;
};

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->p_next = NULL;
}

void addHead(List* &list, int data){
    Node* node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = node;
    } else {
        node->p_next = list->p_head;
        list->p_head = node;
    }
}

void addTail(List* &list, int data){
    Node* node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = node;
    } else{
        list->p_tail->p_next = node;
        list->p_tail = node;
    }
}

void addBefore(List* &list, Node* node, int data){
    Node* new_node = createNode(data);
    Node* root = list->p_head;
    while(root!=NULL){
        if(root->p_next == node){
            new_node->p_next = root->p_next;
            root->p_next = new_node;
            break;
        }
        root = root->p_next;
    }
}

void printList(List* list){
    Node* root = list->p_head;
    while(root != NULL){
        cout << root->data << " ";
        root = root->p_next;
    }
    cout << endl;
}

void removeHead(List* &list){
    if(list->p_head == NULL){
        cout << "List is empty" << endl;
    } else {
        Node* temp = list->p_head;
        list->p_head = list->p_head->p_next;
        delete temp;
    }
}

void removeLast(List* &list){
    if(list->p_head == NULL){
        cout << "List is empty" << endl;
    } else {
        Node* temp = list->p_tail;
        Node* root = list->p_head;
        while(root!= NULL){
            if(root == temp){
                delete root;
                list->p_head = list->p_tail = NULL;
            }
            if(root->p_next == temp){
                list->p_tail = root;
                root->p_next = NULL;
                delete temp;
                break;
            }
            root = root->p_next;
        }
    }
}

void removeAll(List* &list){
    
}

int main(){
    List* list = new List;
    addTail(list, 0);
    addTail(list, 1);
    addTail(list, 2);
    printList(list);
    Node* temp = list->p_head;
    addHead(list, -1);
    printList(list);
    addBefore(list, temp, 11);
    printList(list);

    removeHead(list);
    printList(list);

    removeLast(list);
    printList(list);

    return 0;
}