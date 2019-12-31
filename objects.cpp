#include "objects.hpp"

namespace Objects
{

Snake::Snake(int _x, int _y)
{
    for (auto i = 0; i <= 10; i++)
    {
        positions.push_back({_x - i, _y});
    }
}

Snake::~Snake()
{
}

pos *Snake::head()
{
    return &positions.front();
}

pos *Snake::tail()
{
    return &positions.back();
}

void Snake::move(int x_dir, int y_dir)
{
    auto new_head = *this->head();
    new_head.x += x_dir;
    new_head.y += y_dir;
    if (new_head.x >= 99)
    {
        new_head.x = 1;
    }
    else if (new_head.x < 0)
    {
        new_head.x = 98;
    }
    if (new_head.y >= 37)
    {
        new_head.y = 0;
    }
    else if (new_head.y <= 0)
    {
        new_head.y = 37;
    }
    positions.push_front(new_head);
    positions.pop_back();
}
} // namespace Objects