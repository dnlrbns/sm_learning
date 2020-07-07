#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define BKSP '\b'

enum states
{
  HOME,
  ECHO,
  SLEEP
};
enum states programState = HOME;

int homeMachine();
int buildHomeMenu();
int echoMachine();
int sleepMachine();
int startSession();
int endSession();

int main(void)
{
  startSession();
  while (1)
  {
    switch (programState)
    {
    case HOME:
    {
      homeMachine();
      break;
    }
    case ECHO:
    {
      echoMachine();

      break;
    }
    case SLEEP:
    {
      sleepMachine();
      break;
    }
    default:
      break;
    }
  }
  endSession();
}

int homeMachine()
{
  buildHomeMenu();
  int c = 0;
  c = getch();
  if (c == 'E')
  {
    programState = ECHO;
  }
  else if (c == 'S')
  {
    programState = SLEEP;
  }
  else
  {
    // do nothing, dont care about any other c
  }
  return 0;
}

int buildHomeMenu()
{
  clear();
  refresh();
  printw("You are HOME\n");
  printw("E - goto ECHO mode\n");
  printw("S - goto SLEEP mode\n");
}

int echoMachine()
{ 
  int c = getch();
  if (c == 'H')
  {
    programState = HOME;
  }
  else
  {
    addch(c);
  }
}
int sleepMachine()
{
  clear();
  refresh();
  int c = getch();
  if (c == 'H')
  {
    programState = HOME;
  }
  else
  {
    // do nothing, dont care about any other c
  }
}

int startSession()
{
  initscr();
  noecho();
  return 0;
}

int endSession()
{
  echo();
  endwin();
  return 0;
}