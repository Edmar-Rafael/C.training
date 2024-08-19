#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


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