#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node* insert(Node *root, int val) {
  Node *temp = (struct Node *) malloc(sizeof(struct Node));

  if(temp) {
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL) {
      root = temp;
    } else {
      Node *current = root;
      Node *parent = NULL;

      while(1) {
        parent = current;

        if(val < parent->data) {
          current = current->left;

          if(current == NULL) {
            parent->left = temp;
            return root;
          }
        } else {
          current = current->right;

          if(current == NULL) {
            parent->right = temp;
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

void inorderTraversal(Node *root) {
  if(root) {
    inorderTraversal(root->left);
    printf("%d, ", root->data);
    inorderTraversal(root->right);
  }
}

Node* search(Node *root, int val) {
  Node *current = root;
  printf("Visited: ");

  while(current) {
    printf("%d, ", current->data);

    if(val < current->data) {
      current = current->left;
    } else if(val > current->data) {
      current = current->right;
    } else {
      return current;
    }
  }
}

int main() {
  int i, arr[11], el = 43;
  int length = sizeof(arr) / sizeof(arr[0]);
  Node *root = NULL;

  printf("Inserted: ");
  for(i = 0; i < length; i++) {
    arr[i] = rand() % 100;
    root = insert(root, arr[i]);
    printf("%d, ", arr[i]);
  }

  printf("\nInorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  Node *aux = search(root, el);

  aux ? printf("\n{%d} found.\n", aux->data) : printf("\n(x) {%d} not found.\n", el);

  return 0;
}