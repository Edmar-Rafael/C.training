#include <stdio.h>
#include <stdlib.h>

#define LENGTH 31

typedef struct Node {
  int key;
  struct Node *next;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;

void listInit(List *t) {
  t->head = NULL;
  t->length = 0;
}

void pushInorder(List *t, int val) {
   Node *newNode = (struct Node *) malloc(sizeof(struct Node));

   if(newNode) {
      newNode->key = val;
      newNode->next = NULL;

      if(!t->head || t->head->key > val) {
         newNode->next = t->head;
         t->head = newNode;
      } else {
         Node *head = t->head;

         while(head->next && head->next->key < val) {
            head = head->next;
         }

         if(head->next && head->next->key == val || head->key == val) {
            free(newNode);
            return;
         }

         newNode->next = head->next;
         head->next = newNode; 
      }

      t->length++;
   } else {
      printf("Memory allocation error!!!\n\n");
   }
}

int popAtSpecificPos(List *t, int val) {
  Node *head = t->head;

  if(head) {
    Node *rm, *prev;

    if(head->key == val) {
      rm = t->head;
      t->head = rm->next;
      t->length--;
      return rm->key;
    }

    while(head->key != val) {
      prev = head;
      head = head->next;
    }

    if(!head->next && head->key != val) {
      printf("Element does'nt exist.\n");
      return 0;
    }

    rm = head;
    prev->next = head->next;
    t->length--;
    return rm->key;
  }

  printf("Empty list.\n");
  return 0;
}

void listPrint(List *t) {
  Node *head = t->head;

  printf("Length: %d-> ", t->length);
  while(head) {
    printf("%d-> ", head->key);
    head = head->next;
  }
}

int listSearch(List *t, int val) {
  Node *head = t->head;

  while(head && head->key != val) {
    head = head->next;
  }

  return head ? head->key : 0;
}

void tableInit(List t[]) {
  for(int i = 0; i < LENGTH; i++) {
    listInit(&t[i]);
  }
}

int hash(int key) {
  return key % LENGTH;
}

void insert(List t[], int val) {
  printf("Type a number to insert: ");
  scanf("%d", &val);

  int id = hash(val);

  pushInorder(&t[id], val);
}

int delete(List t[], int val) {
  printf("Type a number to delete: ");
  scanf("%d", &val);

  int id = hash(val);

  return popAtSpecificPos(&t[id], val);
}

void tablePrint(List t[]) {
  for(int i = 0; i < LENGTH; i++) {
    printf("%2d = ", i);
    listPrint(&t[i]);
    printf("\n");
  }
  printf("\n");
}

int search(List t[], int key) {
  printf("Type a number to search: ");
  scanf("%d", &key);

  int id = hash(key);

  return listSearch(&t[id], key);
}


int main() {
  int choice, val;
  List table[15];

  tableInit(table);

  do {
    printf("\t0 - Exit\n\t1 - Insert\n\t2 - Delete\n\t3 - Show table\n\t4 - Search\n\n");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        insert(table, val);
      break;

      case 2:
        val = delete(table, val);
        val ? printf("%d deleted.\n\n", val) : printf("Element not found.\n\n");
      break;

      case 3:
        tablePrint(table);
      break;

      case 4:
        val = search(table, val);
        val ? printf("%d found,\n\n", val) : printf("Element not found\n\n");
      break;

      default:
        choice != 0 ? printf("Wrong choice.\n\n") : printf("Bye Bye!!!\n\n");
    }
  } while(choice != 0);

  return 0;
}