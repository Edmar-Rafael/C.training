#include <stdio.h>
#include <stdlib.h>
#include "../mergeSort.c"


int countNodes(Node *head) {
  int count = 0;

  while(head) {
    count++;
    head = head->next;
  }

  return count;
}

Node* findItem(Node *list, int item) {
  Node *res = NULL;
  if(list) {
    printf("Type a value: ");
    scanf("%d", &item);

    while(list && item != list->data) {
      list = list->next;
    }

    if(list) {
      res = list;
    }

    return res;
  }
  
  printf("Empty list.");
  return NULL;
}

void insertAtBegin(Node **list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = *list;
    *list = newNode;
  } else {
    printf("Memory allocation error...!");
  }
}

void insertAtMiddle(Node **list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(*list == NULL) {
      *list = newNode;
    } else {
      Node *aux = *list;
      int nodes = countNodes(aux) / 2;
      int i = 0;

      while(nodes >  1) {
        aux = aux->next;  
        nodes--;
      }

      newNode->next = aux->next;
      aux->next = newNode;
    }
  } else {
    printf("Memory allocation error...!");
  }
}

void insertAtSpecificPos(Node **list, int val, int after) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  int nodes = countNodes(*list);

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);
    if(nodes > 1) {
      printf("insert after: ");
      scanf("%d", &after);
    }

    newNode->data = val;
    newNode->next = NULL;

    if(*list == NULL) {
      *list = newNode;
    } else {
      Node *aux = *list;

      while(aux->data != after && aux->next) {
        aux = aux->next;
      }

      newNode->next = aux->next;
      aux->next = newNode;
    }
  } else {
    printf("Memory allocation error!");
  }
}

void insertAtEnd(Node **list, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(*list == NULL) {
      *list = newNode;
    } else {
      Node *aux = *list;

      while(aux->next) {
        aux = aux->next;
      }

      aux->next = newNode;
    }
  } else {
    printf("Memory allocation error...!");
  }
}

void listSort(Node **list) {
  int nodes = countNodes(*list);
  
  if(*list && nodes > 1) {
    mergeSort(list);
  } else {
    printf("Not enough elements.\n\n");
  }
}

Node* removeAtbegin(Node **list) {
  if(*list) {
    Node *rm = *list;
    *list = rm->next;
    return rm;
  }

  printf("Empty list!\n");
  return NULL;
}

Node* removeAtEnd(Node **list) {
  Node *aux = *list;

  if(aux) {
    int nodes = countNodes(aux);
    Node *rm;

    if(nodes == 1) {
      rm = aux;
      *list = NULL;      
    } else {
      while(nodes > 2) {
        aux = aux->next;
        nodes--;
      }

      rm = aux->next;
      aux->next = NULL;
    }

    return rm;
  }

  printf("Empty list!\n");
  return NULL;
}

Node* removeAtSpecificPos(Node **list, int key) {
  Node *aux = *list;

  if(aux) {
    Node *rm, *prev;

    if(aux && aux->data == key) {
      rm = *list;
      *list = aux->next;
      return rm;  
    }

    while(aux->data != key) {
      prev = aux;
      aux = aux->next;
    }

    rm = aux;
    prev->next = aux->next;
    return rm;
  }

  return NULL;
}

Node* removeAll(Node **list) {
  if(*list) {
    Node *rm = *list;
    *list = NULL;
    return rm;
  }

  printf("Empty list!\n");
  return NULL;
}

Node* changePlace(Node **list, int key1, int key2) {
  Node *current = *list;

  if(current && countNodes(current) > 1) {
    printf("Type the first node: ");
    scanf("%d", &key1);
    printf("Type the node to change with the first: ");
    scanf("%d", &key2);

    if(key1 == key2) {
      printf("\nSame values are'nt allowed.\n\n");
      return *list;
    }

    Node *currentKey1 = NULL, *currentKey2 = NULL;
    Node *prevKey1 = NULL, *prevKey2 = NULL;

    while(current) {
      if(current->data == key1) {
        currentKey1 = current;
        break;
      }

      prevKey1 = current;
      current = current->next;
    }

    current = *list;

    while(current) {
      if(current->data == key2) {
        currentKey2 = current;
        break;
      }

      prevKey2 = current;
      current = current->next;
    }

    if(currentKey1 == NULL || currentKey2 == NULL) {
      printf("\nSome value doesnt exist.\n\n");
      return *list;
    }

    if(prevKey1) {
      prevKey1->next = currentKey2;
    } else {
      *list = currentKey2;
    }

    if(prevKey2) {
      prevKey2->next = currentKey1;
    } else {
      *list = currentKey1;
    }

    Node *aux = currentKey2->next;
    currentKey2->next = currentKey1->next;
    currentKey1->next = aux;

    return *list;
  } else {
    printf("Not enough elements!\n\n");
    return NULL;
  }
}

Node* listInverter(Node **list) {
  Node *current = *list;
  Node *invertedList = NULL;

  if(current) {
    while(current) {
      Node *next = current->next;
      current->next = invertedList;
      invertedList = current;
      current = next;
    }

    return invertedList;
  }

  printf("Empty list\n");
  return NULL;
}

void printList(Node *list) {
  printf("\n---------List----------\n");
  printf("Nodes: %d\n", countNodes(list));

  while(list) {
    printf("%d -> ", list->data);
    list = list->next;
  }

  printf("\n------End of list------\n\n");
}

int main() {
  int choice, val, after, pos;
  char option1[] = "0 - Exit\n1 - insert at begin\n2 - Remove at begin\n3 - Print\n4 - insert at end\n";
  char option2[] = "5 - insert at middle\n6 - insert at specific\n7 - Remove at end\n";
  char option3[] = "8 - Remove at specific position\n9 - Clear list\n10 - change positions\n";
  char option4[] = "11 - To invert\n12 - sort\n13 - Find Item\n\n";
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s%s", option1, option2, option3, option4);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtBegin(&list, val);
      break;

      case 2:
        remove = removeAtbegin(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 3:
        printList(list);
      break;

      case 4:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtEnd(&list, val);
      break;

      case 5:
        printf("Type a number: ");
        scanf("%d", &val);
        insertAtMiddle(&list, val);
      break;

      case 6:
        insertAtSpecificPos(&list, val, after);
      break;

      case 7:
        remove = removeAtEnd(&list);
        remove ? printf("%d removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 8:
        printf("Type a number to remove: ");
        scanf("%d", &pos);
        remove = removeAtSpecificPos(&list, pos);
        remove ? printf("%d removed.\n\n", remove->data) : printf("%d not found.\n\n", pos);
        free(remove);
      break;

      case 9:
        remove = removeAll(&list);
        if(remove) {
          printf("Erased items: ");
          printList(remove);
        } else {
          printf("Nothing to remove!\n\n");
        }
        free(remove);
      break;

      case 10:
        list = changePlace(&list, val, after);
      break;

      case 11:
        list = listInverter(&list);
        list ? printf("List was inverted.\n\n") : printf("Nothing to invert.\n\n");
      break;

      case 12:
        listSort(&list);
      break;

      case 13:
        list = findItem(list, val);
        list ? printf("%d Found.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
      break;

      default:
        choice != 0 ? printf("invalid option!\n") : printf("Good bye!\n\n");
    }
  } while(choice != 0);
  
  return 0;
}