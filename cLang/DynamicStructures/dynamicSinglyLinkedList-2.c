#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.c"

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct List {
  int length;
  Node *head;
} List;

void createList(List *list) {
  list->length = 0;
  list->head = NULL;
}

Node* listInverter(List *list) {
  Node *current = list->head;
  Node *invertedList = NULL;

  if(current && list->length > 1) {
    while(current) {
      Node *next = current->next;
      current->next = invertedList;
      invertedList = current;
      current = next;
    }

    return invertedList;
  }

  printf("Not enough elements.\n\n");
  return NULL;
}

void changePlace(List *list, int key1, int key2) {
  Node *aux = list->head;
  int count = 0;

  if(aux && list->length >= 2) {
    printf("Type the first value: ");
    scanf("%d", &key1);
    printf("Type the value to change with the first: ");
    scanf("%d", &key2);

    while(aux) {
      if(aux->data == key1) {
        aux->data = key2;
        count++;
        if(aux->next) {
          aux = aux->next;
          count--;
        }
      }
      if(aux->data == key2 && count == 0) {
        aux->data = key1;
      }

      aux = aux->next;
    }
  } else {
    printf("Not enough elements!\n\n");
  }
}

void listSort(List *list) {
  Node *head = list->head;

  if(head && list->length > 1) {
    mergeSort(&head);
  } else {
    printf("List contains only one element or, its empty.\n\n");
  }
}

void printList(List list) {
  Node *current = list.head;

  printf("\n-----List length: %d-----\n", list.length);

  while(current) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("\n-------End of List-------\n\n");
}

Node* findItem(List *list, int key) {
  Node *head = list->head;

  if(head) {
    Node *temp = NULL;

    printf("Type a value: ");
    scanf("%d", &key);

    while(head && head->data != key) {
      head = head->next;
    }

    if(head) {
      temp = head;
    }

    return temp;
  }

  printf("Empty list.\n");
  return NULL;
}

void insertAtBegin(List *list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
  } else {
    printf("Memory allocation error...!");
  }
}

void insertAtMiddle(List *list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = NULL;

    if(list->head == NULL) {
      list->head = newNode;
    } else {
      Node *aux = list->head;
      int nodes = list->length / 2;

      while(nodes > 1) {
        aux = aux->next;
        nodes--;
      }

      newNode->next = aux->next;
      aux->next = newNode;
    }

    list->length++;
  } else {
    printf("Memory allocation error...!");
  }
}

void insertAtSpecificPos(List *list, int val, int after) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);
    if(list->length > 1) {
      printf("Type a position to insert: ");
      scanf("%d", &after);
    }

    newNode->data = val;
    newNode->next = NULL;

    if(list->head == NULL) {
      list->head = newNode;
    } else {
      Node *aux = list->head;

      while(aux->data != after && aux->next) {
        aux = aux->next;
      }
      
      newNode->next = aux->next;
      aux->next = newNode;
    }

    list->length++;
  } else {
    printf("memory allocation error...!");
  }
}

void insertAtEnd(List *list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(list->head == NULL) {
      list->head = newNode;
    } else {
      Node *aux = list->head;

      while(aux->next) {
        aux = aux->next;
      }

      aux->next = newNode;
    }

    list->length++;
  } else {
    printf("Memory allocation error...!");
  }
} 

Node* removeAtBegin(List *list) {
  if(list->head) {
    Node *rm = list->head;
    list->head = rm->next;
    list->length--;
    return rm;
  }

  printf("Empty list!\n");
  return NULL;
}

Node* removeAtEnd(List *list) {
  if(list->head) {
    Node *rm, *aux = list->head;
    int nodes = list->length;

    if(nodes == 1) {
      rm = aux;
      list->head = NULL;
    } else {
      while(nodes > 2) {
        aux = aux->next;
        nodes--;
      }

      rm = aux->next;
      aux->next = NULL;
    }

    list->length--;
    return rm;
  }

  printf("Empty list.\n");
  return NULL;
}

Node* removeAtSpecificPos(List *list, int key) {
  Node *head = list->head;

  if(head) {
    printf("Type a value to remove: ");
    scanf("%d", &key);
    Node *rm, *prev;

    if(head && head->data == key) {
      rm = list->head;
      list->head = rm->next;
      list->length--;
      return rm;
    }

    while(head->data != key) {
      prev = head;
      head = head->next;
    }

    if(head->next == NULL && head->data != key) {
      printf("Element does'nt exist.");
      return NULL;
    }

    rm = head;
    prev->next = head->next;
    list->length--;
    return rm;
  }

  printf("Empty list.\n");
  return NULL;
}

void removeAll(List *list) {
  if(list->head) {
    list->head = NULL;
    list->length = 0;
  } else {
    printf("Empty list.\n");
  }
}

int main() {
  int choice, val, after;
  char *option = "0 - Exit\n1 - insert at begin\n2 - Remove at begin\n3 - Print list\n";
  char *option2 = "4 - Insert at middle\n5 - Insert at specific pos\n6 - Insert at end\n";
  char *option3 = "7 - Remove at end\n8 - Remove specific Item\n9 - Clear list\n";
  char *option4 = "10 - Change elements\n11 - sort\n12 - List inverter\n13 - Find Element\n\n";
  List list;
  Node *remove;

  createList(&list);

  do {
    printf("%s%s%s%s", option, option2, option3, option4);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtBegin(&list, val);
      break;

      case 2:
        remove = removeAtBegin(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 3:
        printList(list);
      break;

      case 4:
        insertAtMiddle(&list, val);
      break;

      case 5:
        insertAtSpecificPos(&list, val, after);
      break;

      case 6:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtEnd(&list, val);
      break;

      case 7:
        remove = removeAtEnd(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 8:
        remove = removeAtSpecificPos(&list, val);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Item not found.\n\n");
      break;

      case 9:
        removeAll(&list);
        list.length == 0 ? printf("Nothing to remove.\n\n") : printf("list erased.\n\n");
      break;

      case 10:
        changePlace(&list, val, after);
      break;

      case 11:
        listSort(&list);
      break;

      case 12:
        listInverter(&list);
      break;

      case 13:
        remove = findItem(&list, val);
        remove ? printf("%d found.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
      break;

      default:
        choice != 0 ? printf("Invalid option!\n") : printf("Good bye!\n\n");
      break;
    }
  } while(choice != 0);

  return 0;
}