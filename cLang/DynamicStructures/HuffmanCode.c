#include <stdio.h>
#include <stdlib.h>
#include "../String/stringCopy.c"
#include "../String/stringConcat.c"
#include "../String/stringLen.c"

#define LENGTH 256

typedef struct Node {
  int frequence;
  unsigned char character;
  struct Node *next;
  struct Node *left, *right;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;

void frequenceTableInit(unsigned int t[]) {
  for(int i = 0; i < LENGTH; i++) {
    t[i] = 0;
  }
}

void frequenceTableFill(unsigned char str[], unsigned int t[]) {
  int i = 0;

  while(str[i] != '\0') {
    t[str[i]]++;
    i++;
  }
}

void frequenceTablePrint(unsigned int t[]) {
  for(int i = 0; i < LENGTH; i++) {
    if(t[i] != 0) {
      printf("%3d - %u = %c\n", i, t[i], i);
    }
  }
  printf("\n");
}

void listInit(List *list) {
  list->head = NULL;
  list->length = 0;
}

void pushInorder(List *list, Node *node) {
  if(!list->head) {
    list->head = node;
  } else if(node->frequence < list->head->frequence) {
    node->next = list->head;
    list->head = node;
  } else {
    Node *head = list->head;

    while(head->next && head->next->frequence <= node->frequence) {
      head = head->next;
    }

    node->next = head->next;
    head->next = node;
  }

  list->length++;
}

void listFill(unsigned int t[], List *list) {
  for(int i = 0; i < LENGTH; i++) {
    if(t[i] > 0) {
      Node *newNode = (struct Node *) malloc(sizeof(struct Node));

      if(newNode) {
        newNode->character = i;
        newNode->frequence = t[i];
        newNode->next = NULL;
        newNode->left = NULL;
        newNode->right = NULL;

        pushInorder(list, newNode);
      } else {
        printf("Memory allocation error...!");
        break;
      }
    }
  }
}

void listPrint(List *list) {
  Node *head = list->head;

  printf("Sorted list: Length: %d\n", list->length);

  while(head) {
    printf("Character: %c Frequence: %d\n", head->character, head->frequence);
    head = head->next;
  }
  printf("\n");
}

Node* pop(List *list) {
  if(list->head) {
    Node *rm = list->head;
    list->head = rm->next;
    rm->next = NULL;
    list->length--;
    return rm;
  }

  printf("Empty list.\n\n");
  return NULL;
}

Node* treeInit(List *list) {
  while(list->length > 1) {
    Node *first = pop(list);
    Node *second = pop(list);

    Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    if(newNode) {
      newNode->character = '+';
      newNode->frequence = first->frequence + second->frequence;
      newNode->left = first;
      newNode->right = second;
      newNode->next = NULL;

      pushInorder(list, newNode);
    } else {
      printf("treeInit memory allocation error!\n");
      return NULL;
    }
  }

  return list->head;
}

void treePrint(Node *root, int size) {
  if(!root->left && !root->right) {
    printf("Leaf: %c\tHeight: %d\n", root->character, size);
  } else {
    treePrint(root->left, size + 1);
    treePrint(root->right, size + 1);
  }
}

int maximumDepth(Node *root) {
  if(!root) {
    return -1;
  }

  int l = maximumDepth(root->left);
  int r = maximumDepth(root->right);

  return (l > r ? l : r) + 1;
}

char** minHeap(int cols) {
  int i;
  char **dictionary = (char**) malloc(sizeof(char*) * LENGTH);

  for(i = 0; i < LENGTH; i++) {
    dictionary[i] = calloc(cols, sizeof(char));
  }

  return dictionary;
}

void createMinHeap(char **dict, Node *root, char *path, int cols) {
  char left[cols], right[cols];

  if(!root->left && !root->right) {
    stringCopy(dict[root->character], path);
  } else {
    stringCopy(left, path);
    stringCopy(right, path);

    stringConcat(left, "0");
    stringConcat(right, "1");

    createMinHeap(dict, root->left, left, cols);
    createMinHeap(dict, root->right, right, cols);
  }
}

void minHeapPrint(char **dict) {
  printf("\nMinHeap: \n");
  for(int i = 0; i < LENGTH; i++) {
    if(stringLen(dict[i]) > 0) {
      printf("%3d: %s\n", i, dict[i]);
    }
  }
}

int findStringLength(char **dict, unsigned char *text) {
  int i = 0, len;

  while(text[i] != '\0') {
    len = len + stringLen(dict[text[i]]);
    i++;
  }

  return len + 1;
}

char* encode(char **dict, unsigned char *text) {
  int i = 0;
  int length = findStringLength(dict, text);
  char *code = calloc(length, sizeof(char));

  while(text[i] != '\0') {
    stringConcat(code, dict[text[i]]);
    i++;
  }

  return code;
}

char* decode(unsigned char *text, Node *root) {
  int i = 0;
  Node *aux = root;
  char temp[2];

  char *decoded = calloc(stringLen(text), sizeof(char));

  while(text[i] != '\0') {
    if(text[i] == '0') {
      aux = aux->left;
    } else {
      aux = aux->right;
    }

    if(!aux->left && !aux->right) {
      temp[0] = aux->character;
      temp[1] = '\0';
      stringConcat(decoded, temp);
      aux = root;
    }

    i++;
  }

  return decoded;
}


int main() {
  unsigned char text[] = {"Lets try some Huffman!"};
  unsigned int table[LENGTH];
  List list;
  Node *root = NULL;
  int cols;
  char **dict;
  char *code, *decoded;

  frequenceTableInit(table);
  frequenceTableFill(text, table);
  frequenceTablePrint(table);

  listInit(&list);
  listFill(table, &list);
  listPrint(&list);

  root = treeInit(&list);
  treePrint(root, 0);

  cols = maximumDepth(root) + 1;
  dict = minHeap(cols);
  createMinHeap(dict, root, "", cols);
  minHeapPrint(dict);

  code = encode(dict, text);
  printf("\nEncoded text: %s\n", code);

  decoded = decode(code, root);
  printf("\ndecoded text: %s\n", decoded);

  return 0;
}