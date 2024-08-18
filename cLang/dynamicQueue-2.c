#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  struct Node *front;
  struct Node *rear;
  int length;
} Queue;

void createQueue(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
  queue->length = 0;
}

void enqueue(Queue *queue, int val) {
  Node *newNode = (struct Node *) malloc(sizeof(struct Node));
  
  if(newNode) {
    newNode->data = val;
    newNode->next = NULL;

    if(queue->front == NULL) {
      queue->front = newNode;
      queue->rear = newNode;
    } else {
      queue->rear->next = newNode;
      queue->rear = newNode;
    }

    queue->length++;
  } else {
    printf("Memory allocating error...!\n\n");
  } 
}

Node* dequeue(Queue *queue) {  
  if(queue->front) {
    Node *rm = queue->front;
    queue->front = rm->next;
    queue->length--;
    return rm;
  }

  printf("\nQueue empty.\n\n");
  return NULL;
}

void printQueue(Queue *queue) {
  Node *aux = queue->front;

  printf("\n-----Queue length: %d-----\n\n", queue->length);

  while(aux) {
    printf("%d\n", aux->data);
    aux = aux->next;
  }

  printf("\n-------End of Queue-------\n\n");
}

int main() {
  int choice, value;
  Node *remove;
  Queue queue;

  createQueue(&queue);

  do {
    printf(" 0 - Exit\n 1 - Insert\n 2 - Remove\n 3 - Print Queue\n");
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
        printQueue(&queue);
      break;

      default:
        choice != 0 ? printf("Invalid option!\n\n") : printf("Good bye!!!\n\n");
      break;
    }
  } while(choice !=0);

  return 0;
}