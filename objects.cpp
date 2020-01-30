#include "objects.hpp"
#include <curses.h>
#include <random>

namespace Objects {

Snake::Snake(unsigned int _x, unsigned int _y) : rng(98, 36) {
  for (auto i = 0; i < 5; i++) {
    positions.push_back({_x - i, _y});
  }
  food = rng.spawnFood();
}

Snake::~Snake() {}

pos Snake::head() { return positions.front(); }

bool Snake::move(int x_dir, int y_dir) {
  auto new_head = head();
  new_head.x += x_dir;
  new_head.y += y_dir;
  wallCollision(new_head);
  if (bodyCollision(new_head))
    return false;
  positions.push_front(new_head);
  if (new_head == food)
    food = rng.spawnFood();
  else
    positions.pop_back();
  return true;
}

void Snake::wallCollision(pos &new_head) {
  if (new_head.x >= 99) {
    new_head.x = 1;
  } else if (new_head.x <= 0) {
    new_head.x = 98;
  }
  if (new_head.y >= 37) {
    new_head.y = 0;
  } else if (new_head.y <= 0) {
    new_head.y = 37;
  }
}

bool Snake::bodyCollision(pos &new_head) {
  for (auto &part : positions) {
    if (new_head == part) {
      return true;
    }
  }
  return false;
}

void Snake::draw() {
  for (auto &part : positions) {
    mvprintw(part.y, part.x, "o");
  }
  mvprintw(head().y, head().x, "@");
  mvprintw(food.y, food.x, "x");
}

} // namespace Objects
