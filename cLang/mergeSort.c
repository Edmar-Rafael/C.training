#include <stdio.h>
#include <stdlib.h>
#include "practice.h"

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

Node* mergeSort(Node **headRef) {
  Node *head = *headRef;
  Node *a, *b;

  if(head == NULL || head->next == NULL) {
    return head;
  }

  splitMiddle(head, &a, &b);

  mergeSort(&a);
  mergeSort(&b);

  *headRef = sortedMerge(a, b);
  return *headRef;
}