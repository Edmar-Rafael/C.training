#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, j, matrix[4][5];
  int rows = sizeof(matrix) / sizeof(matrix[0]);
  int cols = sizeof(*matrix) / sizeof(matrix[0][0]);
  int length = sizeof(matrix) / sizeof(matrix[0][0]);

  srand(time(NULL));

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 5; j++) {
      matrix[i][j] = rand() % 2;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("rows: [%d]\ncols: [%d]\nlength: %d\n", rows, cols, length);

  return 0;
}