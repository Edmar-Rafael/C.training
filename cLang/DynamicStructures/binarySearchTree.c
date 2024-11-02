#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node* insert(Node *root, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL) {
      root = newNode;
    } else {
      Node *current = root;
      Node *parent = NULL;

      while(1) {
        parent = current;

        if(val < parent->data) {
          current = current->left;

          if(current == NULL) {
            parent->left = newNode;
            return root;
          }
        } else {
          current = current->right;

          if(current == NULL) {
            parent->right = newNode;
            return root;
          }
        }
      }
    }

    return root;
  }

  printf("Memory allocation error...!");
  return NULL;
}

Node* search(Node *root, int val) {
  if(root) {
    printf("Visited: ");
    while(root) {
      printf("%d, ", root->data);

      if(val < root->data) {
        root = root->left;
      } else if(val > root->data) {
        root = root->right;
      } else {
        return root;
      }
    }
  }

  return NULL;
}

void clearTree(Node **root) {
  *root = NULL;
}

void treeLevelSwap(Node *root, int level, int k) {
  if(root == NULL || root->left == NULL || root->right == NULL) {
    return;
  }

  if((level + 1) % k == 0) {
    Node *aux = root->left;
    root->left = root->right;
    root->right = aux;
  }

  treeLevelSwap(root->left, level + 1, k);
  treeLevelSwap(root->right, level + 1, k);
}

void swapEveryLevel(Node *root, int k) {
  if(root) {
    treeLevelSwap(root, 1, k);
  } else {
    printf("Tree is empty.\n\n");
  }
}

void inorderTraversal(Node *root) {
  if(root) {
    inorderTraversal(root->left);
    printf("%d, ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(Node *root) {
  if(root) {
    printf("%d, ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(Node *root) {
  if(root) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d, ", root->data);
  }
}

int maximumDepth(Node *root) {
  if(root == NULL) {
    return -1;
  }

  int l = maximumDepth(root->left);
  int r = maximumDepth(root->right);

  return (l > r ? l : r) + 1;
}

int countNodes(Node *root) {
  
  return root == NULL ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
}

int countLeaves(Node *root) {
  if(root == NULL) {
    return 0;
  }

  if(root->left == NULL && root->right == NULL) {
    return 1;
  }

  return countLeaves(root->left) + countLeaves(root->right);
}

Node* deleteLeaves(Node *root) {
  if(!root) {
    return NULL;
  }

  if(!root->left && !root->right) {
    free(root);
    return NULL;
  }

  root->left = deleteLeaves(root->left);
  root->right = deleteLeaves(root->right);

  return root;
}

Node*deleteNode(Node *root, int key) {
  if(!root) {
    printf("Not found.\n");
    return NULL;
  }

  if(root->data == key) {
    Node *aux;

    if(!root->left && !root->right) {
      free(root);
      printf("Element removed: .\n");
      return NULL;
    } else if(root->left && root->right) {
      aux = root->left;

      while(aux->right) {
        aux = aux->right;
      }

      root->data = aux->data;
      aux->data = key;
      root->left = deleteNode(root->left, key);
      return root;
    } else {
      if(root->left) {
        aux = root->left;
      } else {
        aux = root->right;
      }

      free(root);
      printf("Node with one child removed.\n");
      return aux;
    }
  } else if(key < root->data) {
    root->left = deleteNode(root->left, key);
  } else {
    root->right = deleteNode(root->right, key);
  }

  return root;
}


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