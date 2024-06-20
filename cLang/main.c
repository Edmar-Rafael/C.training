#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *left, int *right);

int main() {
  int i, arr[15];
  int length = sizeof(arr) / sizeof(arr[0]);

  for(i = 0; i < length; i++) {
    arr[i] = rand() % 100;
    printf("%d, ", arr[i]);
  }
  printf("\n");

  quickSort(arr, 0, length - 1);

  for(i = 0; i < length; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}

void quickSort(int arr[], int left, int right) {
  if(left < right) {
    int pivotIndex = partition(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, right);
  }
}

int partition(int arr[], int left, int right) {
  srand(time(NULL));

  int pivotValue = left + (rand() % (right - left));

  if(pivotValue != right) {
    swap(&arr[pivotValue], &arr[right]);
  }

  int pivot = arr[right];

  int i = left;

  for(int j = left; j < right; j++) {
    if(arr[j] <= pivot) {
      swap(&arr[j], &arr[i]);
      i++;
    }
  }

  swap(&arr[i], &arr[right]);

  return i;
}

void swap(int *left, int *right) {
  int aux = *left;
  *left = *right;
  *right = aux;
}