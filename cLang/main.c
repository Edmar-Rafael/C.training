#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


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