#include <stdio.h>
#include <stdlib.h>
#include "practice.h"

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