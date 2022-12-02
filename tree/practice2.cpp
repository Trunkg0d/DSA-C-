#include<iostream>
using namespace std;

struct NODE{
  int key;
  NODE* p_left;
  NODE* p_right;
  int height;
};

NODE* createNode(int data){
  NODE* node = new NODE;
  node->key = data;
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
    } else {
      return 1 + r;
    }
  }
}

NODE* rightRotate(NODE* root){
  NODE* x = root->p_left;

  root->p_left = x->p_right;
  x->p_right = root;

  x->height = Height(x);
  root->height = Height(root);

  return x;
}

NODE* leftRotate(NODE* root){
  NODE* x = root->p_right;

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
  }
  if(x < root->key){
    Insert(root->p_left, x);
  } else if(x > root->key){
    Insert(root->p_right, x);
  }

  root->height = Height(root);

  int balance = getBalance(root);

  // Left left case
  if(balance > 1 && x<root->p_left->key){
    root = rightRotate(root);
  }

  // Right right case
  if(balance < -1 && x>root->p_right->key){
    root = leftRotate(root);
  }

  // Left right case
  if(balance > 1 && x>root->p_left->key){
    root->p_left = leftRotate(root->p_left);
    root = rightRotate(root);
  }

  // Right left case
  if(balance < -1 && x<root->p_right->key){
    root->p_right = rightRotate(root->p_right);
    root = leftRotate(root);
  }
}

NODE* Search(NODE* &root, int x){
  if(root==NULL){
    return root;
  }
  if(root->key == x){
    return root;
  }
  if(x > root->key){
    return Search(root->p_right,x);
  }
  if(x < root->key){
    return Search(root->p_left,x);
  }
  return NULL;
}

NODE* MinRight(NODE* root){
  if(root == NULL){
    return NULL;
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

  if(x < root->key){
    root->p_left = Remove(root->p_left, x);
  }
  else if(x > root->key){
    root->p_right = Remove(root->p_right, x);
  } else {
    // node has no child
    if(root->p_left == NULL && root->p_right == NULL){
      return NULL;
    }
    // node has one child
    else if (root->p_left == NULL){
      NODE* temp = root->p_right;
      free(temp);
      return temp;
    } 
    else if (root->p_right == NULL){
      NODE* temp = root->p_left;
      free(temp);
      return temp;
    }

    NODE* temp = MinRight(root->p_right);
    root->key = temp->key;
    root->p_right = Remove(root->p_right, temp->key);
  }

  // Update height
  root->height = Height(root);
  // Get the balance
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

int main(){
    NODE *root = NULL;
  //            30
  //        /        \
  //      20          40
  //     /  \            \
  //   10    25           50
  //  /
  // 5
  Insert(root, 10);
  Insert(root, 20);
  Insert(root, 30);
  Insert(root, 40);
  Insert(root, 50);
  Insert(root, 25);
  Insert(root, 5);
  return 0;
}