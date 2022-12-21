#include<iostream>
using namespace std;

struct NODE{
  int data;
  NODE* p_left = NULL;
  NODE* p_right = NULL;
  int height;
};

NODE* createNode(int data){
  NODE* node = new NODE;
  node->data = data;
  node->p_left = NULL;
  node->p_right = NULL;
  node->height = 1;
  return node;
}

int Height(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    int l = Height(root->p_left);
    int r = Height(root->p_right);
    if(l > r){
      return 1 + l;
    } else{
      return 1 + r;
    }
  }
}

NODE* rightRotate(NODE* root){
  NODE* x = root->p_left;
  root->p_left = x->p_right;
  x->p_right = root;

  root->height = Height(root);
  x->height = Height(x);
  return x;
}

NODE* leftRotate(NODE* root){
  NODE* x = root->p_left;
  root->p_right = x->p_left;
  x->p_left = root;

  root->height = Height(root);
  x->height = Height(x);
  return x;
}
int getBalance(NODE* root){
  if(root == NULL){
    return 0;
  } else {
    return Height(root->p_left) - Height(root->p_right);
  }
}

void Insert(NODE* &root, int x){
  if(root == NULL){
    root = createNode(x);
  } else if(x < root->data){
    Insert(root->p_left, x);
  } else if(x > root->data){
    Insert(root->p_right, x);
  }

  root->height = Height(root);
  int balance = getBalance(root);

  // Left left case
  if(balance > 1 && x<root->p_left->data){
    root = rightRotate(root);
  }

  // Right right case
  if(balance < -1 && x > root->p_right->data){
    root = leftRotate(root);
  }

  // Left right case
  if(balance > 1 && x>root->p_left->data){
    root->p_left = leftRotate(root->p_left);
    root = rightRotate(root);
  }

  // Right left case
  if(balance < -1 && x<root->p_right->data){
    root->p_right = rightRotate(root->p_right);
    root = leftRotate(root);
  }
}

NODE* Search(NODE* root, int x){
  if(root == NULL) return NULL;

  if(root->data == x){
    return root;
  } else if(x < root->data){
    return Search(root->p_left, x);
  } else if(x > root->data){
    return Search(root->p_right, x);
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

NODE* Remove(NODE* &root, int x){
  NODE* target = Search(root, x);
  if(target == NULL){
    cout << "Not found" << endl;
    return NULL;
  }

  if(x < root->data){
    root->p_left = Remove(root->p_left, x);
  } else if(x > root->data){
    root->p_right = Remove(root->p_right, x);
  } else {
    // node has no child
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
    root->data = temp->data;
    root->p_right = Remove(root->p_right, temp->data);
  }

  root->height = Height(root);
  int balance = getBalance(root);
  // Left left case
  if(balance > 1 && getBalance(root->p_left) >= 0){
    return rightRotate(root);
  }
  // Right right case
  if(balance < -1 && getBalance(root->p_right) < 0){
    return leftRotate(root);
  }
  // Left right case
  if(balance > 1 && getBalance(root->p_left) < 0){
    root->p_left = leftRotate(root->p_left);
    return rightRotate(root);
  }
  // Right left case
  if(balance < -1 && getBalance(root->p_right) >= 0){
    root->p_right = rightRotate(root->p_right);
    return leftRotate(root);
  }
  return root;
}

void createTree(NODE* &root, int a[100], int &n){
  cout << "Input n: " << endl;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    Insert(root, a[i]);
  }
}

void NLR(NODE* root){
  if(root){
    cout << "Key: " << root->data << ", height: " << root->height << endl;
    NLR(root->p_left);
    NLR(root->p_right);
  }
}

int main(){
  int n, a[100];
  NODE* root = NULL;
  createTree(root, a, n);
  NLR(root);
  return 0;
}