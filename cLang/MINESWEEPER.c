#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Cell {
  int isBomb;
  int isOpen;
  int neighbors;
} Cell;

Cell field[10][10];
int row, col, length = 10;

void initializing() {
  for(row = 0; row < length; row++) {
    for(col = 0; col < length; col++) {
      field[row][col].isBomb = 0;
      field[row][col].isOpen = 0;
      field[row][col].neighbors = 0;
    }
  }
}

void drawBombs(int n) {
  srand(time(NULL));
  
  for(int i = 0; i <= n; i++) {
    row = rand() % length;
    col = rand() % length;
    field[row][col].isBomb = 1;
  }
}

int checkCoord(int r, int c) {
  if(r >= 0 && r < length && c >= 0 && c < length) {
    return 1; 
  }

  return 0;
}

int neighborsBombs(int r, int c) {
  int amount = 0;

  if(checkCoord(r - 1, c) && field[r - 1][c].isBomb) {
    amount++;
  }
  if(checkCoord(r + 1, c) && field[r + 1][c].isBomb) {
    amount++;
  }
  if(checkCoord(r, c - 1) && field[r][c - 1].isBomb) {
    amount++;
  }
  if(checkCoord(r, c + 1) && field[r][c + 1].isBomb) {
    amount++;
  }

  return amount;
}

void bombsCounter() {
  for(row = 0; row < length; row++) {
    for(col = 0; col < length; col++) {
      field[row][col].neighbors = neighborsBombs(row, col);
    }
  }
}

void renderField() {
  printf("\n\t\t\t\t\t! MINESWEEPER !\n\n");

  for(col = 0; col < length; col++) {
    printf("\t    %d", col);
  }
  printf("\n\n\t---------------------------------------------------------------------------------\n");

  for(row = 0; row < length; row++) {
    printf("   %d\t|", row);
    
    for(col = 0; col < length; col++) {
      if(field[row][col].isOpen){
        if(field[row][col].isBomb){
          printf("*");
        }
        printf("%d", field[row][col].neighbors);
      }
      printf(" ");
      printf("\t|");
    }
    printf("\n\t---------------------------------------------------------------------------------\n");
  }
}

void openTile(int r, int c) {
  int isCoordValid = checkCoord(r, c);

  if(isCoordValid == 1 && field[r][c].isOpen == 0) {
    field[r][c].isOpen = 1;

    if(field[r][c].neighbors == 0) {
      openTile(r - 1, c);
      openTile(r + 1, c);
      openTile(r, c - 1);
      openTile(r, c + 1);
    }
  }
}

int victory() {
  int amount = 0;

  for(row = 0; row < length; row) {
    for(col = 0; col < length; col++) {
      if(field[row][col].isOpen == 0 && field[row][col].isBomb == 0) {
        amount++;
      }
    }
  }

  return amount;
}

void play() {
  int selectedRow, selectedCol;

  do{
    renderField();

    do {
      printf("\nType the row and collumn coords: ");
      scanf("%d%d", &selectedRow, &selectedCol);;

      if(checkCoord(selectedRow, selectedCol) == 0) {
        printf("\nInvalid coords!");
      }
    } while(
      checkCoord(selectedRow, selectedCol) == 0 || field[selectedRow][selectedCol].isOpen == 1
    );

    openTile(selectedRow, selectedCol);
  }while(victory() != 0 && field[selectedRow][selectedCol].isBomb == 0);

  if(field[selectedRow][selectedCol].isBomb == 1) {
    printf("\n\t\tDerrota!!!\n");
  }
  printf("\n\t\tVITÓRIA!!!\n");

  renderField();
}