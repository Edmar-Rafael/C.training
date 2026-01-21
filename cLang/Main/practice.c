#include "practice.h"
#include "../Sort_algorithms/mergeSort_linkedList.c"


void createList(List *l) {
   l->head = NULL;
   l->length = 0;
}

void push(List *l, char *str) {
   printf("Type a number: ");
   scanf("%s", str);
   
   if(!charToInt(str)) return;

   int val = charToInt(str);

   if(sizeof(val) > sizeof(int)) {
      printf("Too much digits. stack smashed!!!\n\n");
      return;
   }

   Node *newNode = (struct Node *) malloc(sizeof(struct Node));

   if(newNode) {
      newNode->data = val;
      newNode->next = l->head;
      l->head = newNode;
      l->length++;
      return;
   }

   printf("Memory allocation error!!!");
}

Node* pop(List *l) {
   if(l->head) {
      Node *rm = l->head;
      l->head = rm->next;
      rm->next = NULL;
      l->length--;

      return rm;
   }

   printf("Empty list.\n");
   return NULL;
} 

void printList(List l) {
   Node *head = l.head;

   printf("\n--------List\tLength: %d---------\n\n", l.length);
   while(head) {
      printf("%d ->", head->data);
      head = head->next;
   }
   printf("\n\n-------------END----------------\n\n");
}

void SortList(List *l) {
   if(l->head && l->length > 1) {
      Node *head = l->head;
      l->head = linkedList_mergeSort(&head);
      return;
   }

   printf("Not enough items to sort.\n\n");
}

void listInverter(List *l) {
   if(l->head && l->length > 1) {
      Node *curr = l->head;
      Node *invertedList = NULL;

      while(curr) {
         Node *next = curr->next;
         curr->next = invertedList;
         invertedList = curr;
         curr = next;
      }

      l->head = invertedList;
      return;
   }

   printf("Not enough elements!!!\n\n");
}

void clearList(List *l) {
   if(l->head || l->length > 0) {
      createList(l);
      printf("List erased!\n\n");
      return;
   }

   printf("Empty list!!!\n\n");
}

void enqueue(List *l, char *str) {
   if(!l->head) {
      push(l, str);
      return;
   }

   printf("Type a number to add: ");
   scanf("%s", str);

   if(!charToInt(str)) return;

   int val = charToInt(str);

   Node *newNode = (struct Node *) malloc(sizeof(struct Node));

   if(newNode) {
      newNode->data = val;
      newNode->next = NULL;

      Node *curr = l->head;

      while(curr->next) {
         curr = curr->next;
      }

      curr->next = newNode;
      l->length++;
      return;
   }

   printf("Memory allocation error!!!\n\n");
}

Node* dequeue(List *l) {
   Node *rm = NULL;

   if(!l->head) return NULL;

   if(l->length == 1) {
      rm = pop(l);
      createList(l);
      return rm;
   }

   Node *curr = l->head;
   Node *prev = NULL;

   while(curr->next) {
      prev = curr;
      curr = curr->next;
   }

   rm = curr;
   prev->next = NULL;
   l->length--;

   return rm;
}

void changePlace(List *l, int key1, int key2) {
   if(l->head) {
      Node *curr = l->head;

      if(l->length > 1) {
         printf("Type the first number to change: ");
         scanf("%d", &key1);
         printf("Type the second number to change: ");
         scanf("%d", &key2);

         Node *currKey1 = NULL, *currKey2 = NULL;
         Node *prevkey1 = NULL, *prevKey2 = NULL;

         while(curr) {
            if(curr->data == key1) {
               currKey1 = curr;
               break;
            }

            prevkey1 = curr;
            curr = curr->next;
         }

         curr = l->head;

         while(curr) {
            if(curr->data == key2) {
               currKey2 = curr;
               break;
            }

            prevKey2 = curr;
            curr = curr->next;
         }

         if(!currKey1 || !currKey2) {
            printf("Some element does'nt exist.\n\n");
            return;
         }

         if(prevkey1) prevkey1->next = currKey2;
         if(!prevkey1) l->head = currKey2;

         if(prevKey2) prevKey2->next = currKey1;
         if(!prevKey2) l->head = currKey1;

         Node *aux = currKey2->next;
         currKey2->next = currKey1->next;
         currKey1->next = aux;
         return;
      }

      printf("Not enough items.\n\n");
      return;
   }

   printf("Empty list!\n\n");
}

Node* popAtspecificPos(List *l, int key) {
   if(l->head) {
      Node *curr = l->head;
      Node *prev = NULL;
      Node *rm = NULL;

      printf("Type a number to remove: ");
      scanf("%d", &key);

      if(l->head->data == key) {
         rm = pop(l);
         return rm;
      }

      while(curr->next && curr->data != key) {
         prev = curr;
         curr = curr->next;
      }

      if(curr->data != key) {
         printf("Element {%d} not found.\n\n", key);
         return NULL;
      }

      rm = curr;
      prev->next = rm->next;
      rm->next = NULL;
      l->length--;
      return rm;
   }

   printf("Empty list!\n\n");
   return NULL;
}

void pushAtSpecificElement(List *l, int key, char *str) {
   if(!l->head || l->length == 1) {
      push(l, str);
      return;
   }

   Node *curr = l->head;
   Node *prev = NULL;

   printf("Type an element to insert at: ");
   scanf("%d", &key);

   if(l->head->data == key) {
      push(l, str);
      return;
   }

   Node *newNode = (struct Node *) malloc(sizeof(struct Node));

   if(newNode) {
      printf("Type a number to insert: ");
      scanf("%s", str);

      if(!charToInt(str)) return;

      int val = charToInt(str);

      newNode->data = val;
      newNode->next = NULL;

      while(curr && curr->data != key) {
         prev = curr;
         curr = curr->next;
      }

      if(!curr) {
         printf("The element you choose does'nt exists.\n\n");
         return;
      }

      newNode->next = curr;
      prev->next = newNode;
      l->length++;
      return;
   }

   printf("Memory allocation error.\n\n");
}