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

void Insert(NODE* &root, int x){
  if(root == NULL){
    root = createNode(x);
  } else {
    if(x < root->key){
      Insert(root->p_left, x);
    } else if (x > root->key){
      Insert(root->p_right, x);
    }
  }
}

void createTree(int a[100], int &n, NODE* &root){
  cout << "Input n: ";
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> a[i];
  }
  for(int i =0; i<n; i++){
    Insert(root, a[i]);
  }
}

int Height(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    int l = Height(root->p_left);
    int r = Height(root->p_right);
    if (l > r){
      return 1 + l;
    } else {
      return 1 + r;
    }
  }
}

void printCurrentLevel(NODE* root, int level){
  if(root == NULL){
    return;
  } 
  if(level == 1){
    cout << root->key << " ";
  } else if (level > 1){
    printCurrentLevel(root->p_left, level - 1);
    printCurrentLevel(root->p_right, level - 1);
  }
}

void levelOrder(NODE* root){
  for(int i = 1; i<= Height(root); i++){
    cout << "Level " << i << ": " << endl;
    printCurrentLevel(root, i);
    cout << endl;
  }
  cout << endl;
}

NODE* Search(NODE* root, int x){
  if(root == NULL){
    return NULL;
  }
  if(root->key == x){
    return root;
  } else {
    if(x < root->key){
      return Search(root->p_left, x);
    } else {
      return Search(root->p_right, x);
    }
  }
}

NODE* MinRight(NODE* root){
  if(root == NULL){
    return root;
  }
  if(root->p_left == NULL){
    return root;
  } else {
    return MinRight(root->p_left);
  }
}

NODE* MaxLeft(NODE* root){
  if(root == NULL){
    return root;
  }
  if(root->p_right == NULL){
    return root; 
  } else {
    return MaxLeft(root->p_right);
  }
}

NODE* Remove(NODE* &root, int x){
  if(Search(root, x) == NULL){
    return NULL;
  }

  if(root == NULL){
    return root;
  }

  if(x < root->key){
    root->p_left = Remove(root->p_left, x);
  } else if (x > root->key){
    root->p_right = Remove(root->p_right, x);
  } else {
    if(root->p_left == NULL && root->p_right == NULL){
      return NULL;
    } 
    else if(root->p_right == NULL){
      NODE* temp = root->p_left;
      free(root);
      return temp;
    }
    else if(root->p_left == NULL){
      NODE* temp = root->p_right;
      free(root);
      return temp;
    }

    NODE* temp = MinRight(root->p_right);
    root->key = temp->key;
    root->p_right = Remove(root->p_right, temp->key);
  }
}

int countNode(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    return 1 + countNode(root->p_right) + countNode(root->p_left);
  }
}

int sumNode(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    return root->key + sumNode(root->p_right) + sumNode(root->p_left);
  }
}

int heightNode(NODE* root, int x){
  NODE* target = Search(root, x);
  if(target != NULL){
    return Height(target);
  } else {
    return -1;
  }
}

int countLeaf(NODE* root){
  if(root == NULL){
    return 0;
  }
  if(root->p_left == NULL && root->p_right == NULL){
    return 1;
  } else {
    return countLeaf(root->p_right) + countLeaf(root->p_left);
  }
}

int countLess(NODE* root, int x){
  if(root == NULL){
    return 0;
  }
  if(root->key < x){
    return 1 + countLess(root->p_left, x) + countLess(root->p_right, x);
  } else {
    return countLess(root->p_right, x) + countLess(root->p_left, x);
  }
}

int countGreater(NODE* root, int x){
  if(root == NULL){
    return 0;
  }
  if(root->key > x){
    return 1 + countGreater(root->p_left, x) + countGreater(root->p_right, x);
  } else {
    return countGreater(root->p_right, x) + countGreater(root->p_left, x);
  }
}

bool isBST(NODE* root){
  if(root == NULL){
    return true;
  } 
  if(root->p_right != NULL && (root)->key < root->key){
    return false;
  }
  if(root->p_left != NULL && (root)->key > root->key){
    return false;
  }
  if(!isBST(root->p_left) && !isBST(root->p_right)){
    return false;
  }
  return true;
}

bool isFullBST(NODE* root){
  if(root == NULL){
    return true;
  } 
  if(root->p_right != NULL && root->p_left == NULL){
    return false;
  }
  if(root->p_left != NULL && root->p_right == NULL){
    return false;
  }
  if(root->p_right != NULL && (root)->key < root->key){
    return false;
  }
  if(root->p_left != NULL && (root)->key > root->key){
    return false;
  }
  if(!isFullBST(root->p_left) && !isFullBST(root->p_right)){
    return false;
  }
  return true;
}

void removeTree(NODE* &root){
  if(root){
    removeTree(root->p_left);
    removeTree(root->p_right);
    delete root;
  }
}

int main(){
  int a[100];
  int n;
  NODE* root = NULL;
  createTree(a, n, root);
  NLR(root);
  cout << endl;
  LNR(root);
  cout << endl;
  LRN(root);
  cout << endl;

  cout << Height(root) << endl;
  levelOrder(root);
  NODE* s = Search(root, 5);
  if(s == NULL){
    cout << "Not found" << endl;
  } else {
    cout << s->key << endl;
  }
  root = Remove(root, 7);
  NLR(root);
  cout << endl;
  cout << "Count node is: " << countNode(root) << endl;
  cout << "Sum node is: " << sumNode(root) << endl;
  cout << heightNode(root, 2) << endl;
  cout << "Count leaf is: " << countLeaf(root) << endl;
  cout << "Count less 7: " << countLess(root, 7) << endl;
  cout << "Count greater 7: " << countGreater(root, 7) << endl;
  cout << "Check BST: " << isBST(root) << endl;
  // cout << "Check Full BST: " << isFullBST(root) << endl;
  removeTree(root);
}
// 4
// 7
// 2
// 8
// 1
// 9
// 3
// 5
// 0
// 6