#include <ctype.h>

int isNumbers(char *str) {
   for(int i = 0; str[i] != '\0'; i++) {
      if(!isdigit((unsigned char) str[i])) {
         return 0;
      }
   }

   return 1;
}