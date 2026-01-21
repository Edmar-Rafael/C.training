void set_bg_rgb(int r, int g, int b) {
   printf("\x1b[48;2;%d;%d;%dm", r, g, b);
}

void reset() {
   printf("\x1b[0m");
}