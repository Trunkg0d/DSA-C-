#include<iostream>
using namespace std;

struct NODE{
    int key;
    NODE* p_left = NULL;
    NODE* p_right = NULL;
};

NODE* createNode(int data){
    NODE* node = new NODE;
    node->key = data;
    node->p_left = NULL;
    node->p_right = NULL;
    return node;
}

void Insert(NODE* &root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    if(data < root->key){
        Insert(root->p_left, data);
    }
    if(data > root->key){
        Insert(root->p_right, data);
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

void createTree(int a[], int n, NODE* &root){
    for(int i = 0; i<n; i++){
        Insert(root, a[i]);
    }
}

int DataMaxBranch(NODE* root, int h){
  if(root == NULL || h == 0){
    return 0;
  } else {
    if(height(root->p_left) > height(root->p_right)){
      return root->key + DataMaxBranch(root->p_left, height(root->p_left));
    } else {
      return root->key + DataMaxBranch(root->p_right, height(root->p_right));
    }
  }
}

int maxData(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    if(maxData(root->p_left) > maxData(root->p_right)){
      return root->key + maxData(root->p_left);
    } else {
      return root->key + maxData(root->p_right);
    }
  }
}

void LNR(NODE* root){
    if(root){
        LNR(root->p_left);
        cout << root->key << " ";
        LNR(root->p_right);
    }
}

int main(){
    int a[10] = {4, 7, 2, 1, 3, 5, 0};
    int n = 7;
    NODE* root = NULL;
    createTree(a, 7, root);
    LNR(root);
    cout << endl;
    cout << DataMaxBranch(root, height(root)) << endl;
    cout << maxData(root) << endl;
    return 0;
}