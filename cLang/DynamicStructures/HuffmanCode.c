#include <stdio.h>
#include <stdlib.h>
#include "../Main/styles.c"
#include "../String/String.c"

#define LENGTH 256


typedef struct Node {
   int frequence;
   char character;
   int height;
   char visited;
   struct Node *next;
   struct Node *left, *right;
} Node;

typedef struct {
   int length;
   Node *head;
} List;

typedef struct Stack {
   int height;
   struct Node *top;
} Stack;

int i, j;

void frequenceTableFill(unsigned int t[], unsigned char *str) {
   for(i = 0; str[i] != '\0'; i++) {
      t[str[i]]++;
   }
}

void frequenceTablePrint(unsigned int t[]) {
   for(i = 0; i < LENGTH; i++) {
      if(t[i] > 0) {
         printf("%d = %u: %c\n", i, t[i], i);
      }
   }
}

void listInit(List *list) {
   list->head = NULL;
   list->length = 0;
}

void pushInorder(List *list, Node *node) {
   if(!list->head || list->head->frequence >= node->frequence) {
      node->next = list->head;
      list->head = node;
      list->length++;
      return;
   }

   Node *current = list->head;

   while(current->next && current->next->frequence < node->frequence) {
      current = current->next;
   }

   node->next = current->next;
   current->next = node;
   list->length++;
}

Node* createStackNewNode(Node *curr, Stack *stk) {
   Node *node = (struct Node *) malloc(sizeof(struct Node));

   if(node) {
      curr->visited = 1;
      node->visited = curr->visited;
      node->height = stk->height;
      node->character = curr->character;
      node->frequence = curr->frequence;
      node->left = curr->left;
      node->right = curr->right;
      node->next = stk->top;
      stk->top = node;
   }

   return node;
}

void listFill(List *list, unsigned int t[]) {
   Node *current = NULL;

   for(i = 0; i < LENGTH; i++) {
      if(t[i] > 0) {
         Node *newNode = (struct Node *) malloc(sizeof(struct Node));

         if(newNode) {
            newNode->character = i;
            newNode->frequence = t[i];
            newNode->next = NULL;
            newNode->left = NULL;
            newNode->right = NULL;

            pushInorder(list, newNode);
         }
      }
   }
}

void listPrint(List list) {
   Node *current = list.head;

   printf("\nSorted List\n");
   while(current) {
      printf("Character: %c\tFrequence: %d\n", current->character, current->frequence);
      current = current->next;
   }
   printf("\n");
}

Node* pop(List *list) {
   Node *rm = list->head;
   list->head = rm->next;
   rm->next = NULL;
   list->length--;

   return rm;
}

Node* HuffmanTreeInsert(List *list) {
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
      }
   }

   return list->head;
}

void recursiveHuffmanTreePrint(Node *root, int height) {
   printf("Char: %c\tVisited: %d\n", root->character, root->visited);

   if(root->left) recursiveHuffmanTreePrint(root->left, height + 1);
   if(root->right) recursiveHuffmanTreePrint(root->right, height + 1);
}

int recursiveMaximumDepth(Node *root) {
   if(!root) {
      return -1;
   }

   int l = recursiveMaximumDepth(root->left);
   int r = recursiveMaximumDepth(root->right);

   return (l > r ? l : r) + 1;
}

void stackInit(Stack *stk) {
   stk->height = 0;
   stk->top = NULL;
}

Node* popStack(Stack *stk) {
   Node *remove = stk->top;
   stk->top = remove->next;
   remove->next = NULL;
   return remove;
}

void iterativeStackTreePrint(Stack *stk, Node *root) {
   Node *current = root;

   printf("Huffman Tree.\n");
   while(1) {
      if(!current->visited) {
         Node *newNode = createStackNewNode(current, stk);
      }

      if(!current->left && !current->right) {
         printf("Leaf: %c\t\tHeight: %d\n", current->character, stk->height);
      }

      if(current->left && !current->left->visited) {
         current = current->left;
         stk->height++;
         continue;
      }

      if(current->right && !current->right->visited) {
         current = current->right;
         stk->height++;
         continue;
      }

      Node *rm = popStack(stk);

      current = stk->top;
      if(rm->right && rm->right->visited) {
         rm->right->visited = 0;
         if(rm->left && rm->left->visited) rm->left->visited = 0;
      }
      free(rm);

      if(stk->height == 0) {
         root->visited = 0;
         break;
      }
      stk->height = current->height;
   }
}

