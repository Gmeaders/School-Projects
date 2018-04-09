#include "tree.h"

treenode_t *createNode(int key) {
  treenode_t *newNode = malloc(sizeof(treenode_t));
  newNode->key = key;
  newNode->value = 1;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}

int findNode(treenode_t *root, int searchkey) {
  if(root == NULL) return -1;
  if(root->key == searchkey) {
    root->value++;
    return 1;
  }
  if(root->key > searchkey) {
    if(findNode(root->lchild, searchkey) == -1) {
      treenode_t *newNode = createNode(searchkey);
      root->lchild = newNode;
    }
  }
  else {
    if(findNode(root->rchild, searchkey) == -1) {
      treenode_t *newNode = createNode(searchkey);
      root->rchild = newNode;
    }
  }
  return 1;
}


void inorder(treenode_t *root) {
  //prints in order. All of the left children for a node, and then all of the right
  //first check to see if tree is empty; i.e. root == NULL
  
	if(root == NULL)
	{
		return;
	}
  	
	inorder(root->lchild);
	printf("%8d%8d\n", root->key, root->value);
	inorder(root->rchild);		
}

void preorder(treenode_t *root, int rd) {
  //check for root = NULL, return
  //rd = root depth, each level gets an extra "-"
  //print the key, all the left children, all the right children
  //don't forget to increment the rd each time you go to another child!
	
	if(root == NULL)
	{
		return;
	}	

	int i;
	for(i = 0; i < rd; ++i)
	{
		printf("-");
	}

	printf("%4d\n", root->key);
	preorder(root->lchild, rd + 1);
	preorder(root->rchild, rd + 1);
	


  
}

void postorder(treenode_t *root) {
 //check for root == NULL, return
 //print out all the left, followed by all the right
	
	if(root == NULL)
	{
		return;
	}

	postorder(root->lchild);
	postorder(root->rchild);	
	printf("%8d%8d\n", root->key, root->value);
	
}










