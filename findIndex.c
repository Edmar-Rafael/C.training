#include <stdio.h>

int linearSearch(int arr[], int length, int target);
void findIndex(int res, int target);

int main() {
  int arr[] = {5,2,8,12,3,1};
  int length = sizeof(arr) / sizeof(arr[0]);
  int target = 12;
  
  int result = linearSearch(arr, length, target);

  findIndex(result, target);

  return 0;
}

int linearSearch(int arr[], int length, int target) {
  for(int i = 0; i < length; i++) {
    if(arr[i] == target) {
      return i;
    }
  }
  
  return -1;
}

void findIndex(int res, int target) {
  if(res != -1) {
    printf("valor %d found at index: %d\n",target, res);
  } else {
    printf("valor %d doesnt exist\n", target);
  }
}