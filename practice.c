#include <stdio.h>

int recursiveBinarySearch(int vet[], int key, int start, int end) {
  int half;

  if(start <= end) {
    half = (start + end) / 2;

    if(key == vet[half]) {
      return half;
    } else {
      if(key < vet[half]) {
        return recursiveBinarySearch(vet, key, start, half - 1);
      } else {
        return recursiveBinarySearch(vet, key, half + 1, end);
      }
    }
  }

  return -1;
}

int main() {
  int vet[] = {13,14,19,43,47,52,65,82,89,91};
  int length = sizeof(vet) / sizeof(vet[0]);
  int valor, op;

  do{
    printf("Type a valor to search: ");
    scanf("%d", &valor);
    printf("\nFind at index: %d \n", recursiveBinarySearch(vet, valor, 0, length - 1));

    printf("\nType 0 to- exit \nType 1 to- New Search \n");
    scanf("%d", &op);
  } while (op != 0);

  return 0;
}