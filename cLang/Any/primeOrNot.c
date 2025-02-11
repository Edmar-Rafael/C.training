#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
  int i, j, arr[11];
  int length = sizeof(arr) / sizeof(arr[0]);
  int count;

  srand(time(NULL));
  
  for(i = 0; i < length; i++) {
    count = 0;
    arr[i] = rand() % 100;

    for(j = 2; j <= arr[i] / 2; j++) {
      if(arr[i] % j == 0) {
        count++;
      }
    }

    count == 0 || arr[i] == 1 ? printf("%d prime.\n", arr[i]) : printf("%d not prime.\n", arr[i]);
  }

  return 0;
}