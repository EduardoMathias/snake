#include "screen.hpp"

#include <curses.h>

namespace Screen {

Screen::Screen() {
  initscr();
  getmaxyx(stdscr, height, width);
  if (this->enoughSize())
    resize_term(38, 100);
  getmaxyx(stdscr, height, width);
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(FALSE);
  keypad(stdscr, TRUE);
}

Screen::~Screen() { endwin(); }

bool Screen::enoughSize() { return height >= 38 && width >= 100; }

void Screen::drawBox() { box(stdscr, 0, 0); }

} // namespace Screen