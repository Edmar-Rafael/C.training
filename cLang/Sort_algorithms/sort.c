#include <stdio.h>
#include <stdlib.h>
#include "../Main/practice.h"

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


void splitMiddle(Node *source, Node **frontRef, Node **backRef) {
   Node *slow = source;
   Node *fast = source->next;

   while(fast) {
      fast = fast->next;

      if(fast) {
         slow = slow->next;
         fast = fast->next;
      }
   }

   *frontRef = source;
   *backRef = slow->next;
   slow->next = NULL;
}

Node* sortedMerge(Node *a, Node *b) {
   Node *result = NULL;

   if(a == NULL) {
      return b;
   } else if(b == NULL) {
      return a;
   }

   if(a->data <= b->data) {
      result = a;
      result->next = sortedMerge(a->next, b);
   } else {
      result = b;
      result->next = sortedMerge(a, b->next);
   }

   return result;
}

Node* linkedList_mergeSort(Node **headRef) {
   Node *head = *headRef;
   Node *a, *b;

   if(head == NULL || head->next == NULL) {
      return head;
   }

   splitMiddle(head, &a, &b);

   linkedList_mergeSort(&a);
   linkedList_mergeSort(&b);

   *headRef = sortedMerge(a, b);
   return *headRef;
}


void merge(int arr[], int left, int mid, int right) {
   int i, j, k;
   int n1 = mid - left + 1;
   int n2 = right - mid;

   int leftArr[n1], rightArr[n2];

   for(i = 0; i < n1; i++) {
      leftArr[i] = arr[left + i];
   }

   for(j = 0; j < n2; j++) {
      rightArr[j] = arr[mid + 1 + j];
   }

   i=0;
   j=0;
   k= left;

   while(i < n1 && j < n2) {
      if(leftArr[i] <= rightArr[j]) {
         arr[k] = leftArr[i];
         i++;
      } else {
         arr[k] = rightArr[j];
         j++;
      }

      k++;
   }

   while(i < n1) {
      arr[k] = leftArr[i];
      i++;
      k++;
   }

   while(j < n2) {
      arr[k] = rightArr[j];
      j++;
      k++;
   }
}

void mergeSort(int arr[], int left, int right) {
   if(left < right) {
      int mid = left + (right - left) / 2;

      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      merge(arr, left, mid, right);
   }
}