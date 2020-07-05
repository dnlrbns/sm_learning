#include <stdio.h>
#include <stdlib.h>

enum states { ON, OFF };
enum escapes {
  BELL = '\a',
  BACKSPACE = '\b',
  TAB = '\t',
  NEWLINE = '\n',
  VTAB = '\v',
  RETURN = '\r'
}

states programState = ON;

// int delayOff = 1000;
// int delayOn = 500;

int main(void) {
  while (1) {
    switch (programState) {
    case ON:
      delay(200);
      putchar(BACKSPACE) putchar('|');
      break;

    case OFF:
      delay(200);
      putchar(BACKSPACE) putchar('-');
      break;
    }
  }
}
