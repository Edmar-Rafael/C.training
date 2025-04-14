#include <stdio.h>
#include <stdlib.h>
#include "../String/String.c"

#define LENGTH 256

typedef struct Node {
   int frequence;
   unsigned char character;
   struct Node *next;
   struct Node *left, *right;
} Node;

typedef struct {
   int length;
   Node *head;
} List;

int i;

void frequenceTableInit(unsigned int t[]) {
   for(i = 0; i < LENGTH; i++) {
      t[i] = 0;
   }
}

void frequenceTableFill(unsigned int t[], unsigned char *str) {
   for(i = 0; str[i] != '\0'; i++) {
      t[str[i]]++;
   }
}

void frequenceTablePrint(unsigned int t[]) {
   for(i = 0; i < LENGTH; i++) {
      if(t[i] > 0) {
         printf("%d: %u = %c\n", i, t[i], i);
      }
   }
}

void listInit(List *list) {
   list->head = NULL;
    list->length = 0;
}

void pushInorder(List *list, Node *node) {
   if(!list->head) {
      list->head = node;
   } else if(list->head->frequence > node->frequence) {
      node->next = list->head;
      list->head = node;
   } else {
      Node *head = list->head;

      while(head->next && head->next->frequence < node->frequence) {
         head = head->next;
      }

      node->next = head->next;
      head->next = node;
   }

   list->length++;
}

void listFill(List *list, unsigned int t[]) {
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
         } else {
            printf("Memory allocation error!\n\n");
            break;
         }
      }
   }
}

void listPrint(List *list) {
   Node *head = list->head;

   printf("\nSorted List.\t Length: %d\n", list->length);
   while(head) {
      printf("Character: %c   Frequence: %d\n", head->character, head->frequence);
      head = head->next;
   }
   printf("\n");
}

Node* pop(List *list) {
   if(!list) {
      return NULL;
   }

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
         newNode->next = NULL;
         newNode->left = first;
         newNode->right = second;

         pushInorder(list, newNode);
      } else {
         printf("HuffmanTree error!!!\n");
         return NULL;
      }
   }

   return list->head;
}

void HuffmanTreePrint(Node *root, int height) {
   if(!root->left && !root->right) {
      printf("Leaf: %c   Height: %d\n", root->character, height);
   } else {
      HuffmanTreePrint(root->left, height + 1);
      HuffmanTreePrint(root->right, height + 1);
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

char** dictionaryInit(int cols) {
   char **dictionary = (char **) malloc(sizeof(char*) * LENGTH);

   for(i = 0; i < LENGTH; i++) {
      dictionary[i] = calloc(cols,sizeof(char));
   }

   return dictionary;
}

void createDictionary(char **dict, Node *root, char *path, int cols) {

   struct DictIteration {
      Node *root;
      char path[LENGTH];
      char left_done;
      char right_done;
   };
   struct DictIteration dict_stack[LENGTH] = {0};
   dict_stack[0].root = root;
   stringMemset(dict_stack[0].path, 0, cols);
   stringCopy(dict_stack[0].path, path);
   dict_stack[0].left_done = 0;
   dict_stack[0].right_done = 0;
   int iterator = 0;
   while (1){
      struct DictIteration *current = &dict_stack[iterator];      
      if(!current->root->left  && !current->root->right){
  printf("caracter %d\n",current->root->character);
         printf("path %s\n",current->path);     
      stringCopy(dict[current->root->character], current->path);
      }
       

     // printf("iterator %d\n", iterator);
      //printf("current %p\n", current);
      if(current->root->left && !current->left_done){
         current->left_done = 1;
         iterator+=1;
         char left[cols];
         stringMemset(left, 0, cols);
         stringCopy(left, current->path);
         concat(left, "0");
         dict_stack[iterator].root = current->root->left;
         stringCopy(dict_stack[iterator].path, left);
         dict_stack[iterator].right_done = 0;
         dict_stack[iterator].left_done = 0;
         
         continue;
      }
      
      if(current->root->right && !current->right_done){
         current->right_done = 1;
         iterator+=1;
         char right[cols];
         stringMemset(right, 0, cols);
         stringCopy(right, current->path);
         concat(right, "1");
         dict_stack[iterator].root = current->root->right;
         stringCopy(dict_stack[iterator].path, right);
         dict_stack[iterator].right_done = 0;
         dict_stack[iterator].left_done = 0;
         
         continue;
      }


      if(iterator == 0){
         break;
      }

      iterator-=1;   
   }
   

}
void dictionaryPrint(char **dict) {
   printf("\nDictionary.\n");
   for(i = 0; i < LENGTH; i++) {
      if(stringLen(dict[i]) > 0) {
         printf("%d: %s\n", i, dict[i]);
      }
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
   int codeLen = findCodeLength(dict, str);

   char *code = (char *) calloc(codeLen, sizeof(char));

   for(i = 0; str[i] != '\0'; i++) {
      concat(code, dict[str[i]]);
   }

   return code;
}

char* toDecode(char *code, Node *root, unsigned char *str) {
   Node *aux = root;
   char temp[2];

   char *decode = (char *) calloc(stringLen(str), sizeof(char));

   for(i = 0; code[i] != '\0'; i++) {
      if(code[i] == '0') {
         aux = aux->left;
      } else {
         aux = aux->right;
      }

      if(!aux->left && !aux->right) {
         temp[0] = aux->character;
         temp[1] = '\0';
         concat(decode, temp);
         aux = root;
      }
   }

   return decode;
}


int main() {
  unsigned int table[LENGTH];
   unsigned char *text = {"I'll squeeze you till the death!!!"};
   List list;

   frequenceTableInit(table);
   frequenceTableFill(table, text);
   frequenceTablePrint(table);

   listInit(&list);
   listFill(&list, table);
   listPrint(&list);

   Node *root = HuffmanTreeInsert(&list);
   HuffmanTreePrint(root, 0);

   int cols = maximumDepth(root);
   char **dictionary = dictionaryInit(cols);
   createDictionary(dictionary, root, "", cols);
   dictionaryPrint(dictionary);

   char *code = encode(dictionary, text);
   printf("\nCode: %s\n", code);

   char *decode = toDecode(code, root, text);
   printf("\ndecode: %s\n", decode);

  return 0;
}