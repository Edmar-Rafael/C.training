#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "practice.c"


int main() {
   char *file = "advent1.txt";
   char *buffer = stringBuffer(file);
   int length = stringLen(buffer) / 2;
   int i, j, k = 0, leftIdx = 0, rightIdx = 0;
   int countLen = 0;

   for(i = 0; i < length; i++) {
      if(buffer[i] != ' ' && buffer[i] != '\n') {
         leftIdx++;
      }
   }

   for(i = 0; buffer[i] != '\0'; i++) {
      if(buffer[i] == '\n') {
         countLen++;
      }
   }
 
   int l[leftIdx];
   int r[leftIdx];
   int rest[5];
   int count[countLen];

   for(i = 0; buffer[i] != '\0'; i++) {
      for(leftIdx = 0; buffer[i] != ' '; leftIdx++) {
         l[leftIdx] = (int) buffer[i];
         i++;
      }
 
      while(buffer[i] != '\n' && buffer[i] != '\0') {
         if(buffer[i] != ' ') {
            r[rightIdx] = (int) buffer[i];
            rightIdx++;
         }
         i++;
      }

      quickSort(l, 0, leftIdx - 1);
      quickSort(r, 0, rightIdx - 1);

      for(j = 0; j < rightIdx; j++) {
         if(l[j] > r[j]) {
            rest[j] = l[j] - r[j];
         } else {
            rest[j] = r[j] - l[j];
         }
         printf("rest = %d, ", rest[j]);
      }

      int total = 0;

      for(j = 0; j < rightIdx; j++) {
         total += rest[j];
      }
      
      count[k] = total;
      printf("\t Total: %d\n", count[k]);
      k++;
      rightIdx = 0;
   }

   for(i = 0; i < 1000; i++) {
      leftIdx += count[i];
   }

   printf("%d\n", leftIdx);

   return 0;
}