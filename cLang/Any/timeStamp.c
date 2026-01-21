#include "../Main/practice.h"

int main() {
   struct timespec stop, start;

   clock_gettime(CLOCK_REALTIME, &start);

   //do some stuff...

   clock_gettime(CLOCK_REALTIME, &stop);
   printf("took: %lu us\n",
      ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_nsec - start.tv_nsec) / 1000
   );

   return 0;
}