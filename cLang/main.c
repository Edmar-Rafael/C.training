#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
   char *file = "advent1.txt";
   char *buffer = stringBuffer(file);
   int length = stringLen(buffer) / 2;
   int i, leftIdx = 0, rightIdx = 0;

   for(i = 0; i < length; i++) {
      if(buffer[i] != ' ' && buffer[i] != '\n') {
         leftIdx++;
      }
   }
 
   int l[leftIdx];
   int r[leftIdx];
 
   for(i = 0; buffer[i] != '\0'; i++) {
      for(leftIdx = 0; buffer[i] != ' '; leftIdx++) {
         l[leftIdx] = (int) buffer[i];
         i++;
      }

      quickSort(l, 0, 4);

      for(leftIdx = 0; leftIdx < 5; leftIdx++) {
         printf("%c, ", l[leftIdx]);
      }
      
      printf("- ");
 
      while(buffer[i] != '\n' && buffer[i] != '\0') {
         if(buffer[i] != ' ') {
            r[rightIdx] = (int) buffer[i];
            rightIdx++;
         }
         i++;
      }

      quickSort(r, 0, 4);

      for(rightIdx = 0; rightIdx < 5; rightIdx++) {
         printf("%c, ", r[rightIdx]);
      }

      rightIdx = 0;

      printf("\n");
   }

   return 0;
}