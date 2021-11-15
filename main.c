#include <stdio.h>
#include <termios.h>

// TODO: dont do this every time
int _getch() {
  struct termios old;
  tcgetattr(0, &old);
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &old);
  int ch = getchar();
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  tcsetattr(0, TCSADRAIN, &old);
  return ch;
}


int main() {
  int ch;
  printf("\033[2J\033[0;0H");
  while ((ch = _getch()) != 4) {
    switch (ch) {
      case '\n':
        printf("\033[2J");
        break;
      default:
        putchar(ch);
        break;
    }
  }
  return 0;
}
