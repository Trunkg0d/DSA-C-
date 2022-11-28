#include<iostream>
using namespace std;

// Cây nhị phân là cây mỗi node có tối đa 2 node con
// Cây đầy đủ: Mỗi node đều có 2 con và các lá đều ở mức h
// Cây hoàn chỉnh: Từ mức h-1 trở lên đầy đủ, mức lá (mức h) các lá phải được thêm từ trái sang phải
// Cây cân bằng: 

struct NODE{
    int key;
    NODE* p_left = NULL;
    NODE* p_right = NULL;
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
  if(pRoot == NULL){
    return NULL;
  }
  if(x == pRoot->key){
      return pRoot;
  } else if (x < pRoot->key){
      return Search(pRoot->p_left, x);
  } else {
      return Search(pRoot->p_right, x);
  }
}

void Insert(NODE* &pRoot, int x){
  NODE* new_node = createNode(x);
  if(pRoot != NULL){
      if (x == pRoot->key){
      return;
      } 
      if(x < pRoot->key){
          Insert(pRoot->p_left, x);
      } else {
          Insert(pRoot->p_right, x);
      }
  } else {
      pRoot = new_node;
  }
}

NODE* MinRight(NODE* pRoot) {
  if (pRoot == NULL) {
      return NULL;
  }
  
  if (pRoot->p_left == NULL) {
      return pRoot;
  } else {
      return MinRight(pRoot->p_left);
  }
  
  return NULL;
}

NODE* MaxLeft(NODE* pRoot){
  if(pRoot == NULL){
    return NULL;
  }

  if(pRoot->p_right == NULL) {
    return pRoot;
  } else {
    return MaxLeft(pRoot->p_right);
  }

  return NULL;
}

// NODE* PreNode(NODE* pRoot, int x) {
//     if (pRoot->key == x) {
//         return NULL;
//     }
//     if (pRoot->p_right != NULL || pRoot->p_left != NULL) {
        
//         if (x > pRoot->key) {
            
//             if (pRoot->p_right->key == x) {
//                 return pRoot;
//             } else {
//                 return PreNode(pRoot->p_right, x);
//             }
//         }
//         if (x < pRoot->key) {
//             if (pRoot->p_left->key == x) {
//                 return pRoot;
//             } else {
//                 return PreNode(pRoot->p_left, x);
//             }
//         }
        
//     }
//     return NULL;
// }

NODE* Remove(NODE* pRoot, int key)
{
  if (pRoot == NULL)
    return pRoot;

  if (key < pRoot->key)
    pRoot->p_left = Remove(pRoot->p_left, key);

  else if (key > pRoot->key)
    pRoot->p_right = Remove(pRoot->p_right, key);

  else {
    // node has no child
    if (pRoot->p_left==NULL && pRoot->p_right==NULL)
        return NULL;
    
    // node with only one child or no child
    else if (pRoot->p_left == NULL) {
        NODE* temp = pRoot->p_right;
        free(pRoot);
        return temp;
    }
    else if (pRoot->p_right == NULL) {
        NODE* temp = pRoot->p_left;
        free(pRoot);
        return temp;
    }

    // node with two child
    NODE* temp = MinRight(pRoot->p_right);

    pRoot->key = temp->key;

    pRoot->p_right = Remove(pRoot->p_right, temp->key);
  }
  return pRoot;
}

NODE* createTree(int a[], int n) {
  NODE* pRoot = new NODE;
  pRoot = createNode(a[0]);
  for (int i = 1; i < n; i++) {
      Insert(pRoot, a[i]);
  }
  return pRoot;
}

int countNode(NODE* pRoot){
  if(pRoot == NULL){
      return 0;
  } else {
    int count_left = countNode(pRoot->p_left);
    int count_right = countNode(pRoot->p_right);
    return 1 + count_left + count_right;
  }
}

int sumNode(NODE* pRoot){
  if(pRoot == NULL){
    return 0;
  } else {
    int sum_left = sumNode(pRoot->p_left);
    int sum_right = sumNode(pRoot->p_right);
    return pRoot->key + sum_left + sum_right;
  }
}

int heightNode(NODE* pRoot, int value){
  NODE* target = Search(pRoot, value);
  if(target == NULL){
    return -1;
  }
  return height(target);
}

int countLeaf(NODE* pRoot){
  if(pRoot==NULL){
    return 0;
  } else if(pRoot->p_left == NULL && pRoot->p_right == NULL){
    return 1;
  } else {
    int l = countLeaf(pRoot->p_left);
    int r = countLeaf(pRoot->p_right);
    return l + r;
  }
}

int countLess(NODE* pRoot, int x){
  if(pRoot==NULL){
    return 0;
  } else if(pRoot->key < x){
    return 1 + countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
  } else {
    return countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
  }
}

int countGreater(NODE* pRoot, int x){
  if(pRoot == NULL){
    return 0;
  } else if (pRoot->key > x){
    return 1 + countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
  } else {
    countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
  }
}

bool isBST(NODE* pRoot){
  if(pRoot == NULL){
    return true;
  }

  if(pRoot->p_left != NULL && MaxLeft(pRoot->p_left)->key > pRoot->key){
    return false;
  }

  if(pRoot->p_right != NULL && MinRight(pRoot->p_right)->key < pRoot->key){
    return false;
  }

  if(!isBST(pRoot->p_left) && !isBST(pRoot->p_right)){
    return false;
  }
  return true;
}

//             5       
//        1          8
//      0   4     6     10
//                 7  9   11
//                         12
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
    cout << "NLR: ";
    NLR(root);
    cout << endl;
    cout << "LNR: ";
    LNR(root);
    cout << endl;
    cout << "LRN: ";
    LRN(root);
    cout << endl;

    cout << "Height: ";
    cout << height(root);
    cout << endl;

    cout << "LevelOrder: ";
    LevelOrder(root);
    cout << endl;

    Search(root, 9);

    cout << "Insert 7: ";
    Insert(root, 7);
    NLR(root);
    cout << endl;

    cout << "Remove 8: ";
    Remove(root, 8);
    NLR(root);
    cout << endl;

    cout << "Create tree from list: ";
    int a[10] = {4,7,2,8,1,9,3,5,0,6};
    int n = 10;
    NODE* root1 = createTree(a, n);
    NLR(root1);
    cout << endl;

    cout << "Count node: " << countNode(root1) << endl;
    cout << "Sum node: " << sumNode(root1) << endl;
    cout << endl;

    cout << heightNode(root, 9) << endl;
    cout << "Count leaf: " << countLeaf(root) << endl;
    cout << "Count less: " << countLess(root, 10) << endl;
    cout << "Count greater: " << countGreater(root, 10) << endl;
    return 0;
}