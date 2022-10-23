#include <iostream>
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
    Node* new_node = new Node;
    new_node->data = data;
    new_node->p_next = NULL;
    return new_node;
}

List* addHead(List* &list, int data){
    Node* new_node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = new_node;
    } else{
        new_node->p_next = list->p_head;
        list->p_head = new_node;
    }
}

List* addTail(List* &list, int data){
    Node* new_node = createNode(data);
    if(list->p_head == NULL){
        list->p_head = list->p_tail = new_node;
    } else{
        list->p_tail->p_next = new_node;
        list->p_tail = new_node;
    }
}

void addPos(List* &list, int data, int pos){
    Node* new_node = createNode(data);
    int real_pos = 0;
    Node* root = list->p_head;
    while(true){
        if(real_pos + 1 == pos && root!=NULL){
            new_node->p_next = root->p_next;
            root->p_next = new_node;
            break;
        }
        root = root->p_next;
        real_pos+=1;
        if(root == NULL){
            addTail(list, data);
            break;
        }
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

void removeHead(List* &list){
    if(list->p_head == NULL){
        cout << "List is empty" << endl;
    } else{
        Node* temp = list->p_head;
        list->p_head = temp->p_next;
        delete temp;
    }
}

void removeTail(List* &list){
    if(list->p_head == NULL){
        cout << "List is empty" << endl;
    } 
    else if(list->p_tail == list->p_head){
        removeHead(list);
    }
    else{
        Node* temp = list->p_tail;
        Node* root = list->p_head; 
        while(root != NULL){
            if(root->p_next == list->p_tail){
                root->p_next = NULL;
                list->p_tail = root;
                delete temp;
            }
            root = root->p_next;
        }
    }
}

void removePos(List* &list, int pos){
    int real_pos = 0;
    Node* root = list->p_head;
    if(pos==0){
        removeHead(list);
    } else{
        while(true){
        if(real_pos + 1 == pos){
            Node* temp = root->p_next;
            root->p_next = temp->p_next;
            delete temp;
            break;
        }
        root = root->p_next;
        real_pos+=1;
        if(root==NULL){
            cout << "Pos not found" << endl;
            break;
        }
    }
    }
}

void removeAll(List* &list){
    Node* root = list->p_head;
    while(root!=NULL){
        Node* temp = list->p_head;
        root=root->p_next;
        delete temp;
    }
    list->p_head = list->p_tail = NULL;
}

List* reverseList(List* list){
    List* newList = new List;
    Node* root = list->p_head;
    while(root!=NULL){
        addHead(newList, root->data);
        root=root->p_next;
    }
    return newList;
}

void removeDuplicate(List* &list){
	Node* root = list->p_head;
	Node* temp_root;
	while (root != NULL && root->p_next!=NULL) {
		temp_root = root;
		while (temp_root->p_next != NULL) {
			if (temp_root->p_next->data == root->data) {
				Node* dup = temp_root->p_next;
				temp_root->p_next = temp_root->p_next->p_next;
				free(dup);
			}
			else {
				temp_root = temp_root->p_next;
			}
		}
		root = root->p_next;
	}
}

void removeElement(List* &list, int key){
    List* newlist = new List;
    Node* root = list->p_head;
    while(root != NULL){
        if(root->data != key){
            addTail(newlist, root->data);
        }
        root = root->p_next;
    }
    list = newlist;
}

int main(){
    List* list = new List;
    addHead(list, 0);
    printList(list);
    addHead(list, 1);
    printList(list);
    addTail(list, 3);
    printList(list);
    addTail(list, 3);
    printList(list);
    removeElement(list, 3);
    printList(list);
    return 0;
}