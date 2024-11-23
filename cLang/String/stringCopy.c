void stringCopy(char *to, char *from) {
  int i = 0;

  while(from[i] != '\0') {
    to[i] = from[i];
    i++;
  }

  to[i] = '\0';
}