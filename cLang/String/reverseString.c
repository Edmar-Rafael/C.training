void stringInverter(char *str) {
  int first = 0;
  int last = stringlength(str) - 1;
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