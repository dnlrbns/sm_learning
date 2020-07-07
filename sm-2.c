#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

// watch this and implement menu for states
// https://www.youtube.com/watch?v=3YiPdibiQHA

#define BKSP '\b'

enum states { HOME, ECHO, SLEEP };
enum states programState = HOME;

int startSession();
int endSession();

int main(void) {
  startSession();
  int c;
  while (c != 'q') {
    switch (programState) {
    case HOME: {
      //   printw("start home case\n");
      c = getch();
      if (c == 'E') {
        programState = ECHO;
      } else if (c == 'S') {
        programState = SLEEP;
      } else {
        //   putchar('BKSP');
      }
      break;
    }
    case ECHO: {

      int echo_char = getch();

      if (echo_char == 'H') {
        programState = HOME;
      } else {
        addch(echo_char);
      }
      break;
    }
    case SLEEP: {
      int echo_char = getch();
      if (echo_char == 'H') {
        programState = HOME;
      } else {
        // do nothing, dont care about any other echo_char
      }
      break;
    }
    default:
      // do nothing. why are we here anyway
      break;
    }
  }
  endSession();
}

int startSession() {
  initscr();
  noecho();
  return 0;
}

int endSession() {
  echo();
  endwin();
  return 0;
}