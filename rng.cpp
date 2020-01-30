#include "rng.hpp"

namespace Objects {

RNG::RNG(int max_x, int max_y)
    : rng(dev()), dist_x(1, max_x), dist_y(1, max_y) {}

RNG::~RNG() {}

pos RNG::spawnFood() {
  return {(unsigned int)dist_x(rng), (unsigned int)dist_y(rng)};
}
} // namespace Objects