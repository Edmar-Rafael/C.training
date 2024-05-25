#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *left, int *right);

int main() {
  int el = 15;
  int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 62, 27, 90, 59}, i;
  int length = sizeof(arr) / sizeof(arr[0]);

  for(i = 0; i < length; i++) {;
    printf("%d, ", arr[i]);
  }
  printf("\n");

  quickSort(arr, 0, length - 1);

  for(int j = 0; j < length; j++) {
    printf("%d, ", arr[j]);
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
  int pivot = (arr[left] + arr[right] + arr[(left + right) / 2]) / 3;

  while(left < right) {
    while(left < right && arr[left] <= pivot) {
      left++;
    }

    while(left < right && arr[right] > pivot) {
      right--;
    }

    swap(&arr[left], &arr[right]);
  }
  return right;
}

void swap(int *left, int *right) {
  int aux = *left;
  *left = *right;
  *right = aux;
}