#include "rng.hpp"

bool pos::operator==(pos a) { return a.x == x && a.y == y; }
pos &pos::operator+=(pos &a) {
  x += a.x;
  y += a.y;
  return *this;
}

namespace Objects {

RNG::RNG(int max_x, int max_y)
    : rng(dev()), dist_x(1, max_x), dist_y(1, max_y) {}

RNG::~RNG() {}

pos RNG::spawnFood() { return {(int)dist_x(rng), (int)dist_y(rng)}; }
} // namespace Objects