#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

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
      int nodes = countNodes(aux);

      while(nodes / 2 > 1) {
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

  if(newNode) {
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

int countNodes(Node *head) {
  int count = 0;

  while(head) {
    count++;
    head = head->next;
  }

  return count;
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
  Node *rm, *aux = *list;

  if(aux) {
    int nodes = countNodes(aux);

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

Node* removeAll(Node **list) {
  if(*list) {
    Node *rm = *list;
    *list = NULL;
    return rm;
  }

  printf("Empty list!\n");
  return NULL;
}

void changePlace(Node **list, int key1, int key2) {
  Node *aux = *list;
  int count = 0;

  if(aux) {
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
    printf("Empty list!\n\n");
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
  char option1[] = "0 - Exit\n1 - insert at begin\n2 - Remove\n3 - Print\n4 - insert at end\n";
  char option2[] = "5 - insert at middle\n6 - insert at specific\n7 - Remove at end\n";
  char option3[] = "8 - Remove at specific position\n9 - Clear list\n10 - change positions\n";
  char option4[] = "11 - To invert\n\n";
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
        printf("Type a number: ");
        scanf("%d", &val);
        printf("insert after: ");
        scanf("%d", &after);
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
        remove = removeAtspecificPos(&list, pos);
        remove ? printf("%d removed.\n\n", remove->data) : printf("%d not found.\n\n", pos);
      break;

      case 9:
        remove = removeAll(&list);
        if(remove) {
          printf("Erased items: ");
          printList(remove);
        } else {
          printf("Nothing to remove!\n\n");
        }
      break;

      case 10:
        printf("Type the first node: ");
        scanf("%d", &val);
        printf("Type the node to change with the first: ");
        scanf("%d", &after);
        changePlace(&list, val, after);
      break;

      case 11:
        list = listInverter(&list);
        list ? printf("List was inverted.\n\n") : printf("Nothing to invert.\n\n");
      break;

      default:
        choice != 0 ? printf("invalid option!\n") : printf("Good bye!\n\n");
    }
  } while(choice != 0);
  
  return 0;
}