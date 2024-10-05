#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "practice.c"

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
} Node;

int countNodes(Node *headRef) {
  int count = 0;

  while(headRef) {
    count++;
    headRef = headRef->next;
  }

  return count;
}

void swapper(Node **headRef, int key1, int key2) {
  Node *head = *headRef;

  if(head) {
    printf("Type the fist node to swap: ");
    scanf("%d", &key1);
    printf("Type the second node to swap: ");
    scanf("%d", &key2);

    if(head->next == NULL || key1 == key2) {
      printf("Not enough elements or, invalid entry.\n\n");
      return;
    }

    Node *currentKey1 = NULL;
    Node *currentKey2 = NULL;
    Node *aux;

    while(head) {
      if(head->data == key1) {
        currentKey1 = head;
        break;
      }

      head = head->next;
    }

    head = *headRef;

    while(head) {
      if(head->data == key2) {
        currentKey2 = head;
        break;
      }

      head = head->next;
    }

    if(currentKey1 == NULL || currentKey2 == NULL) {
      printf("\nSome value does'nt exist.\n\n");
      return;
    }

    if(currentKey1->previous) {
      currentKey1->previous->next = currentKey2;
    } else {
      *headRef = currentKey2;
    }

    if(currentKey2->previous) {
      currentKey2->previous->next = currentKey1;
    } else {
      *headRef = currentKey1;
    }

    aux = currentKey2->next;
    currentKey2->next = currentKey1->next;
    currentKey1->next = aux;

    aux = currentKey2->previous;
    currentKey2->previous = currentKey1->previous;
    currentKey1->previous = aux;
  } else {
    printf("Empty list.\n\n");
  }
}

void showList(Node *headRef) {
  printf("\n-----------List-----------\n");
  printf("Nodes: %d\n", countNodes(headRef));

  while(headRef) {
    printf("%d <-> ", headRef->data);
    headRef = headRef->next;
  }

  printf("\n-------End of list--------\n\n");
}

Node* insertionSort(Node **headRef) {
  if(*headRef == NULL) {
    return *headRef;
  }
  
  Node *current = *headRef;
  Node *sorted = NULL;

  while(current) {
    Node *next = current->next;

    if(sorted == NULL || sorted->data >= current->data) {
      current->next = sorted;

      if(sorted) {
        sorted->previous = current;
      }

      sorted = current;
      sorted->previous = NULL;
    } else {
      Node *currentSorted = sorted;

      while(currentSorted->next && currentSorted->next->data < current->data) {
        currentSorted = currentSorted->next;
      }

      current->next = currentSorted->next;

      if(currentSorted->next) {
        currentSorted->next->previous = current;
      }

      currentSorted->next = current;
      current->previous = currentSorted;
    }

    current = next;
  }

  return sorted;
}

Node* listReverter(Node **headRef) {
  Node *head = *headRef;
  int nodes = countNodes(head);

  if(head == NULL) {
    return *headRef;
  }

  if(nodes > 1) {
    Node *prev;

    while(head) {
      prev = head->previous;
      head->previous = head->next;
      head->next = prev;
      head = head->previous;
    }

    if(prev) {
      *headRef = prev->previous;
    }

    return *headRef;
  }
}

void push(Node **headRef, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);
    getchar();

    newNode->data = val;
    newNode->next = *headRef;
    newNode->previous = NULL;

    if(*headRef) {
      Node *head = *headRef;
      head->previous = newNode;
    }

    *headRef = newNode;
  } else {
    printf("Memory allocation error...!");
  }
}

void pushAtEnd(Node **headRef, int val) {
  Node *newNode = malloc(sizeof(newNode));

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(*headRef == NULL) {
      *headRef = newNode;
    } else {
      Node *head = *headRef;

      while(head->next) {
        head = head->next;
      }

      newNode->previous = head;
      head->next = newNode;
    }
  }
}

