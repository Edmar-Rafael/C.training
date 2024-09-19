#include <stdio.h>
#include <stdlib.h>

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

void showList(Node *headRef) {
  printf("\n-----------List-----------\n");
  printf("Nodes: %d\n", countNodes(headRef));

  while(headRef) {
    printf("%d -> ", headRef->data);
    headRef = headRef->next;
  }

  printf("\n-------End of list--------\n\n");
}

void push(Node **headRef, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    printf("Type a number: ");
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
    printf("Memory allocation error...!");
  }
}

void pushAtEnd(Node **headRef, int val) {
  Node *newNode = malloc(sizeof(newNode));

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
  }
}

Node* popAll(Node **headRef) {
  if(*headRef) {
    *headRef = NULL;
  } else {
    printf("Empty list.\n");
  }
}

int main() {
  char *menu1 = "0 - Exit\n1 - Insert at begin\n2 - Remove at begin\n3 - show\n4 - Insert at end\n";
  char *menu2 = "5 - Insert at middle\n6 - Remove at end\n7 - Remove specific\n8 - Clear list\n\n";
  int choice, val;
  Node *remove, *list = NULL;

  do {
    printf("%s%s", menu1, menu2);
    scanf("%d", &choice);
    getchar();

    switch(choice) {
      case 1:
        push(&list, val);
      break;

      case 2:
        remove = pop(&list);
        remove ? printf("%d Removed successfully!\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 3:
        showList(list);
      break;

      case 4:
        pushAtEnd(&list, val);
      break;

      case 5:
        pushAtMiddle(&list, val);
      break;

      case 6:
        remove = popAtEnd(&list);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Element does'nt exist.\n\n");
      break;

      case 7:
        remove = popAtSpecificPos(&list, val);
        remove ? printf("%d Removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
      break;

      case 8:
        remove = popAll(&list);
        remove ? printf("List erased.\n\n") : printf("Nothing to remove.\n\n");
      break;

      default:
        !choice ? printf("Wrong choice.") : printf("Good bye!!!");
    }
  }while(choice != 0);
  
  return 0;
}