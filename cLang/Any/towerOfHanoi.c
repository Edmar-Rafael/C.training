#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
  if(n == 1) {
    printf("Move %d from %c to %c \n", n, source, target);
    return;
  }
  towerOfHanoi(n - 1, source, target, auxiliary);
  printf("Move %d from %c to %c \n", n, source, target);
  towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
  int numDisks = 5;
  /* char source = 'A';
  char auxiliary = 'B';
  char target = 'C'; */

  towerOfHanoi(numDisks, 'A', 'B', 'C');

  return 0;
}