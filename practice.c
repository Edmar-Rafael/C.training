#include <stdio.h>

int main() {
  int v[] = {4,3,7,8,1,9,0};
  int length = sizeof(v) / sizeof(v[0]);
  int pivo = v[(0 + length - 1)];

  printf("pivot is: %d \n", pivo);

  return 0;
}