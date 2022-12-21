#include<iostream>
using namespace std;

struct NODE{
  int data;
  NODE* p_left = NULL;
  NODE* p_right = NULL;
};

NODE* createNode(int data){
  NODE* node = new NODE;
  node->data = data;
  node->p_left = NULL;
  node->p_right = NULL;
  return node;
}

void NLR(NODE* root){
  if(root){
    cout << root->data << " ";
    NLR(root->p_left);
    NLR(root->p_right);
  }
}

void LNR(NODE* root){
  if(root){
    LNR(root->p_left);
    cout << root->data << " ";
    LNR(root->p_right);
  }
}

void LRN(NODE* root){
  if(root){
    LRN(root->p_left);
    LRN(root->p_right);
    cout << root->data << " ";
  }
}

void Insert(NODE* &root, int data){
  if(root == NULL){
    root = createNode(data);
  } else {
    if(data < root->data){
      Insert(root->p_left, data);
    }
    if(data > root->data){
      Insert(root->p_right, data);
    }
  }
}

void createTree(int a[100], int &n, NODE* &root){
  cout << "Input n: ";
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    Insert(root, a[i]);
  }
}

int Height(NODE* root){
  if(root == NULL){
    return 0;
  } else{
    int l = Height(root->p_left);
    int r = Height(root->p_right);
    if(l > r){
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
    cout << root->data << " ";
  } else if (level > 1){
    printCurrentLevel(root->p_left, level - 1);
    printCurrentLevel(root->p_right, level - 1);
  }
}

void LevelOrder(NODE* root){
  for(int i=1; i<= Height(root); i++){
    cout << "Level " << i << ": " << endl;
    printCurrentLevel(root, i);
    cout << endl;
  }
  cout << endl;
}

NODE* Search(NODE* root, int data){
  if(root == NULL){
    return NULL;
  }
  if(root->data == data){
    return root;
  } 
  else {
    if(data < root->data){
      return Search(root->p_left, data);
    }
    if(data > root->data){
      return Search(root->p_right, data);
    }
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

NODE* MaxLeft(NODE* root){
  if(root == NULL){
    return NULL;
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
    return NULL;
  }
  if(x < root->data){
    root->p_left = Remove(root->p_left, x);
  } else if (x > root->data){
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
    root->data = temp->data;
    root->p_right = Remove(root->p_right, temp->data);
  }
  return root;
}

int countNode(NODE* root){
  if(root == NULL){
    return 0;
  } else{
    return 1 + countNode(root->p_right) + countNode(root->p_left);
  }
}

int sumNode(NODE* root){
  if(root == NULL){
    return 0;
  } else{
    return root->data + sumNode(root->p_right) + sumNode(root->p_left);
  }
}

int main(){
  NODE* root = NULL;
  int a[100], n=0;
  createTree(a, n, root);
  NLR(root);
  cout << endl;
  root = Remove(root, 5);
  NLR(root);
  cout << "Sum Node: " << sumNode(root) << endl;
  cout << "Count Node: " << countNode(root) << endl;
  return 0;
}