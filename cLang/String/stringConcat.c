#include <stdlib.h>

int stringLen(char *str) {
  int i = 0;

  while(str[i] != '\0') {
    i++;
  }

  return i;
}

char* stringConcat(char *s1, char *s2) {
  int i = 0;
  int j = 0;
  int s1Len = stringLen(s1);
  int s2Len = stringLen(s2);

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

  return res;
}