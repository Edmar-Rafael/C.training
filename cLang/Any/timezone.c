#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>


int main() {
  time_t currentTime = time(NULL);
  printf("%ld\n", currentTime);
  struct tm date = *gmtime(&currentTime);
  printf("date: %d/%02d/%d\n", date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
  printf("o'clock: %d:%d\n", date.tm_hour, date.tm_min);
  printf("Timezone is %s\n", date.tm_zone);

  return 0;
}