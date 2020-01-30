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
  Snake(unsigned int _x, unsigned int _y);
  ~Snake();
  pos head();
  pos *tail();
  bool move(int xdir, int ydir);
  bool bodyCollision(pos &new_head);
  void draw();
};

} // namespace Objects