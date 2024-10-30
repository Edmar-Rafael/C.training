#include <stdio.h>

void handleIndex(int arr[], int length);
int recursiveBinarySearch(int arr[], int key, int start, int end);

int main() {
  int arr[] = {13,14,19,43,47,52,65,82,89,91};
  int length = sizeof(arr) / sizeof(arr[0]);

  handleIndex(arr, length);

  return 0;
}

void handleIndex(int arr[], int length) {
  int valor, op;

  do{
    printf("Type a valor to search: ");
    scanf("%d", &valor);
    int result = recursiveBinarySearch(arr, valor, 0, length - 1);

    if(result != -1) {
      printf("\nValor found at index: %d \n\n", result);
      printf("\n");
    } else {
      printf("\nValor doesnt exist. \n");
      printf("\n");
    }

    printf("Type 1 to New Search \nType any key to exit: ");
    scanf("%d", &op);
    printf("\n");
  } while (op == 1);
}

int recursiveBinarySearch(int arr[], int key, int start, int end) {
  if(start <= end) {
    int half = (start + end) / 2;

    if(key == arr[half]) {
      return half;
    } else if(key < arr[half]) {
      return recursiveBinarySearch(arr, key, start, half - 1);
    } else {
      return recursiveBinarySearch(arr, key, half + 1, end);
    }
  }

  return -1;
}