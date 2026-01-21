#include <stdio.h>

int main() {
   printStyles();
   int w = 40;
   int h = 20;

   for(int y = 0; y < h; y++) {
      for(int x = 0; x < w; x++) {
         int r = (x * 255) / (w - 1);
         int g = (y * 255) / (h - 1);
         int b = ((x + y) * 255) / (w + h - 2);
         printf("\x1b[48;2;%d;%d;%dmw", r, g, b);      
      }

      reset();
      putchar('\n');
   }

   reset();
   fflush(stdout);

   return 0;
}