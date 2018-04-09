#include "tree.h"

int main() {
   treenode_t *root = NULL;
   int vals[] = {5,10,2,1,3,3,11,1,10,15,9,3,10,10,9,11,15,10,3,
                 -1};
   int ndx=0;

   while (vals[ndx] >= 0) {
      if (findNode(root, vals[ndx]) == -1) {
         /* Special case when tree is empty */
         root = createNode(vals[ndx]);
      }
      ndx++;
   }
 
   fprintf(stdout,"*****************Results***************** \n");
   fprintf(stdout, "Sorted list of numbers (ascending order):\n");
   fprintf(stdout, "%8s%8s\n","Number","Count");
   inorder(root);

   fprintf(stdout, "list of numbers in pre order traversal:\n");
   preorder(root, 1);

   fprintf(stdout, "list of numbers in post order traversal:\n");
   fprintf(stdout, "%8s%8s\n","Number","Count");
   postorder(root);

   exit(0);
}

