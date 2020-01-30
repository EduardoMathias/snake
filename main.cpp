#include "objects.hpp"
#include "rng.hpp"
#include "screen.hpp"

#include <iostream>
#include <ncurses.h>
#include <random>
#include <unistd.h>

constexpr int delay = 80000;

int main(void) {
  auto rng = new Objects::RNG(99, 37);
  auto scr = new Screen::Screen();
  if (!scr->enoughSize()) {
    delete scr;
    std::cerr << "O terminal precisa ter pelo menos 38x100!" << std::endl;
    return 1;
  }
  auto snake = new Objects::Snake(scr->width / 2, scr->height / 2);
  int key;
  int y_dir = 0, x_dir = 1;
  auto food = rng->spawnFood();
  while ((key = getch()) != 'q') {
    clear();
    scr->drawBox();
    switch (key) {
    case KEY_LEFT:
      if (x_dir != 1) {
        x_dir = -1;
        y_dir = 0;
      }
      break;
    case KEY_RIGHT:
      if (x_dir != -1) {
        x_dir = 1;
        y_dir = 0;
      }
      break;
    case KEY_UP:
      if (y_dir != 1) {
        y_dir = -1;
        x_dir = 0;
      }
      break;
    case KEY_DOWN:
      if (y_dir != -1) {
        y_dir = 1;
        x_dir = 0;
      }
    }
    if (!snake->move(x_dir, y_dir))
      mvprintw(scr->height / 2, scr->width / 2 - 4, "Gameover");
    else
      snake->draw();
    mvprintw(food.y, food.x, "x");
    refresh();
    usleep(delay);
  }
  delete scr;
  return 0;
}