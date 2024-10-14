#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void enqueue(Node **queue, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(*queue == NULL) {
      *queue = newNode;
    } else {
      Node *aux = *queue;

      while(aux->next) {
        aux = aux->next;
      }

      aux->next = newNode;
    }
  }
}

void priorityEnqueue(Node **queue, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  Node *aux;

  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(*queue == NULL) {
      *queue = newNode;
    } else if(val > 59) {
      if((*queue)->data < 60) {
        newNode->next = *queue;
        *queue = newNode;
      } else {
        aux = *queue;

        while(aux->next && aux->next->data > 59) {
          aux = aux->next;
        }

        newNode->next = aux->next;
        aux->next = newNode;
      }
    } else {
      aux = *queue;

      while(aux->next) {
        aux = aux->next;
      }

      aux->next = newNode;
    }
  } else {
    printf("Memory allocation error...!");
  }
}

Node* dequeue(Node **queue) {
  if(*queue) {
    Node *rm = *queue;
    *queue = rm->next;
    return rm;
  }

  printf("\nEmpty queue!\n\n");
  return NULL;
}

void printQueue(Node *queue) {
  printf("\n------------Queue------------\n\n");

  while(queue) {
    printf("%d - ", queue->data);
    queue = queue->next;
  }

  printf("\n---------End of Queue---------\n\n");
}

int main() {
  int choice, value;
  Node *remove, *queue = NULL;

  do {
    printf(" 0 - Exit\n 1 - Insert\n 2 - Remove\n 3 - Print Queue\n 4 - Priority Insertion\n");
    scanf("%d", &choice);
    getchar;

    switch(choice) {
      case 1:
        printf("Type a value: ");
        scanf("%d", &value);
        enqueue(&queue, value);
      break;

      case 2:
        remove = dequeue(&queue);
        remove ? printf("\n%d removed!\n\n", remove->data) : printf(" ");
        free(remove);
      break;

      case 3:
        printQueue(queue);
      break;

      case 4:
        printf("Type a value: ");
        scanf("%d", &value);
        priorityEnqueue(&queue, value);
      break;

      default:
        choice != 0 ? printf("Invalid option!\n\n") : printf("Good bye!!!\n\n");
      break;
    }
  } while(choice !=0);

  return 0;
}