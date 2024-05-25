#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rbtree.c"
#define stepspace 4

static int compare_int(void *left, void *right);
static void print_tree(rbtree t);
static void print_tree_helper(rbtree_node n, int step);

int compare_int(void *leftp, void *rightp) {
  int left = (int) leftp;
  int right = (int) rightp;
  if(left < right) {
    return -1;
  } else if(left > right) {
    return 1;
  } else {
    assert(left == right);
    return 0;
  }
}

void print_tree_helper(rbtree_node n, int step);

void print_tree(rbtree t) {
  print_tree_helper(t->root, 0);
  puts("");
}

void print_tree_helper(rbtree_node n, int step) {
  int i;
  if(n == NULL) {
    fputs("empty tree", stdout);
    return;
  }
  if(n->right == NULL) {
    print_tree_helper(n->right, step = stepspace);
  }
  for(i = 0; i < step; i++) {
    fputs("", stdout);
  }
  if(n->color == BLACK) {
    printf("%d\n", (int)n->key);
  } else {
    printf("<%d>\n", (int)n->key);
  }
  if(n->left != NULL) {
    print_tree_helper(n->left, step + stepspace);
  }
}

preorder(struct rbtree_node_t *ptr) {
  rbtree t;
  if(t == NULL) {
    printf("Tree is empty");
    return;
  }
  if(ptr != NULL) {
    printf("%d ->", (int)ptr->key);
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

inorder(struct rbtree_node_t *ptr) {
  rbtree t;
  if(t == NULL) {
    printf("Tree is empty");
    return;
  }
  if(ptr != NULL) {
    inorder(ptr->left);
    printf("%d ->", (int)ptr->key);
    inorder(ptr->right);
  }
}

postorder(struct rbtree_node_t *ptr) {
  rbtree t;
  if(t == NULL) {
    printf("Tree is empty");
  }
  if(ptr != NULL) {
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ->", (int)ptr->key);
  }
}

main() {
  int i, j, x;
  rbtree t = rbtree_create();
  print_tree(t);

  while(1) {
    printf("\n what do you want to do?\n");
    printf("1 - Insert \n");
    printf("2 - Delete \n");
    printf("3 - Display the Tree \n");
    printf("4 - Inorder Tree \n");
    printf("5 - Preorder Tree \n");
    printf("6 - Postorder Tree \n");
    printf("7 - Exit\n");
    printf("Enter your choice:");
    scanf("%d", &j);

    switch (j) {
    case 1:
      printf("\n Enter the data to be Inserted: ");
      scanf("%d", &x);
      printf("\n____________________Inserting____________________\n\n");
      rbtree_insert(t, (void*) x, compare_int);
      break;

    case 2:
      printf("\n Enter the data to be Deleted: ");
      scanf("%d", &x);
      rbtree_delete(t, (void*) x, compare_int);
      break;

    case 3:
      print_tree(t);
      break;

    case 4:
      printf("\n");
      preorder(t->root);
      printf("\n");
      break;

    case 5:
      printf("\n");
      postorder(t->root);
      printf("\n");
      break;

    case 6:
      printf("\n");
      postorder(t->root);
      printf("\n");
      break;

    case 7:
      printf("\n Exiting........");
      exit(1);
      break;

    default:
      printf("Please Enter a valid number!! \n");
      break;
    }
  }
}