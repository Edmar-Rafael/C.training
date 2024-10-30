#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
} Node;

int countNodes(Node *head) {
  int count = 0;

  while(head) {
    head = head->next;
    count++;
  }

  return count;
}

void swapper(Node **headRef, int key1, int key2) {
  Node *head = *headRef;

  if(head) {
    printf("Type the first node to swap: ");
    scanf("%d", &key1);
    printf("Type the second node to swap: ");
    scanf("%d", &key2);

    if(head->next == NULL || key1 == key2) {
      printf("Not enough elements.\n\n");
      return;
    }

    Node *currentKey1 = NULL;
    Node *currentKey2 = NULL;
    Node *aux;

    while(head) {
      if(head->data == key1) {
        currentKey1 = head;
      }

      if(head->data == key2) {
        currentKey2 = head;
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

    aux = currentKey2->previous;
    currentKey2->previous = currentKey1->previous;
    currentKey1->previous = aux;

    aux = currentKey2->next;
    currentKey2->next = currentKey1->next;
    currentKey1->next = aux;

    if(currentKey1->next) {
      currentKey1->next->previous = currentKey1;
    }
    if(currentKey2->next) {
      currentKey2->next->previous = currentKey2;
    }
  } else {
    printf("Empty list.\n\n");
  }
}

Node* insertionSort(Node *head) {
  if(head) {
    Node *sorted = NULL;
    Node *current = head;

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
}

Node* reverse(Node *head) {
  if(head == NULL) {
    return NULL;
  }

  Node *aux = head->previous;
  head->previous = head->next;
  head->next = aux;

  if(head->previous == NULL) {
    return head;
  }

  return reverse(head->previous);
}

void push(Node **headRef, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number to insert: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = *headRef;
    newNode->previous = NULL;

    if(*headRef) {
      Node *head = *headRef;
      head->previous = newNode;
    }

    *headRef = newNode;
  } else {
    printf("Memory allocation error!");
  }
}

void pushAtEnd(Node **headRef,int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);

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

      head->next = newNode;
      newNode->previous = head;
    }
  }
}

void pushAtMiddle(Node **headRef, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(*headRef == NULL) {
      *headRef = newNode;
    } else {
      Node *head = *headRef;
      int halfNodes = countNodes(head) / 2;

      while(halfNodes > 1) {
        head = head->next;
        halfNodes--;
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
    printf("Type a number to insert: ");
    scanf("%d", &val);
    if(nodes > 1) {
      printf("Type a number to insert after: ");
      scanf("%d", &key);
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

void showList(Node *head) {
  int nodes = countNodes(head);
  printf("\n----------------< List >------------------\n");
  printf("Nodes: %d\n\n", nodes);

  while(head) {
    if(head->previous) {
      printf("previous: %d\n", head->previous->data);
    }else {
      printf("previous: %p\n", head->previous);
    }

    printf("head: %d <-> ", head->data);

    if(head->next) {
      printf("\nnext: %d\n\n", head->next->data);
    } else {
      printf("\nnext: %p\n\n", head->next);
    }

    head = head->next;
  }

  printf("-------------< End of List >--------------\n\n");
}

Node* pop(Node **headRef) {
  if(*headRef) {
    Node *rm = *headRef;
    *headRef = rm->next;
    if(rm->next) {
      rm->next->previous = NULL;
    }

    return rm;
  }

  printf("Empty list.\n");
  return NULL;
}

Node* popAtEnd(Node **headRef) {
  if(*headRef) {
    Node *head = *headRef;
    Node *rm;

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

Node* popAtSpecificPos(Node **headRef, int val) {
  if(*headRef) {
    Node *head = *headRef;
    Node *rm;

    printf("Type a number to remove: ");
    scanf("%d", &val);

    if(head->data == val) {
      rm = *headRef;
      *headRef = rm->next;
      return rm;
    }

    while(head->next && head->data != val) {
      head = head->next;
    }

    if(head) {
      rm = head;
      head->previous->next = rm->next;
      rm->next->previous = head->previous;
      return rm;
    }
  } else {
    printf("Element does'nt exist.\n");
    return NULL;
  }
}

Node* popAll(Node **headRef) {
  if(*headRef) {
    Node *rm = *headRef;
    *headRef = NULL;
    return rm;
  }

  printf("Empty list.\n\n");
  return NULL;
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
        if(remove) {
          printf("List erased: ");
          showList(remove);
        }
        free(remove);
      break;

      case 10:
        list = insertionSort(list);
      break;

      case 11:
        list = reverse(list);
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