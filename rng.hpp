#pragma once

#include <random>
struct pos {
  unsigned int x;
  unsigned int y;
  bool operator==(pos a);
};

namespace Objects {
class RNG {
private:
  std::random_device dev;
  std::mt19937 rng;
  std::uniform_int_distribution<std::mt19937::result_type> dist_x;
  std::uniform_int_distribution<std::mt19937::result_type> dist_y;

public:
  RNG(int max_x, int max_y);
  ~RNG();
  pos spawnFood();
};

} // namespace Objects