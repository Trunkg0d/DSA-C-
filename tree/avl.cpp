#include <iostream>
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

int height(NODE* root){
  if(root==NULL){
    return 0;
  } else {
    int left_h = height(root->p_left);
    int right_h = height(root->p_right);
    if(left_h > right_h){
      return 1 + left_h;
    } else {
      return 1 + right_h;
    }
  }
}

NODE* rightRotate(NODE* root){
  NODE* x = root->p_left;

  root->p_left = x->p_right;
  x->p_right = root;

  root->height = height(root);
  x->height = height(x);

  return x;
}

NODE* leftRotate(NODE* root){
  NODE* x = root->p_right;

  root->p_right = x->p_left;
  x->p_left = root;

  root->height = height(root);
  x->height = height(x);

  return x;
}

int getBalance(NODE* root){
  if(root==NULL){
    return 0;
  } else {
    return height(root->p_left) - height(root->p_right);
  }
}

void Insert(NODE* &root, int x){
  if(root == NULL){
    root = createNode(x);
  }

  if(x < root->key){
    Insert(root->p_left, x);
  } else if (x > root->key){
    Insert(root->p_right, x);
  }

  root->height = height(root);

  int balance = getBalance(root);

  //Left left case
  if(balance > 1 && x < root->p_left->key){
    root = rightRotate(root);
  }

  // Right right case
  if(balance < -1 && x > root->p_right->key){
    root = leftRotate(root);
  }

  // Left right case
  if(balance > 1 && x > root->p_left->key){
    root->p_left = leftRotate(root->p_left);
    root = rightRotate(root);
  }

  // Right left case
  if(balance < -1 && x < root->p_right->key){
    root->p_right = rightRotate(root->p_right);
    root = leftRotate(root);
  }

}

void NLR(NODE* root){
  if(root){
    cout << "{key: " << root->key << ", height:  " << root->height << "}; ";
    NLR(root->p_left);
    NLR(root->p_right);
  }
}

void LNR(NODE* root){
  if(root){
    LNR(root->p_left);
    cout << "{key: " << root->key << ", height:  " << root->height << "}; ";
    LNR(root->p_right);
  }
}

void LRN(NODE* root){
  if(root){
    LRN(root->p_left);
    LRN(root->p_right);
    cout << "{key: " << root->key << ", height:  " << root->height << "}; ";
  }
}

NODE* Search(NODE* root, int x){
  if(root == NULL){
    return NULL;
  }
  if(root->key == x){
    return root;
  }
  if(x > root->key){
    return Search(root->p_right, x);
  }
  if(x < root->key){
    return Search(root->p_left, x);
  }
  return NULL;
}

NODE* minRight(NODE* root){
  if(root == NULL){
    return NULL;
  }
  if(root->p_left == NULL){
    return root;
  } else {
    return minRight(root->p_left);
  }
  return NULL;
}

NODE* maxLeft(NODE* root){
  if(root == NULL){
    return root;
  }
  if(root->p_right == NULL){
    return root;
  } else {
    return maxLeft(root->p_right);
  }
  return NULL;
}

NODE* Remove(NODE* &root, int x){
  NODE* target = Search(root, x);
  if(target == NULL){
    cout << "Not found" << endl;
    return NULL;
  } 
  if(x < root->key){
    root->p_left = Remove(root->p_left, x);
  } else if (x > root->key){
    root->p_right = Remove(root->p_right, x);
  } else {
    // node has no child
    if(root->p_left == NULL && root->p_right == NULL){
      return NULL;
    } else if (root->p_left == NULL){  // node with one right child
      NODE* temp = root->p_right;
      free(root);
      return temp;
    } else if (root->p_right == NULL){  // node with one left child
      NODE* temp = root->p_left;
      free(root);
      return temp;
    }
    // node with two child
    NODE* temp = maxLeft(root->p_left);
    root->key = temp->key;
    root->p_left = Remove(root->p_left, temp->key);
  }
  if(root == NULL){
    return root;
  }
  // Update height
  root->height = height(root);
  // Get the balance
  int balance = getBalance(root); 

  // Left Left Case 
  if (balance > 1 && getBalance(root->p_left) >= 0) 
      return rightRotate(root); 

  // Left Right Case 
  if (balance > 1 && getBalance(root->p_left) < 0) 
  { 
      root->p_left = leftRotate(root->p_left); 
      return rightRotate(root); 
  } 

  // Right Right Case 
  if (balance < -1 && getBalance(root->p_right) <= 0) 
      return leftRotate(root); 

  // Right Left Case 
  if (balance < -1 && getBalance(root->p_right) >= 0) 
  { 
      root->p_right = rightRotate(root->p_right); 
      return leftRotate(root); 
  } 
  return root;
}

void printCurrentLevel(NODE* root, int level){
  if(root==NULL){
    return;
  }
  if(level == 1){
    cout << "{key: " << root->key << ", height:  " << root->height << "}; ";
  } else {
    printCurrentLevel(root->p_left, level - 1);
    printCurrentLevel(root->p_right, level - 1);
  }
}

void LevelOrder(NODE* root){
  for(int i = 1; i<= height(root); i++){
    cout << "Level " << i << ": " << endl;
    printCurrentLevel(root, i);
    cout << endl;
  }
}

// bool isAVL(NODE* root){
//   if(root == NULL){
//     return true;
//   }
//   if(getBalance(root) > 1 || getBalance(root) < -1){
//     return false;
//   } else {
//     if (root->p_left != NULL && MaxLeft(root->p_left) > root->key){
//       return false;
//     }
//     if(root->p_right != NULL && MaxRight(root->p_left) < root->key){
//       return false;
//     }
//     if(!isAVL(root->p_left) && !isAVL(root->p_right)){
//       return false;
//     }
//     return true;
//   } 
// }

int main(){
  NODE *root = NULL;
  //            30
  //        /        \
  //      20          40
  //     /  \            \
  //   10    25           50
  //  /
  // 5
  Insert(root, 100);
  Insert(root, 70);
  Insert(root, 150);
  Insert(root, 90);
  Insert(root, 120);
  Insert(root, 180);
  Insert(root, 130);
  NLR(root);
  cout << endl;
  root = Remove(root, 100);
  NLR(root);
  cout << endl;
  LevelOrder(root);
  return 0;
}