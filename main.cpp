#include "objects.hpp"
#include "rng.hpp"
#include "screen.hpp"

#include <iostream>
#include <ncurses.h>
#include <random>
#include <unistd.h>

constexpr int delay = 50000;

int main(void) {
  auto scr = new Screen::Screen();
  if (!scr->enoughSize()) {
    delete scr;
    std::cerr << "O terminal precisa ter pelo menos 38x100!" << std::endl;
    return 1;
  }
  auto snake = new Objects::Snake(scr->width / 2, scr->height / 2);
  int key;
  pos dir = {1, 0};
  while ((key = getch()) != 'q') {
    clear();
    scr->drawBox();
    switch (key) {
    case KEY_LEFT:
      if (dir.x != 1) {
        dir.x = -1;
        dir.y = 0;
      }
      break;
    case KEY_RIGHT:
      if (dir.x != -1) {
        dir.x = 1;
        dir.y = 0;
      }
      break;
    case KEY_UP:
      if (dir.y != 1) {
        dir.x = 0;
        dir.y = -1;
      }
      break;
    case KEY_DOWN:
      if (dir.y != -1) {
        dir.x = 0;
        dir.y = 1;
      }
    }
    // TODO: um gameover de verdade
    if (!snake->move(dir))
      mvprintw(scr->height / 2, scr->width / 2 - 4, "Gameover");
    else
      snake->draw();
    refresh();
    usleep(delay);
  }
  delete scr;
  return 0;
}
