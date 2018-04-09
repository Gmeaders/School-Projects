/*
    Greg Meaders
    10/3/14
    Project 2
    Bad3.cpp
*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
  int key;
  int size;
  Node *left;
  Node *right;
  Node (int k) { key = k; size = 1; left = right = NULL; }
};

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

Node *insert(Node *T, int v, int r)
{
  if (T == NULL) return new Node(v);
  int rank_of_root = T->left ? T->left->size : 0;
  if (r <= rank_of_root) T->left = insert(T->left, v, r);
  else T->right = insert(T->right, v, r - rank_of_root - 1);
  fix_size(T);
  return T;
}

void split(Node *T, int r, Node **L, Node **R)
{
  
  if (T == NULL) {
    *L = NULL;
    *R = NULL;
    return;
  }
  if(r < T->key){
    split(T->left, r, L, &T->left);
    *R = T;
    }
  else{
    split(T->right, r, &T->right, R);
    *L = T;
    }
    fix_size(T);
}

Node *insert_random(Node *T, int v, int r)
{
  if (T == NULL) return new Node(v);
  if (rand() % (T->size + 1) == 0)
  {
    // insert at root
    Node *new_root = new Node(v);
    split(T, r, &new_root->left, &new_root->right);
    fix_size(new_root);
    return new_root;
  }
    int rank_of_root = T->left ? T->left->size : 0;
    if (r <= rank_of_root) T->left = insert(T->left, v, r);
    else T->right = insert(T->right, v, r - rank_of_root - 1);
    fix_size(T);
    return T;
  }  
 
void print_inorder(Node *T)
{
  if (T == NULL) return;
  print_inorder(T->left);
  cout << T->key << "\n";
  print_inorder(T->right);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Usage: bad3 <input size>\n";
    return 0;
  }

  int N = atoi(argv[1]);  // get first command-line argument
  if (N<1 || N>100000) {
    cout << "Invalid input size!\n";
    return 0;
  }
  cout << N << endl;
  int i;
  Node *T = NULL;
  
  for(i = N; i > 0; i--)
  {
    T = insert_random(T, i, 123456789 % (N - i + 1));
  }
  
  print_inorder(T);
  
  return 0;
}
