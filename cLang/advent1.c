#include <stdio.h>
#include <stdlib.h>
#include "practice.c"


int main() {
   char *file = stringBuffer("advent1.txt");
   int i = 0, j, k = 0, sum, lineIdx = 0;
   int arrLRDiffLen;
   int totalSum = 0;

   for(arrLRDiffLen = 0; file[arrLRDiffLen] != ' '; arrLRDiffLen++);

   int *l = (int *) malloc(sizeof(arrLRDiffLen));
   int *r = (int *) malloc(sizeof(arrLRDiffLen));
   int *diff = (int *) malloc(sizeof(arrLRDiffLen));

   while(file[i] != '\0') {
      printf("%4d:", lineIdx);
      for(j = 0; file[i] != ' '; j++, i++) {
         l[j] = (int) file[i];
      }

      for(i, j = 0; file[i] != '\n' && file[i] != '\0'; i++) {
         if(file[i] != ' ') {
            r[j] = (int) file[i];
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