void pushAtMiddle(Node **headRef, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);
    getchar();

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(*headRef == NULL) {
      *headRef = newNode;
    } else {
      Node *head = *headRef;
      int nodes = countNodes(head) / 2;

      while(nodes > 1) {
        head = head->next;
        nodes--;
      }

      newNode->next = head->next;
      newNode->previous = head;
      if(newNode->next) {
        newNode->next->previous = newNode;
      }
      head->next = newNode;
    }
  }
}

void pushAtSpecificPos(Node **headRef, int val, int key) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  int nodes = countNodes(*headRef);

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);
    getchar();
    if(nodes > 1) {
      printf("Type a number to insert after: ");
      scanf("%d", &key);
      getchar();
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(*headRef == NULL) {
      *headRef = newNode;
    } else {
      Node *head = *headRef;

      while(head->next && head->data != key) {
        head = head->next;
      }

      newNode->next = head->next;
      newNode->previous = head;
      if(newNode->next) {
        newNode->next->previous = newNode;
      }
      head->next = newNode;
    }
  } else {
    printf("Memory allocation error...!");
  }
}

Node* pop(Node **headRef) {
  if(*headRef) {
    Node *rm = *headRef;
    *headRef = rm->next;
    rm->previous = NULL;
    return rm;
  }

  printf("Empty list.\n");
  return NULL;
}

Node* popAtEnd(Node **headRef) {
  Node *head = *headRef;

  if(head) {
    Node *rm = NULL;

    if(head->next == NULL) {
      rm = *headRef;
      *headRef = NULL;
    } else {
      while(head->next) {
        head = head->next;
      }

      rm = head;
      head->previous->next = NULL;
    }

    return rm;
  }

  printf("Empty list.\n");
  return NULL;
}

Node* popAtSpecificPos(Node **headRef, int key) {
  Node *head = *headRef;

  if(head) {
    Node *rm = NULL;

    printf("Choose an item to remove: ");
    scanf("%d", &key);

    if(head->data == key) {
      rm = *headRef;
      *headRef = rm->next;
      return rm;
    }
    
    while(head->data != key) {
      head = head->next;
    }
  
    rm = head;
    head->previous->next = rm->next;

    return rm;
  } else {
    printf("Element does'nt exist.\n");
    return NULL;
  }
}

Node* popAll(Node **headRef) {
  Node *rm = NULL;

  if(*headRef) {
    Node *rm = *headRef;
    *headRef = NULL;
  } else {
    printf("Empty list.\n");
  }

  return rm;
}

int main() {
  char *menu1 = "0 - Exit\n1 - Insert at begin\n2 - Remove at begin\n3 - show\n4 - Insert at end\n";
  char *menu2 = "5 - Insert at middle\n6 - Insert after specific position\n7 - Remove at end\n";
  char *menu3 = "8 - Remove specific item\n9 - Clear list\n10 - To sort list\n11 - To reverse\n";
  char *menu4 = "12 - swap position\n\n";
  int choice, val, key;
  Node *remove, *list = NULL;

  do {
    printf("%s%s%s%s", menu1, menu2, menu3, menu4);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&list, val);
      break;

      case 2:
        remove = pop(&list);
        remove ? printf("%d Removed successfully!\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 3:
        showList(list);
      break;

      case 4:
        printf("Type a number: ");
        scanf("%d", &val);
        getchar();
        pushAtEnd(&list, val);
      break;

      case 5:
        pushAtMiddle(&list, val);
      break;

      case 6:
        pushAtSpecificPos(&list, val, key);
      break;

      case 7:
        remove = popAtEnd(&list);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
        free(remove);
      break;

      case 8:
        remove = popAtSpecificPos(&list, val);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 9:
        remove = popAll(&list);
        remove ? printf("List erased.\n\n") : printf("Nothing to remove.\n\n");
        free(remove);
      break;

      case 10:
        list = insertionSort(&list);
      break;

      case 11:
        list = listReverter(&list);
        list ? printf("Your list was reversed.\n\n") : printf("Not enough items.\n\n");
      break;

      case 12:
        swapper(&list, val, key);
      break;

      default:
        !choice ? printf("Wrong choice.") : printf("All good!");
    }
  }while(choice != 0);
  
  return 0;
}