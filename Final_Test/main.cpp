#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> adj[1000];
int v, e;
bool used[1000];

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

bool isCompleteBST(NODE* root){
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
  if(!isCompleteBST(root->p_left) && !isCompleteBST(root->p_right)){
    return false;
  }
  return true;
}

void Input(){
  cin >> v >> e;
  for(int i = 0; i < e; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  memset(used, false, sizeof(used));
}

void Output(){
  for(int i = 0; i < v; i++){
    cout << "Dinh " << i << ": ";
    for(int v : adj[i]){
      cout << v << " ";
    }
    cout << endl;
  }
}
int parent[100];
void bfs(int u, int end){
  // Khoi tao va danh dau
  queue<int> q;
  q.push(u);
  used[u] = true;
  // Lap
  while(!q.empty()){
    int v = q.front();
    q.pop();
    cout << v << " ";
    if(v == end){
        break;
    }
    for(int x : adj[v]){
      if(!used[x]){
        q.push(x);
        used[x] = true;
      }
    }
  }
}

int main(){
    // NODE* root = NULL;
    // int a[100];
    // int n;
    // Insert(root, 33);
    // Insert(root, 14);
    // Insert(root, 15);
    // Insert(root, 92);
    // Insert(root, 64);
    // Insert(root, 35);
    // Insert(root, 79);
    // Insert(root, 27);
    // Insert(root, 38);
    // Insert(root, 105);
    // Insert(root, 99);
    // NLR(root);
    
    Input();
    Output();
    bfs(1, 3);
    return 0;
}