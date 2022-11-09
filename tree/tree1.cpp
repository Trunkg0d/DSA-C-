#include<iostream>
using namespace std;

// Cây nhị phân là cây mỗi node có tối đa 2 node con
// Cây đầy đủ: Mỗi node đều có 2 con và các lá đều ở mức h
// Cây hoàn chỉnh: Từ mức h-1 trở lên đầy đủ, mức lá (mức h) các lá phải được thêm từ trái sang phải
// Cây cân bằng: 

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
};

NODE* createNode(int key){
    NODE* node = new NODE;
    node->key = key;
    node->p_left = NULL;
    node->p_right = NULL;
    return node;
}

struct Tree{
    NODE* root = NULL;
};

struct BSTNode{
    int data; //Một số code có trường này hoặc không có
    int key;
    BSTNode* left;
    BSTNode* right;
};

void NLR(NODE* root){
    if(root){
        cout << root->key << " ";
        NLR(root->p_left);
        NLR(root->p_right);
    }
}

void LNR(NODE* root){
    if(root){
        LNR(root->p_left);
        cout << root->key << " ";
        LNR(root->p_right);
    }
}

void LRN(NODE* root){
    if(root){
        LRN(root->p_left);
        LRN(root->p_right);
        cout << root->key << " ";
    }
}

int height(NODE* root)
{
    if (root == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(root->p_left);
        int rheight = height(root->p_right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(NODE* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        printCurrentLevel(root->p_left, level - 1);
        printCurrentLevel(root->p_right, level - 1);
    }
}

void LevelOrder(NODE* root){
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        printCurrentLevel(root, i);
    }
}

NODE* Search(NODE* pRoot, int x){
    if(x == pRoot->key){
        return pRoot;
    } else if (x < pRoot->key){
        Search(pRoot->p_left, x);
    } else {
        Search(pRoot->p_right, x);
    }
}

void Insert(NODE* &pRoot, int x){
    if (x > pRoot->key && pRoot->p_right == NULL){
        pRoot->p_right = createNode(x);
    } else if (x > pRoot->key){
        Insert(pRoot->p_right, x);
    }
    if (x < pRoot->key && pRoot->p_left == NULL){
        pRoot->p_left = createNode(x);
    } else if (x < pRoot->key){
        Insert(pRoot->p_left, x);
    }
}

//             5       
//        1         8
//      0   4     6   10
//                  9   11
//                        12
int main(){
    NODE* root = createNode(5);
    root->p_left = createNode(1);
    root->p_right = createNode(8);
    root->p_left->p_left = createNode(0);
    root->p_left->p_right = createNode(4);
    root->p_right->p_left = createNode(6);
    root->p_right->p_right = createNode(10);
    root->p_right->p_right->p_left = createNode(9);
    root->p_right->p_right->p_right = createNode(11);
    root->p_right->p_right->p_right->p_right = createNode(12);
    NLR(root);
    cout << endl;
    LNR(root);
    cout << endl;
    LRN(root);
    cout << endl;
    cout << height(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    Search(root, 9);
    return 0;
}