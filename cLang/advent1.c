#include <stdio.h>
#include <stdlib.h>
#include "practice.c"


int main() {
   char *buffer = stringBuffer("advent1.txt");
   int i = 0, j, k = 0, sum, lineIdx = 0;
   int arrLRDiffLen;
   int totalSum = 0;

   for(arrLRDiffLen = 0; buffer[arrLRDiffLen] != ' '; arrLRDiffLen++);

   int *l = (int *) malloc(sizeof(arrLRDiffLen));
   int *r = (int *) malloc(sizeof(arrLRDiffLen));
   int *diff = (int *) malloc(sizeof(arrLRDiffLen));

   while(buffer[i] != '\0') {
      printf("%4d:", lineIdx);
      for(j = 0; buffer[i] != ' '; j++, i++) {
         l[j] = (int) buffer[i];
      }

      for(i, j = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
         if(buffer[i] != ' ') {
            r[j] = (int) buffer[i];
            j++;
         }
      }

      quickSort(l, 0, arrLRDiffLen - 1);
      quickSort(r, 0, arrLRDiffLen - 1);

      for(j = 0; j < arrLRDiffLen; j++) {
         if(l[j] > r[j]) {
            diff[j] = l[j] - r[j];
         } else {
            diff[j] = r[j] - l[j];
         }
         printf("\tdiff:%d", diff[j]);
      }
      
      sum = 0;
      
      for(j = 0; j < arrLRDiffLen; j++) {
         sum += diff[j];
      }

      printf("\t\tsum:%d\n", sum);
      
      totalSum += sum;

      lineIdx++;
      i++;
   }

   printf("\n%d\n", totalSum);
   return 0;
}