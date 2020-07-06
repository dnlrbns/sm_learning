#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

#define BKSP '\b'

enum states { HOME, ECHO, SLEEP };
enum states programState = HOME;


int startSession();
int endSession();


int main(void) {
  startSession();
  int c;
  while (c!='q') {
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
        
    //   printw("start echo case\n");

      addch(getch());

      break;
    }
    case SLEEP:

      break;

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

int endSession(){
    echo();
    endwin();
    return 0;
}