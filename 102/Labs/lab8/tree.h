#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct nodeType {
   int key;                      /* key (the integer here)  */
   int value;                    /* Occurrence count (value)*/
   struct nodeType *lchild;      /* Pointer to left branch  */
   struct nodeType *rchild;      /* Pointer to right branch */
} treenode_t;

/* Prototype statements */
treenode_t *createNode(int value);
int findNode(treenode_t *root, int value);
void inorder(treenode_t *root);
void preorder(treenode_t *root, int rd);
void postorder(treenode_t *root);

