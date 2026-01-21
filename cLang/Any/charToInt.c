#include "isNumbers.c"
#define ErrorMessage(str) (printf("\"%s\" doesnt match with digits!\n\n", str))

int charToInt(char *str) {
   if(isNumbers(str) || *str == '-') {
      int n = 0;
      int isNegative = 0;

      *str == '-' ? isNegative = 1 : '\0';

      for(int i = 0; i < stringLen(str); i++) {
         if(str[i] != '-') {
            n = n * 10 + (str[i] - '0');
         }
      }

      return isNegative ? -n : n;
   }

   ErrorMessage(str);

   return 0;
}