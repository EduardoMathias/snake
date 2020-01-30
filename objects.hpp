#pragma once
#include <list>
#include <random>

struct pos {
  unsigned int x;
  unsigned int y;
};

namespace Objects {
class Snake {
private:
  void wallCollision(pos &new_head);

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