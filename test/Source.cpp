#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* p_next;
};

struct List {
    Node* p_head = NULL;
    Node* p_tail = NULL;
};

Node* createNode(int data) {
    Node* p = new Node;
    p->key = data;
    p->p_next = NULL;
    return p;
}

List* createList(Node*& p_node) {
    List* l = new List;
    l->p_head = p_node;
    l->p_tail = p_node;
    return l;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->key << " -> ";
        head = head->p_next;
    }
    cout << endl;
}

void addHead(List* L, int data) {
    Node* p = createNode(data);
    if (L->p_head == NULL) {
        L->p_head = L->p_tail = p;
    }
    else {
        p->p_next = L->p_head;
        L->p_head = p;
    }
}

void addTail(List* L, int data) {
    Node* p = createNode(data);
    if (L->p_head == NULL) {
        L->p_head = L->p_tail = p;
    }
    else {
        L->p_tail->p_next = p;
        L->p_tail = p;
    }
}

void addPos(List* L, int data, int pos) {
    Node* p = createNode(data);
    Node* n = L->p_head;
    int count = 0;
    // Node head = 0
    if (pos == 0) {
        addHead(L, p->key);
    }
    else {
        while (count < pos - 1) {
            if (n->p_next == NULL) {
                break;
            }
            n = n->p_next;
            count++;
        }
        p->p_next = n->p_next;
        n->p_next = p;
    }

}

void removeHead(List* L) {
    Node* p = L->p_head;
    L->p_head = p->p_next;
    delete p;
}

void removeTail(List* L) {
    Node* head = L->p_head;
    Node* tail = L->p_tail;
    while (head->p_next != tail) {
        head = head->p_next;
    }
    L->p_tail = head;
    delete tail;
}

void removePos(List* L, int pos) {
    if (pos == 0) {
        removeHead(L);
    }
    else {
        int count = 0;
        Node* n = L->p_head;
        while (count < pos - 1) {
            n = n->p_next;
            count++;
        }
        Node* p = n->p_next;
        n->p_next = p->p_next;
        delete p;
    }
}

void removeAll(List* L) {
    Node* p = L->p_head;
    while (p != NULL) {
        removeHead(L);
        p = p->p_next;
    }
}

void AddLast(Node*& p_head, Node* p) {
    if (p_head == NULL) {
        p_head = p;
    }
    else {
        AddLast(p_head->p_next, p);
    }
}

int countElement(List* L) {
    int count = 0;
    Node* p = L->p_head;
    while (p != NULL) {
        count++;
        p = p->p_next;
    }
    return count;
}

//List* reverseList(List* L) {
//    int lenL = countElement(L);
//    int count = 0;
//    Node* p = L->p_head;
//    while (count < lenL) {
//        addPos(L,p->key,lenL-count);
//        p = p->p_next;
//        removeHead(L);
//        count++;
//    }
//    return L;
//}

List* reverseList(List* L) {
    List* revL = new List;
    Node* p = L->p_head;
    while (p != NULL) {
        addHead(revL, p->key);
        p = p->p_next;
    }
    return revL;
}

int main() {
    Node* p = createNode(7);
    List* L = new List;
    addHead(L, 8);
    addHead(L, 3);
    addHead(L, 5);

    List* myList = new List;
    printList(L->p_head);
    myList = reverseList(L);
    printList(myList->p_head);
    return 0;
}