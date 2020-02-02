#pragma once
#include "rng.hpp"

#include <list>
#include <random>

namespace Objects {
class Snake {
private:
  RNG rng;
  void wallCollision(pos &new_head);
  pos food;

public:
  std::list<pos> positions;
  Snake(int _x, int _y);
  ~Snake();
  pos head();
  bool move(pos dir);
  bool bodyCollision(pos &new_head);
  void draw();
};

} // namespace Objects