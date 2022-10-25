#include<iostream>
#include<string>
using namespace std;

struct Node{
    char data;
    Node* p_next;
};

struct List{
    Node* p_head = NULL;
    Node* p_tail = NULL;
};

Node* createNode(char data){
    Node* node = new Node;
    node->data = data;
    node->p_next = NULL;
    return node;
}

//Stack: last in first out
// add head
void push(List* &list, char data){
    Node* node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = node;
    } else {
        node->p_next = list->p_head;
        list->p_head = node;
    }
}

char pop(List* &list){
    if(list->p_head == NULL){
        cout << "List is empty" << endl;
        return NULL;
    } else {
        Node* temp = list->p_head;
        list->p_head = list->p_head->p_next;
        char data = temp->data;
        delete temp;
        return data;
    }
}

void printList(List* list){
    Node* root = list->p_head;
    while(root!=NULL){
        cout << root->data << " ";
        root = root->p_next;
    }
    cout << endl;
}

bool check1(string s){
    List* stack = new List;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            push(stack, s[i]);
        }
        if(s[i]==')'){
            if(stack->p_head == NULL){
                return false;
            } else {
                pop(stack);
            }            
        }
    }
    if(stack->p_head == NULL){
        return true;
    } else {
        return false;
    }
}

bool check2(string s){
    List* stack = new List;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '['){
            push(stack, s[i]);
        }
        if(s[i]==']'){
            if(stack->p_head == NULL){
                return false;
            } else {
                pop(stack);
            }            
        }
    }
    if(stack->p_head == NULL){
        return true;
    } else {
        return false;
    }
}

bool check3(string s){
    List* stack = new List;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{'){
            push(stack, s[i]);
        }
        if(s[i]=='}'){
            if(stack->p_head == NULL){
                return false;
            } else {
                pop(stack);
            }            
        }
    }
    if(stack->p_head == NULL){
        return true;
    } else {
        return false;
    }
}

void CheckBalance(string s){
    if(check1(s) == true && check2(s) == true && check3(s) == true){
        cout << "Balance" << endl;
    } else {
        cout << "Not balance" << endl;
    }
}

int main(){
    List* stack = new List;
    string s;
    cout << "Input s: " << endl;
    getline(cin, s);
    CheckBalance(s);
    return 0;
}