int iterativeMaximumDepth(Stack *stk, Node *root) {
   if(!root) return -1;
   
   Node *current = root;
   int n = 0;

   while(1) {
      if(!current->visited) {
         createStackNewNode(current, stk);
      }

      if(current->left && !current->left->visited) {
         current = current->left;
         stk->height++;
         continue;
      }

      if(current->right && !current->right->visited) {
         current = current->right;
         stk->height++;
         continue;
      }

      Node *rm = popStack(stk);

      current = stk->top;
      if(rm->right && rm->right->visited) {
         rm->right->visited = 0;
         if(rm->left && rm->left->visited) rm->left->visited = 0;
      }
      free(rm);
      if(stk->height == 0) {
         root->visited = 0;
         break;
      }
      if(stk->height > n) n = stk->height;
      stk->height = current->height;
   }

   return n;
}

char** dictionaryInit(int cols) {
   char **dictionary = (char **) malloc(sizeof(char *) * LENGTH);

   for(i = 0; i < LENGTH; i++) {
      dictionary[i] = (char *) calloc(cols, sizeof(char));
   }

   return dictionary;
}

void iterativeCreateDictionary(char **dict, Node *root, Stack *stk, int cols) {
   Node *current = root;

   char *path = (char *) calloc(cols, sizeof(char));

   while(1) {
      if(!current->visited) {
         Node *newNode = createStackNewNode(current, stk);
      }

      if(!current->left && !current->right) stringCopy(dict[current->character], path);

      if(current->left && !current->left->visited) {
         current = current->left;
         stk->height++;
         char left[cols];
         stringMemSet(left, 0, cols);
         stringCopy(left, path);
         concat(left, "0");
         stringCopy(path, left);
         continue;
      }

      if(current->right && !current->right->visited) {
         current = current->right;
         stk->height++;
         char right[cols];
         stringMemSet(right, 0, cols);
         stringCopy(right, path);
         concat(right, "1");
         stringCopy(path, right);
         continue;
      }

      Node *rm = popStack(stk);
      
      current = stk->top;
      path[stk->height - 1] = '\0';
      if(rm->right && rm->right->visited) {
         rm->right->visited = 0;
         if(rm->left && rm->left->visited) rm->left->visited = 0;
      }
      free(rm);
      if(stk->height == 0) {
         root->visited = 0;
         break;
      }
      stk->height = current->height;
   }
}

void recursiveCreateDictionary(char **dict, Node *root, char *path, int cols) {
   char left[cols], right[cols];

   if(!root->left && !root->right) stringCopy(dict[root->character], path);

   stringCopy(left, path);
   stringCopy(right, path);

   concat(left, "0");
   concat(right, "1");

   if(root->left) recursiveCreateDictionary(dict, root->left, left, cols);
   if(root->right) recursiveCreateDictionary(dict, root->right, right, cols);
}

void dictionaryPrint(char **dict) {
   printf("\n");
   for(i = 0; i < LENGTH; i++) {
      if(stringLen(dict[i]) > 0) printf("%3d: %c = %s\n", i, i, dict[i]);
   }
}

int findCodeLength(char **dict, unsigned char *str) {
   int len = 0;
   
   for(i = 0; str[i] != '\0'; i++) {
      len += stringLen(dict[str[i]]);
   }

   return len;
}

char* encode(char **dict, unsigned char *str) {
   int codeLenght = findCodeLength(dict, str);

   char *code = (char *) calloc(codeLenght, sizeof(char));

   for(i = 0; str[i] != '\0'; i++) {
      concat(code, dict[str[i]]);
   }

   return code;
}

char* toDecode(char *code, Node *root, unsigned char *str) {
   Node *curr = root;
   
   char *decode = (char *) calloc(stringLen(str), sizeof(char));
   char temp[2];

   for(i = 0; code[i] != '\0'; i++) {
      if(code[i] == '0') curr = curr->left;
      if(code[i] == '1') curr = curr->right;

      if(!curr->left && !curr->right) {
         temp[0] = curr->character;
         temp[1] = '\0';
         concat(decode, temp);
         curr = root;
      }
   }

   return decode;
}


int main() {
   printStyles();
   unsigned int table[LENGTH] = {0};
   unsigned char *text = {"I'll squeeze you till the death!!!"};
   List list;

   frequenceTableFill(table, text);
   frequenceTablePrint(table);

   listInit(&list);
   listFill(&list, table);
   listPrint(list);

   Stack stk;
   stackInit(&stk);

   Node *root = HuffmanTreeInsert(&list);
   iterativeStackTreePrint(&stk, root);

   int cols = iterativeMaximumDepth(&stk, root);
   char **dictionary = dictionaryInit(cols);
   iterativeCreateDictionary(dictionary, root, &stk, cols);
   dictionaryPrint(dictionary);

   char *code = encode(dictionary, text);
   printf("\nCode: %s\n", code);

   char *decode = toDecode(code, root, text);
   printf("\ndecode: %s\n", decode);

  return 0;
}