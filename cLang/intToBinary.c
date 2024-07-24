#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>
#include "practice.c"

void intToBinary(int n) {
  while(n) {
    if(n & 1) {
      printf("1");
    } else {
      printf("0");
    }

    n >>= 1;
  }

  printf("\n");
}

int main() {
  int a = 33;

  intToBinary(a);

  return 0;
}
 