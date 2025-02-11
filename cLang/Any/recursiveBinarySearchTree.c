#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;

  struct Node *left;
  struct Node *right;
} Node;

Node* insert(Node *root, int val) {
  if(root == NULL) {
    Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
  }

  if(val < root->data) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
    
  return root;
}

void inorderTraversal(Node *root) {
  if(root) {
    inorderTraversal(root->left);
    printf("%d-> ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(Node *root) {
  if(root) {
    printf("%d-> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(Node *root) {
  if(root) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d-> ", root->data);
  }
}

int main() {
  int choice, val, arr[13];
  int length = sizeof(arr) / sizeof(arr[0]);
  char *m = "0 - Exit\n1 - Insert\n2 - Inorder\n3 - Preorder\n4 - Postorder\n\n";
  Node *root = NULL;

  do {
    printf("%s", m);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        printf("Type a number: ");
        scanf("%d", &val);
        root = insert(root, val);
      break;

      case 2:
        inorderTraversal(root);
        printf("\n\n");
      break;

      case 3:
        preorderTraversal(root);
        printf("\n\n");
      break;

      case 4:
        postorderTraversal(root);
        printf("\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("Good bye!!!\n\n");
    }
  }while(choice != 0);
  return 0;
}