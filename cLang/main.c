#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"

int main() {
  int choice, val, key;
  char *m = "\n\t0 - Exit\n\t1 - Insert\n\t2 - search\n\t3 - Inorder tree\n\t4 - Preorder tree\n\t";
  char *m2 = "5 - Postorder tree\n\t6 - Tree height\n\t7 - Total of nodes\n\t8 - Clear\n\t";
  char *m3 = "9 - change position\n\t10 - Total of leaves\n\t11 - Delete leafs\n\t";
  char *m4 = "12 - Delete specific node\n\n\t";
  Node *el, *root = NULL;

  do {
    printf("\x1b[1;3;4;34m%s%s%s%s", m, m2, m3, m4);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        root = insert(root, val);
      break;

      case 2:
        printf("Choose an item to search: ");
        scanf("%d", &val);
        el = search(root, val);
        el ? printf("(%d) found.\n\n", el->data) : printf("{x} (%d) Not found.\n\n", val);
      break;

      case 3:
        root ? printf("Inorder: ") : printf("Tree is empty.\n\n");
        inorderTraversal(root);
      break;

      case 4:
        root ? printf("Preorder: ") : printf("Tree is empty.\n\n");
        preorderTraversal(root);
      break;

      case 5:
        root ? printf("Postorder: ") : printf("Tree is empty.\n\n");
        postorderTraversal(root);
      break;

      case 6:
        val = maximumDepth(root);
        val >= 0 ? printf("Tree height is: %d\n\n", val) : printf("Tree is empty.\n\n");
      break;

      case 7:
        val = countNodes(root);
        val ? printf("Tree have %d nodes.\n\n", val) : printf("Tree is empty.\n\n");
      break;

      case 8:
        clearTree(&root);
      break;

      case 9:
        swapEveryLevel(root, 2);
      break;

      case 10:
        val = countLeaves(root);
        val ? printf("Tree have %d leaves.\n\n", val) : printf("Tree is empty.\n\n");
      break;

      case 11:
        root = deleteLeaves(root);
        root ? printf("Leaves deleted.\n\n") : printf("Tree is empty.\n\n");
      break;

      case 12:
        printf("\x1b[1;3;4;32mType a number: ");
        scanf("%d", &val);
        root = deleteNode(root, val);
        root ? printf("%d\n\n", root->data) : printf("\x1b[1;3;4;31mCan't remove.\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("All good!");
    }
  } while(choice != 0);

  return 0;
}