#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;

  struct Node *left;
  struct Node *right;
} Node;

Node *insert(Node *root, int data);
void inorderTraversal(struct Node *root);
Node *search(Node *root, int data);

int main() {
  int i, arr[15], el = 59;
  int length = sizeof(arr) / sizeof(arr[0]);
  Node *root = NULL;

  for(i = 0; i < length; i++) {
    arr[i] = rand() % 100;
  }

  printf("Inserted: ");
  for(i = 0; i < length; i++) {
    root = insert(root, arr[i]);
    printf("%d, ", arr[i]);
  }

  printf("\nInorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  Node *temp = search(root, el);

  if(temp) {
    printf("\n{%d} found.\n", temp->data);
  } else {
    printf("\n{x} (%d) not found.\n", el);
  }

  return 0;
}

Node *insert(Node *root, int data) {
  Node *temp = (Node*) malloc(sizeof(Node));

  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL) {
    root = temp;
  } else {
    Node *current = root;
    Node *parent = NULL;

    while(1) {
      parent = current;

      if(data < parent->data) {
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

void inorderTraversal(struct Node *root) {
  if(root) {
    inorderTraversal(root->left);
    printf("%d, ", root->data);
    inorderTraversal(root->right);
  }
}

Node *search(Node *root, int data) {
  Node *current = root;
  printf("Visiting elements: ");

  while(current) {
    printf("%d, ", current->data);

    if(data < current->data) {
      current = current->left;
    } else if(data > current->data) {
      current = current->right;
    } else {
      return current;
    }
  } 
}