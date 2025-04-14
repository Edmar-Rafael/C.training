#include <stdio.h>


void stringMemset(char *str, char c, int n) {
   int i;
 
   for(i = 0; i < n; i++) {
     str[i] = c;
   }
 
   str[n] = '\0';
}
int stringLen(char *str) {
   int i = 0;
 
   while(str[i] != '\0') {
     i++;
   }
 
   return i;
}

void stringInverter(char *str) {
   int first = 0;
   int last = stringLen(str) - 1;
   char aux;
 
   while(first < last) {
     aux = str[first];
     str[first] = str[last];
     str[last] = aux;
 
     first++;
     last--;
   }
 
   printf("%s\n", str);
}

char* string(char *newString) {
  
   return newString;
}

char* stringConcat(char *s1, char *s2) {
   int s1Len, s2Len;
   int i = 0;
   int j = 0;
 
   for(s1Len = 0; s1[s1Len] != '\0'; s1Len++);
 
   for(s2Len = 0; s2[s2Len] != '\0'; s2Len++);
 
   char *res = (char *) calloc(s1Len + s2Len, sizeof(char));
 
   while(s1[i] != '\0') {
     res[i] = s1[i];
     i++;
   }
 
   j = i;
   i = 0;
 
   while(s2[i] != '\0') {
     res[j] = s2[i];
     i++;
     j++;
   }
 
   res[s1Len + s2Len] = '\0';
 
   return res;
}

void concat(char *s1, char *s2) {
   int s1Len, i;
 
   for(s1Len = 0; s1[s1Len] != '\0'; s1Len++);
 
   for(i = 0; s2[i] != '\0'; i++, s1Len++) {
     s1[s1Len] = s2[i];
   }
 
   s1[s1Len] = '\0';
}

void stringCopy(char *to, char *from) {
   int i = 0;
 
   while(from[i] != '\0') {
     to[i] = from[i];
     i++;
   }
 
   to[i] = '\0';
}

char* fileReader(char *fileName) {
   FILE *input = fopen(fileName, "rb");
   int size;
   char *buffer;

   if(!input) {
      perror("No input inserted.\n\n");
   }

   fseek(input, 0, SEEK_END);
   size = ftell(input);
   rewind(input);

   buffer = (char *) calloc(1, size + 1);
   if(!buffer) {
      fclose(input);
      fputs("Memory allocation fails", stderr);
   }

   if(buffer) {
      fread(buffer, 1, size, input);
   }

   fclose(input);

   return buffer;
}